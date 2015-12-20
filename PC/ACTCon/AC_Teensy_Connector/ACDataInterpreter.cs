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


namespace AC_Teensy_Connector
{
    class ACDataInterpreter
    {
        /*struct RTCarInfo
        {
0 char identifier; 97 32
2 int size; 17 63 72 01

8 float speed_Kmh; 147 220 115 61
12 float speed_Mph; 82 135 23 61
16 float speed_Ms; 139 122 135 60

20 bool isAbsEnabled; 1
21 bool isAbsInAction; 0
22 bool isTcInAction; 0
23 bool isTcEnabled; 1
24 bool isInPit; 1
25 bool isEngineLimiterOn; 0


26 float accG_vertical;
30 float accG_horizontal;
34 float accG_frontal;

38 int lapTime; 0 0 50 184
42 int lastLap; 0 0 0 0
46 int bestLap; 0 0 0 0
50 int lapCount; 0 0 0 0

54 float gas; 0 0 232 106
58 float brake; 219 62 0 0
62 float clutch; 0 0 0 0
66 float engineRPM; 128 63 77 125
70 float steer; 233 69 143 194
74 int gear; 140 193 1 0
78 float cgHeight;

            float wheelAngularSpeed[4];
            float slipAngle[4];
            float slipAngle_ContactPatch[4];
            float slipRatio[4];
            float tyreSlip[4];
            float ndSlip[4];
            float load[4];
            float Dy[4];
            float Mz[4];
            float tyreDirtyLevel[4];

            float camberRAD[4];
            float tyreRadius[4];
            float tyreLoadedRadius[4];
            float suspensionHeight[4];
            float carPositionNormalized;
            float carSlope;
            float carCoordinates[3];

        };*/
        byte[] rec;
        public ACDataInterpreter(byte[] arr)
        { rec = arr; }
        public float getKMH()
        {
            return System.BitConverter.ToSingle(rec, 8);
        }
        public float getMPH()
        {
            return System.BitConverter.ToSingle(rec, 12);
        }
        public float getMS()
        {
            return System.BitConverter.ToSingle(rec, 16);
        }
        /*20 bool isAbsEnabled; 1
        21 bool isAbsInAction; 0
        22 bool isTcInAction; 0
        23 bool isTcEnabled; 1
        24 bool isInPit; 1
        25 bool isEngineLimiterOn; 0*/
        public bool getABSEna()
        {
            return (rec[20] == 1);
        }
        public bool getABSAct()
        {
            return (rec[21] == 1);
        }
        public bool getTCAct()
        {
            return (rec[22] == 1);
        }
        public bool getTCEna()
        {
            return (rec[23] == 1);
        }
        public bool getInPit()
        {
            return (rec[24] == 1);
        }
        public bool getEngLim()
        {
            return (rec[25] == 1);
        }
        /*
        2Fill
        28 float accG_vertical;
        32 float accG_horizontal;
        36 float accG_frontal;*/
        public float getaccG_Vertical()
        {
            return System.BitConverter.ToSingle(rec, 28);
        }
        public float getaccG_Horizontal()
        {
            return System.BitConverter.ToSingle(rec, 32);
        }
        public float getaccG_Frontal()
        {
            return System.BitConverter.ToSingle(rec, 36);
        }
        /*40 int lapTime; 0 0 50 184
        44 int lastLap; 0 0 0 0
        48 int bestLap; 0 0 0 0
        52 int lapCount; 0 0 0 0*/
        public int getcurrlapTime()
        {
            return System.BitConverter.ToInt32(rec, 40);
        }
        public int getlastlapTime()
        {
            return System.BitConverter.ToInt32(rec, 44);
        }
        public int getbestlapTime()
        {
            return System.BitConverter.ToInt32(rec, 48);
        }
        public int getlapCount()
        {
            return System.BitConverter.ToInt32(rec, 52);
        }
        /*
        56 float gas; 0 0 232 106
        60 float brake; 219 62 0 0
        64 float clutch; 0 0 0 0
        68 float engineRPM; 128 63 77 125
        72 float steer; 233 69 143 194
        76 int gear; 140 193 1 0
        80 float cgHeight;*/
        public float getped()
        {
            return System.BitConverter.ToSingle(rec, 56);
        }
        public float getbrk()
        {
            return System.BitConverter.ToSingle(rec, 60);
        }
        public float getclth()
        {
            return System.BitConverter.ToSingle(rec, 64);
        }
        public float getrpm()
        {
            return System.BitConverter.ToSingle(rec, 68);
        }
        public float getsteer()
        {
            return System.BitConverter.ToSingle(rec, 72);
        }
        public int getgear()
        {
            return System.BitConverter.ToInt32(rec, 76);
        }
        public float getcgHeight()
        {
            return System.BitConverter.ToSingle(rec, 80);
        }
        /*  84 float wheelAngularSpeed[4]; 4*4
            100 float slipAngle[4];
            116 float slipAngle_ContactPatch[4];
            132 float slipRatio[4];
            148 float tyreSlip[4];
            164 float ndSlip[4];
            180 float load[4];
            196 float Dy[4];
            212 float Mz[4];
            228 float tyreDirtyLevel[4];*/
        public float[] getwheelAngularSpeed()
        {
            const int start = 84;
            float[] t = { 0, 0, 0, 0 };
            t[0] = System.BitConverter.ToSingle(rec, start);
            t[1] = System.BitConverter.ToSingle(rec, start + 4);
            t[2] = System.BitConverter.ToSingle(rec, start + 8);
            t[3] = System.BitConverter.ToSingle(rec, start + 12);
            return t;
        }
        public float[] getslipangle()
        {
            const int start = 100;
            float[] t = { 0, 0, 0, 0 };
            t[0] = System.BitConverter.ToSingle(rec, start);
            t[1] = System.BitConverter.ToSingle(rec, start + 4);
            t[2] = System.BitConverter.ToSingle(rec, start + 8);
            t[3] = System.BitConverter.ToSingle(rec, start + 12);
            return t;
        }
        public float[] getslipanglecontactpatch()
        {
            const int start = 116;
            float[] t = { 0, 0, 0, 0 };
            t[0] = System.BitConverter.ToSingle(rec, start);
            t[1] = System.BitConverter.ToSingle(rec, start + 4);
            t[2] = System.BitConverter.ToSingle(rec, start + 8);
            t[3] = System.BitConverter.ToSingle(rec, start + 12);
            return t;
        }
        public float[] getslipratio()
        {
            const int start = 132;
            float[] t = { 0, 0, 0, 0 };
            t[0] = System.BitConverter.ToSingle(rec, start);
            t[1] = System.BitConverter.ToSingle(rec, start + 4);
            t[2] = System.BitConverter.ToSingle(rec, start + 8);
            t[3] = System.BitConverter.ToSingle(rec, start + 12);
            return t;
        }
        public float[] gettyreslip()
        {
            const int start = 148;
            float[] t = { 0, 0, 0, 0 };
            t[0] = System.BitConverter.ToSingle(rec, start);
            t[1] = System.BitConverter.ToSingle(rec, start + 4);
            t[2] = System.BitConverter.ToSingle(rec, start + 8);
            t[3] = System.BitConverter.ToSingle(rec, start + 12);
            return t;
        }
    }
}
