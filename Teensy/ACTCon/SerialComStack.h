enum ComState_e
{
  comIdle,
  messageBegin,
  knownMessage,
  unknownMessage,
  receiveComplete,
  invalidMessage
}ComState;
byte ComCurrentIdx;
byte buffer[COMMAXLEN];
byte ComCurPos;
void SerialComStack_ini()
{
  Serial.begin(115200); // USB is always 12 Mbit/sec
  Serial.println("Serial started");
  Serial.setTimeout(30);
  ComState = comIdle;
  ComCurrentIdx = 0;
  ComCurPos = 0;
}

void SerialComStack_cyclic()
{
  while (Serial.available())
  {
    byte incomingByte = Serial.read();
    if(ComState == comIdle && incomingByte == 'A')
    {
      //begin of message
      ComState = messageBegin;
      //Serial.println("Started Message");
    }
    else if(ComState == messageBegin)
    {
      ComState = unknownMessage;
      ComCurrentIdx = 0;
      ComCurPos = 0;
      for(byte i = 0; i < sizeof(SerialData)/sizeof(SerialData_cs); ++i)
      {
        if(SerialData[i].ID == incomingByte)
        {
          ComCurrentIdx = i;
          ComState = knownMessage;
          //Serial.println("found Index");
          break;
        }  
      } 
    }
    else if(ComState == knownMessage)
    {
      if(ComCurPos<SerialData[ComCurrentIdx].len)
      {
        buffer[ComCurPos] = incomingByte;
        ComCurPos++;
        //Serial.println("byte");
      }
      else
      {
        if(incomingByte == 'E')
        {
          ComState = receiveComplete;
          //Serial.println("last byte valid");
        }
        else
        {
          //Serial.println("last byte invalid");
          ComState = invalidMessage;
        }
      }
    }

    if(ComState == receiveComplete)
    {
      //Serial.println("done memcpy");
      memcpy(SerialData[ComCurrentIdx].ptr,buffer,SerialData[ComCurrentIdx].len);
      ComState = comIdle;
    }
    else if(ComState == invalidMessage)
    {
      //error Stuff ;-)
      ComState = comIdle;
    }
  }
  
}
