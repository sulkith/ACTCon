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
            file.WriteLine("\"time\"\t\"laptime\"\t\"AccPed\"\tBrkPed\"\t\"Clth\"\t\"nEng\"\t\"vVeh\"\t\"Gear\"\t\"StAng\"\t\"TAG\"");
            file.WriteLine("\"msec\"\t\"msec\"\t\"%\"\t\"%\"\t\"%\"\t\"rpm\"\t\"kmh\"\t\" \"\t\"Deg\"\t\" \"");
            file.Flush();
        }

        ~FileWriter()
        {
            try
            {
                file.Flush();
                file.Close();
            }
            catch (Exception e)
            {
            }
        }

        public void receiveData(ACDataInterpreter acd)
        {
            if (acd != null)
            {
                if (false)
                {
                    String line = s.ElapsedMilliseconds.ToString();
                    line += ";" + acd.getcurrlapTime();
                    line += ";" + (int)(acd.getped() * 99);//99 takes 2 byte to save while 100 takes 3
                    line += ";" + (int)(acd.getbrk() * 99);
                    line += ";" + (99 - (int)(acd.getclth() * 99));
                    line += ";" + (int)(acd.getrpm() / 100);
                    line += ";" + (int)(acd.getKMH());//scales up to 360 to be drawable with the rpm
                    line += ";" + acd.getgear() * 10;//scales up to 100 to be drawable with the Pedals
                    line += ";" + (int)(acd.getsteer() / 10 + 50);//scales up to 90 while middle Position is 50
                    file.WriteLine(line);
                }
                else
                {
                    String line = s.ElapsedMilliseconds.ToString();
                    line += "\t" + acd.getcurrlapTime();
                    line += "\t" + (int)(acd.getped() * 99);//99 takes 2 byte to save while 100 takes 3
                    line += "\t" + (int)(acd.getbrk() * 99);
                    line += "\t" + (99 - (int)(acd.getclth() * 99));
                    line += "\t" + (int)(acd.getrpm());
                    line += "\t" + (int)(acd.getKMH());
                    line += "\t" + acd.getgear();
                    line += "\t" + (int)(acd.getsteer());
                    line += "\t" + "\" \"";
                    file.WriteLine(line);
                }
            }
        }
    }
}
