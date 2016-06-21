using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.Threading.Tasks;
    
namespace AC_Teensy_Connector
{
    class FileWriter
    {
        StreamWriter file;
        Stopwatch s;
        public FileWriter(string path)
        {
            file = new System.IO.StreamWriter(path);
            s = new Stopwatch();
            s.Start();
            file.WriteLine("time;laptime;AccPed;BrkPed;Clth;nEng;vVeh;Gear;StAng");
        }

        ~FileWriter()
        {
            file.Close();
        }

        public void receiveData(ACDataInterpreter acd)
        {
            if (acd != null)
            { 
                String line = s.ElapsedMilliseconds.ToString();
                line += ";" + acd.getcurrlapTime();
                line += ";" + (int)(acd.getped()*99);//99 takes 2 byte to save while 100 takes 3
                line += ";" + (int)(acd.getbrk()*99);
                line += ";" + (99-(int)(acd.getclth()*99));
                line += ";" + (int)(acd.getrpm()/100);
                line += ";" + (int)(acd.getKMH());//scales up to 360 to be drawable with the rpm
                line += ";" + acd.getgear()*10;//scales up to 100 to be drawable with the Pedals
                line += ";" + (int)(acd.getsteer()/10+50);//scales up to 90 while middle Position is 50
                file.WriteLine(line);
            }
        }
    }
}
