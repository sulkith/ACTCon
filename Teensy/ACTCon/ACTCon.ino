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

int percentage;
int rpm;
int rpmt;
int maxrpm;
enum state_t
{
  idle,
  start,
  rec,
  recrpm,
  finrpm,
  fin
}state;
const int ledPin = 13;
const int FFPin = 12;
void setup()
{
  Serial.begin(9600); // USB is always 12 Mbit/sec
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(FFPin, OUTPUT);
  digitalWrite(FFPin, HIGH);
  percentage = 0;
  rpm = 0;
  rpmt=0;
  maxrpm = 1000;
  state=idle;
}


void loop()
{
  
//check serial and receive messages
  if(Serial.available())
  {
//receive
    byte incomingByte = Serial.read();
//decode vibration level
    if(state == rec && incomingByte >= '0' && incomingByte <= '9')
    {
      percentage *= 10;
      percentage += incomingByte -'0';
      Serial.print("Percentage Set to: ");
      Serial.println(percentage);
    }
//decode rpm
    if(state == recrpm && incomingByte >= '0' && incomingByte <= '9')
    {
      rpmt *= 10;
      rpmt += incomingByte -'0';
      Serial.print("rpm Set to: ");
      Serial.println(rpmt);
    }
//find start and stop Bytes A R and stop E r
    if(incomingByte == 'A')
    {
      state = rec;
    }
    if(incomingByte == 'R')
    {
      rpmt = 0;
      state = recrpm;
    }
    if(incomingByte == 'E' && state == rec)
    {
      state = fin;  
    }
    if(incomingByte == 'r' && state == recrpm)
    {
      state = idle;  
      rpm = rpmt;
    }
  }
//apply received values
  if(state == fin)
  {
    state = idle;
    if(percentage >100){percentage = 0; return;}
    if(percentage > 50)
    {
      digitalWrite(FFPin, LOW);  
    }
    else
    {
      digitalWrite(FFPin, HIGH);  
    }
    percentage = 0;
  }
  
//find max rpm
  if(rpm > maxrpm) maxrpm = rpm;
//TODO: Filter downshifts --> driving fullspeed in the 6th gear and dunshifting rapidly brings engine to 15000 rpm which is definately not maxrpm
  
//LED Controll for max rpm
  if((rpm > (maxrpm*95/100)))
  {
    if(((millis()/50) % 2)==0)
      digitalWrite(ledPin, HIGH);
    else
      digitalWrite(ledPin, LOW);
  }
  else if((rpm > (maxrpm*85/100)))
  {
    digitalWrite(ledPin, HIGH);
  }
  else
    digitalWrite(ledPin, LOW);
}

