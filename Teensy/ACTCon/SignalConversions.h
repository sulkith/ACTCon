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
}
