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
