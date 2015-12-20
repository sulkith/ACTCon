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
                    teensy.Write("A0E");
                return;
            }
            Single[] ts = acd.gettyreslip();
            float sumf = ts[0] + ts[1];
            float sumr = ts[2] + ts[3];
            if (teensy.IsOpen)
            {
                if ((sumr >= 2 * offset) || (sumf >= 2 * offset))
                    teensy.Write("A100E");
                else
                    teensy.Write("A0E");

                int rpm = (int)acd.getrpm();
                teensy.Write("R" + rpm.ToString() + "r");
            }
        }

        public bool isOpen()
        {
            return connected;
        }
    }
}
