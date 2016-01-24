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
using System.IO.Ports;

namespace AC_Teensy_Connector
{
    class TeensyConnector
    {
        private SerialPort teensy;
        private int offset;
        bool connected = false;

        public TeensyConnector()
        {
            teensy = new SerialPort();
            teensy.BaudRate = 9600;
            teensy.PortName = "COM4";
            //teensy.WriteBufferSize = 16;
            teensy.WriteTimeout = 30;
            offset = 2500;
        }
        ~TeensyConnector()
        {
            teensy.Close();
        }
        public void setPort(String s)
        {
            disconnect();
            teensy.PortName = s;
        }
        public String autoConnect()
        {
            setPort("COM1");
            if(connect())return teensy.PortName;
            setPort("COM2");
            if (connect()) return teensy.PortName;
            setPort("COM3");
            if (connect()) return teensy.PortName;
            setPort("COM4");
            if (connect()) return teensy.PortName;
            setPort("COM5");
            if (connect()) return teensy.PortName;
            setPort("COM6");
            if (connect()) return teensy.PortName;
            setPort("COM7");
            if (connect()) return teensy.PortName;
            setPort("COM8");
            if (connect()) return teensy.PortName;
            setPort("COM9");
            if (connect()) return teensy.PortName;
            setPort("COM10");
            if (connect()) return teensy.PortName;
            return "";
        }
        public bool connect()
        {
            try
            {
                teensy.Open();
                connected = true;
            }
            catch
            {
                connected = false;
                return false;
            }

            return true;
        }
        public void disconnect()
        {
            teensy.Close();
            connected = false;
        }
        public void setFFOffset(int off)
        {
            offset = off;
        }

        internal void receiveData(ACDataInterpreter acd)
        {
            if (acd == null)
            {
                if (teensy.IsOpen)
                {
                    
                    try
                    {
                        //teensy.Write("AA000E");
                        teensy.Write("AA000EAR00000EAGNE");
                        int v = 0;
                        byte[] tempv = { (byte)'A', (byte)'V', 0, 0, (byte)'E' };
                        if (v > 255)
                        {
                            tempv[3] = (byte)(v / 256);//higher
                            v %= 256;
                        }
                        tempv[2] = (byte)v;
                        teensy.Write(tempv, 0, 5);
                        byte[] tempf = { (byte)'A', (byte)'F', 0, (byte)'E' };
                        teensy.Write(tempf, 0, 4);

                        byte[] currLapTime = BitConverter.GetBytes((Int32)0);
                        byte[] tempc = { (byte)'A', (byte)'C', 0, 0, 0, 0, (byte)'E' };
                        tempc[2] = currLapTime[0];
                        tempc[3] = currLapTime[1];
                        tempc[4] = currLapTime[2];
                        tempc[5] = currLapTime[3];
                        teensy.Write(tempc, 0, 7);
                        byte[] lastLapTime = BitConverter.GetBytes((Int32)0);
                        byte[] templ = { (byte)'A', (byte)'L', 0, 0, 0, 0, (byte)'E' };
                        templ[2] = lastLapTime[0];
                        templ[3] = lastLapTime[1];
                        templ[4] = lastLapTime[2];
                        templ[5] = lastLapTime[3];
                        teensy.Write(templ, 0, 7);
                    }
                    catch
                    { }
                }
                return;
            }
            Single[] ts = acd.gettyreslip();
            float sumf = ts[0] + ts[1];
            float sumr = ts[2] + ts[3];
            if (teensy.IsOpen)
            {

                try
                {
                    //FFB
                    if ((sumr >= 2 * offset) || (sumf >= 2 * offset))
                        teensy.Write("AA100E");
                    else
                        teensy.Write("AA000E");

                    //RPM
                    int rpm = (int)acd.getrpm();
                    teensy.Write("AR" + rpm.ToString("D5") + "E");

                    //V
                    int v = (int)acd.getKMH();
                    byte[] tempv = { (byte)'A', (byte)'V', 0, 0, (byte)'E' };
                    if (v > 255)
                    {
                        tempv[3] = (byte)(v / 256);//higher
                        v %= 256;
                    }
                    tempv[2] = (byte)v;
                    teensy.Write(tempv, 0, 5);

                    //GEAR
                    int gear = acd.getgear();
                    if (gear == 0)
                        teensy.Write("AGRE");
                    else if (gear == 1)
                        teensy.Write("AGNE");
                    else
                        teensy.Write("AG" + (gear - 1).ToString() + "E");

                    //ABS + TC
                    byte[] tempf = { (byte)'A', (byte)'F', 0, (byte)'E' };
                    if (acd.getABSEna())
                    {
                        tempf[2] += 0x1;
                        if (acd.getABSAct()) tempf[2] += 0x2;
                    }
                    if (acd.getTCEna())
                    {
                        tempf[2] += 0x10;
                        if (acd.getTCAct()) tempf[2] += 0x20;
                    }
                    teensy.Write(tempf, 0, 4);

                    //LAPTimes
                    byte[] currLapTime = BitConverter.GetBytes(acd.getcurrlapTime());
                    byte[] tempc = { (byte)'A', (byte)'C', 0,0,0,0, (byte)'E' };
                    tempc[2] = currLapTime[0];
                    tempc[3] = currLapTime[1];
                    tempc[4] = currLapTime[2];
                    tempc[5] = currLapTime[3];
                    teensy.Write(tempc, 0, 7);

                    byte[] lastLapTime = BitConverter.GetBytes(acd.getlastlapTime());
                    byte[] templ = { (byte)'A', (byte)'L', 0, 0, 0, 0, (byte)'E' };
                    templ[2] = lastLapTime[0];
                    templ[3] = lastLapTime[1];
                    templ[4] = lastLapTime[2];
                    templ[5] = lastLapTime[3];
                    teensy.Write(templ, 0, 7);

                }
                catch
                { }

            }
        }

        public bool isOpen()
        {
            return connected;
        }
    }
}
