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
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace AC_Teensy_Connector
{
    class AC_Connector
    {
        byte[] handshake = { 0, 0, 0, 0,
                          0, 0, 0, 0,
                          0, 0, 0, 0};
        byte[] subscribe = { 0, 0, 0, 0,
                          0, 0, 0, 0,
                          1, 0, 0, 0};
        byte[] dismiss = { 0, 0, 0, 0,
                          0, 0, 0, 0,
                          3, 0, 0, 0};
        UdpClient uc;
        IPAddress IP;
        IAsyncResult ar;
        AsyncCallback ac;
        ACDataInterpreter acd;
        String VehName;
        String DriverName;
        String TrackName;
        public int receiveCounter = 0;
        public int requestCounter = 0;
        bool HandshakeFinished = false;
        public AC_Connector(IPAddress ip)
        {
            IP = ip;
            uc = new UdpClient();
            acd = null;
        }
        public string getTrack()
        {
            return TrackName;
        }
        public string getDriver()
        {
            return DriverName;
        }
        public string getCar()
        {
            return VehName;
        }
        public AC_Connector()
        {
            uc = new UdpClient();
            byte[] ba = { 127, 0, 0, 1 };
            IP = new IPAddress(ba);
            acd = null;
        }
        ~AC_Connector()
        {
            uc.Close(); //make sure it is closed
        }
        public void setIP(IPAddress ip)
        {
            disconnect();
            IP = ip;
        }
        public ACDataInterpreter getData()
        {   if (acd == null)
                return null;
            else
                return acd.clone();
        }
        public bool gethandshakeFinished()
        {
            return HandshakeFinished;
        }
        public void disconnect()
        {
            HandshakeFinished = false;
            uc.Close();
            uc = new UdpClient();
        }
        public bool connect()
        {
            try
            {
                AsyncCallback hs = new AsyncCallback(HanshakeFunc);
                uc.Connect(IP, 9996);
                uc.Send(handshake, 12);
                IPEndPoint ipe = new IPEndPoint(IP, 9996);
                HandshakeFinished = false;
                uc.BeginReceive(hs, 0);
            }
            catch
            { 
                return false;
            }
            return true;
        }
        void HanshakeFunc(IAsyncResult ar)
        {
            try
            {
                IPEndPoint ipe = new IPEndPoint(IP, 9996);
                byte[] rec = uc.EndReceive(ar, ref ipe);
                Encoding enc = Encoding.Unicode;
                char[] c = { (char)0 };
                VehName = enc.GetString(rec, 0, 100).TrimEnd(c);
                DriverName = enc.GetString(rec, 100, 100).TrimEnd(c);
                TrackName = enc.GetString(rec, 208, 100).TrimEnd(c);
                HandshakeFinished = true;
                uc.Send(subscribe, 12);

                //ipe = new IPEndPoint(IP, 9996);
                //ac = new AsyncCallback(ReceiveFunc);
                //object o = 0;
                //ar = uc.BeginReceive(ac, o);
            }
            catch
            {
                HandshakeFinished = false;
                disconnect();
            }
        }
        public void receiveSyncronously()
        {
            try
            {
                IPEndPoint ipe = new IPEndPoint(IP, 9996);
                byte[] rec = uc.Receive(ref ipe);
                if (acd == null)
                    acd = new ACDataInterpreter(rec);
                else
                    acd.setData(rec);
                receiveCounter++;
            }
            catch
            {
                requestCounter++;
            }
        }
        void ReceiveFunc(IAsyncResult ar)
        {
            //try
            {
                //if (ar.IsCompleted)
                {
                    IPEndPoint ipe = new IPEndPoint(IP, 9996);
                    byte[] rec = uc.EndReceive(ar, ref ipe);
                    if(acd==null)
                        acd = new ACDataInterpreter(rec);
                    else
                        acd.setData(rec);
                    receiveCounter++;
                }
                
            }
            //catch { acd = null; }
        }
        public void receive5ms()
        {
            //Receive Syncronously
            object o = 0;
            if (ar == null || ar.IsCompleted)
            {
                //ar = uc.BeginReceive(ac, o);
                //requestCounter++;
            }
        }
    }
}
