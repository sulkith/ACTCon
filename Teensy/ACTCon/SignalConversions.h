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
  SignalConversion(); // initializes percentage and rpm
  vfzg = 0;//(millis()/200)%1000;
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
}
