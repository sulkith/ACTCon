/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2015 Michael Drost
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
using System;
using System.Drawing;
using System.Net;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using System.Threading;

namespace AC_Teensy_Connector
{
    public partial class Form1 : Form
    {
        [DllImport("user32.dll", CharSet = CharSet.Unicode)]
        static extern uint SendMessage(IntPtr hWnd, uint Msg, uint wParam, uint lParam);
        TeensyConnector TC;
        AC_Connector AC;
        Thread workerThread;
        private bool threadRunning;
        private int threadCounter;

        public Form1()
        {
            InitializeComponent();
            TC = new TeensyConnector();
            AC = new AC_Connector();
            //Throttle.Value = 75;
            refreshGUI(null);
            rpm2.Location = rpm1.Location;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            TC.setPort(TeensyPort.Text);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            TC.setFFOffset(Int32.Parse(TeensyFFOffs.Text));
            if (Teensy_AutoConnect.Checked)
            {
                String Port = TC.autoConnect();
                if (Port.Equals(""))
                {
                    TeensyState.Text = "AutoConnect Failed";
                    TeensyState.BackColor = Color.Red;
                }
                else
                {
                    TeensyPort.Text = Port;
                    TeensyState.Text = "Connected to " + Port;
                    TeensyState.BackColor = Color.Green;
                }
            }
            else
            { 
                if (TC.connect())
                {
                    TeensyState.Text = "Connected to " + TeensyPort.Text;
                    TeensyState.BackColor = Color.Green;
                }
                else
                {
                    TeensyState.Text = "Connection Failed for " + TeensyPort.Text;
                    TeensyState.BackColor = Color.Red;
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            TC.disconnect();
            TeensyState.Text = "Disconnected";
            TeensyState.BackColor = Color.Red;
        }

        private void Teensy_AutoConnect_CheckedChanged(object sender, EventArgs e)
        {
            if (Teensy_AutoConnect.Checked)
            {
                TeensyPort.Enabled = false;
            }
            else
            {
                TeensyPort.Enabled = true;
            }
        }

        private void AC_Connect_Click(object sender, EventArgs e)
        {
            String[] sa = ServerIP.Text.Split('.');
            if (sa.Length != 4)
            {
                ACState.Text = "malformed IP Address";
                ACState.BackColor = Color.Red;
                ReceiveAC.Enabled = false;
                return;
            }
            byte[] ba = { 0, 0, 0, 0 };
            try
            {
                for (int i = 0; i < 4; ++i)
                {
                    ba[i] = byte.Parse(sa[i]);
                }
                IPAddress IPAddr = new IPAddress(ba);
                AC.setIP(IPAddr);
            }
            catch
            {
                ACState.Text = "malformed IP Address";
                ACState.BackColor = Color.Red;
                ReceiveAC.Enabled = false;
                return;
            }
            AC.connect();
            checkACConnection.Enabled = true;
        }

        private void RefreshGui_Tick(object sender, EventArgs e)
        {
            ACDataInterpreter acd = AC.getData();
            TC.receiveData(acd);
            refreshGUI(acd);
        }
        String PrintArray(float[] arr)
        {
            String s = "{" + arr[0];
            for (int i = 1; i < arr.Length; ++i)
            {
                s += ", " + arr[i];
            }
            s += "}";
            return s;
        }
        void refreshGUI(ACDataInterpreter acd)
        {
            int offset = Int32.Parse(TeensyFFOffs.Text);
            AdditionalInfo.Text = "";
            AdditionalInfo.Text += "RC: " + AC.receiveCounter.ToString() + Environment.NewLine;
            AdditionalInfo.Text += "RQ: " + AC.requestCounter.ToString() + Environment.NewLine;
            AdditionalInfo.Text += "TR: " + threadRunning.ToString() + Environment.NewLine;
            AdditionalInfo.Text += "TC: " + threadCounter.ToString() + Environment.NewLine;
            
            if (acd == null)
            {

                WheelVL.BackColor = Color.Black;
                WheelVR.BackColor = Color.Black;
                WheelHL.BackColor = Color.Black;
                WheelHR.BackColor = Color.Black;
                Throttle.Value = 0;
                Brake.Value = 0;
                Track.Text = "";
                Driver.Text = "";
                CAR.Text = "";
                Steering.Text = "0°";
                int W = Steering.Size.Width / 2-SteerMark.Size.Width/2;
                Point p = new Point(Steering.Location.X, Steering.Location.Y);
                p.X += W;
                SteerMark.Location = p;
                float rpm = 0;
                Size s1 = rpm1.Size;
                Size s2 = rpm2.Size;
                s2.Width = (int)(s1.Width * rpm / float.Parse(maxRPM.Text));
                rpm2.Size = s2;
                Gear.Text = "";
                TControl.BackColor = Color.Red;
                ABS.BackColor = Color.Red;
                //rpm1.Size.Width * rpm / float.Parse(maxRPM.Text);
                
            }
            else
            {
                AdditionalInfo.Text += "Dy: " + PrintArray(acd.getdy()) + Environment.NewLine;
                AdditionalInfo.Text += "Mz: " + PrintArray(acd.getmz()) + Environment.NewLine;
                AdditionalInfo.Text += "Load: " + PrintArray(acd.getload()) + Environment.NewLine;
                AdditionalInfo.Text += "DirtyLevel: " + PrintArray(acd.gettyreDirtyLevel()) + Environment.NewLine;
                AdditionalInfo.Text += "ndSlip: " + PrintArray(acd.getndslip()) + Environment.NewLine;
                AdditionalInfo.Text += "currentlaptime: " + acd.getcurrlapTime() + Environment.NewLine;
                AdditionalInfo.Text += "lastlaptime: " + acd.getlastlapTime() + Environment.NewLine;
                Single[] ts = acd.gettyreslip();
                WheelVL.BackColor = (ts[0] >= offset) ? Color.Red : Color.Black;
                WheelVR.BackColor = (ts[1] >= offset) ? Color.Red : Color.Black;
                WheelHL.BackColor = (ts[2] >= offset) ? Color.Red : Color.Black;
                WheelHR.BackColor = (ts[3] >= offset) ? Color.Red : Color.Black;
                Throttle.Value = (int)(acd.getped() * 100);
                Brake.Value = (int)(acd.getbrk() * 100);
                Track.Text = AC.getTrack();
                Driver.Text = AC.getDriver();
                CAR.Text = AC.getCar();
                float steer = acd.getsteer();
                Steering.Text = steer.ToString() + "°";
                int maxval = Steering.Size.Width - SteerMark.Size.Width;
                Point p = new Point(Steering.Location.X, Steering.Location.Y);
                maxval = (int)(maxval * 1.0 * (steer + 450)/900);
                p.X += maxval;
                SteerMark.Location = p;
                float rpm = acd.getrpm();
                float maxrpm = float.Parse(maxRPM.Text);
                Size s1 = rpm1.Size;
                Size s2 = rpm2.Size;
                //rpm1.Text = rpm2.Text = ((int)rpm).ToString() + " rpm";
                s2.Width = (int)(s1.Width * rpm / maxrpm);
                rpm2.Size = s2;
                if ((int)rpm > maxrpm)
                    maxRPM.Text = ((int)rpm).ToString();
                if (rpm >= maxrpm * 0.85)
                {
                    rpm2.BackColor = Color.Red;
                }
                else
                {
                    rpm2.BackColor = Color.Orange;
                }
                int gear = acd.getgear();
                if (gear == 0)
                    Gear.Text = "R";
                else if (gear == 1)
                    Gear.Text = "N";
                else
                    Gear.Text = (gear - 1).ToString();

                if (acd.getABSEna())
                    ABS.BackColor = Color.Green;
                else
                    ABS.BackColor = Color.Red;
                if (acd.getABSAct()) ABS.BackColor = Color.Yellow;
                if (acd.getTCEna())
                    TControl.BackColor = Color.Green;
                else
                    TControl.BackColor = Color.Red;
                if (acd.getTCAct()) TControl.BackColor = Color.Yellow;

            }
        }


        private void textBox1_TextChanged_1(object sender, EventArgs e)
        {
            TC.setFFOffset(Int32.Parse(TeensyFFOffs.Text));
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void AC_Disconnect_Click(object sender, EventArgs e)
        {
            ReceiveAC.Enabled = false;
            threadRunning = false;
            AC.disconnect();
            if(workerThread != null)
                workerThread.Join();
            ACState.Text = "Disconnected";
            ACState.BackColor = Color.Red;
            refreshGUI(null);
        }

        private void label10_Click(object sender, EventArgs e)
        {

        }

        private void TControl_Click(object sender, EventArgs e)
        {

        }
        private void threadFunction()
        {
            threadRunning = true;
            while (threadRunning == true)
            {
                threadCounter++;
                try
                {
                    
                    AC.receiveSyncronously();
                }
                catch
                { }
            }
        }
        private void checkACConnection_Tick(object sender, EventArgs e)
        {
            checkACConnection.Enabled = false;
            if (AC.gethandshakeFinished())
            {
                ACState.Text = "Connected";
                ACState.BackColor = Color.Green;
                ReceiveAC.Enabled = true;
                //TODO Start Thread
                threadRunning = true;
                workerThread = new Thread(threadFunction);
                workerThread.Start();
            }
            else
            {
                threadRunning = false;
                //workerThread.Join();
                //workerThread.Suspend();
                ACState.Text = "Connection failed";
                ACState.BackColor = Color.Red;
                ReceiveAC.Enabled = false;
                AC.disconnect();
            }
        }

        private void AutoConnectTimer_Tick(object sender, EventArgs e)
        {
            if (Teensy_AutoConnect.Checked && !TC.isOpen())
            {
                String Port = TC.autoConnect();
                if (Port.Equals(""))
                {
                    TeensyState.Text = "AutoConnect Failed";
                    TeensyState.BackColor = Color.Red;
                }
                else
                {
                    TeensyPort.Text = Port;
                    TeensyState.Text = "Connected to " + Port;
                    TeensyState.BackColor = Color.Green;
                }
            }
            if (ACautoConnect.Checked && !AC.gethandshakeFinished())
            {
                AC_Connect_Click(null, null);
            }

        }

        private void ReceiveAC_Tick(object sender, EventArgs e)
        {
            //ReceiveAC.Enabled = false;
            //AC.receive5ms(); //Trigger refresh
            //ReceiveAC.Enabled = true;
            //RefreshGui.Enabled = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        { 
        }
    }
}
