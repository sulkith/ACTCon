void SignalConversion();

void SignalConversion_ini()
{
  for(byte i = 0; i< 3; ++i)
  {
    inputA[i] = '0'; 
    inputR[i] = '0';
  }
  for(byte i = 3; i< 5; ++i)
  {
    inputR[i] = '0';
  }
  
  vfzg = 0;//(millis()/200)%1000;
  gear[0] = 'N';
  gear[1] = 0;
  abstc = 0x00;
  curlaptime = 0;
  lastlaptime = 0;
  SignalConversion(); // initializes percentage and rpm
}
void SignalConversion()
{
  int oldpercentage = percentage;
  percentage = 0;
  for(uint8_t i = 0; i < 3; ++i)
  {
    percentage *= 10;
    percentage += inputA[i] - '0';
  }
  if(oldpercentage != percentage)
  {
    Serial.print("percentage changed to: ");
    Serial.println(percentage);
  }
  int oldrpm = rpm;
  rpm = 0;
  for(uint8_t i = 0; i < 5; ++i)
  {
    rpm *= 10;
    rpm += inputR[i] - '0';
  }
  if(oldrpm != rpm)
  {
    Serial.print("rpm changed to: ");
    Serial.println(rpm);
  }

  //vfzg = (millis()/200)%1000;
  //String temp = String((millis()/500)%1000);
  //temp.toCharArray(vfzg_ca, 4);
  vfzg_ca[0] = (vfzg>=100)?(vfzg / 100)%10 + 0x30:' ';
  vfzg_ca[1] = (vfzg>=10)?(vfzg / 10)%10 + 0x30:' ';
  vfzg_ca[2] = (vfzg)%10 + 0x30;

  ABS = (DriverAssistance_t)(abstc & 0x3);
  TC = (DriverAssistance_t)((abstc >> 4) & 0x3);

  //get minutes
  uint8_t minutes = curlaptime /1000 /*ms->s*/ / 60 /*s-->min*/;
  uint8_t seconds = (curlaptime - ((uint32_t)minutes*1000*60)) /1000 /*ms-->s*/;
  uint8_t milliseconds = curlaptime % 1000;

  //" 00:00:00"
  curlaptimetext[0] = (minutes>=100)?(minutes / 100)%10 + 0x30:' ';
  curlaptimetext[1] = (minutes / 10)%10 + 0x30;
  curlaptimetext[2] = (minutes)%10 + 0x30;
  
  curlaptimetext[4] = (seconds / 10)%10 + 0x30;
  curlaptimetext[5] = (seconds)%10 + 0x30;

  curlaptimetext[7] = (milliseconds / 100)%10 + 0x30;
  curlaptimetext[8] = (milliseconds/10)%10 + 0x30;

  minutes = lastlaptime /1000 /*ms->s*/ / 60 /*s-->min*/;
  seconds = (lastlaptime - ((uint32_t)minutes*1000*60)) /1000 /*ms-->s*/;
  milliseconds = lastlaptime % 1000;

  //" 00:00:00"
  lastlaptimetext[0] = (minutes>=100)?(minutes / 100)%10 + 0x30:' ';
  lastlaptimetext[1] = (minutes / 10)%10 + 0x30;
  lastlaptimetext[2] = (minutes)%10 + 0x30;
  
  lastlaptimetext[4] = (seconds / 10)%10 + 0x30;
  lastlaptimetext[5] = (seconds)%10 + 0x30;

  lastlaptimetext[7] = (milliseconds / 100)%10 + 0x30;
  lastlaptimetext[8] = (milliseconds/10)%10 + 0x30;
}
