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

#include <FastLED.h>

#define LED_PIN     3

// Information about the LED strip itself
#define NUM_LEDS    34
#define CHIPSET     WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
#define BRIGHTNESS  32

int percentage;
int rpm;
int rpmt;
long maxrpm;
enum state_t
{
  idle,
  start,
  rec,
  recrpm,
  finrpm,
  fin
} state;
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
  rpmt = 0;
  maxrpm = 1000;
  state = idle;

  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalSMD5050 );
  FastLED.setBrightness( BRIGHTNESS );
}


void loop()
{

  //check serial and receive messages
  if (Serial.available())
  {
    //receive
    byte incomingByte = Serial.read();
    //decode vibration level
    if (state == rec && incomingByte >= '0' && incomingByte <= '9')
    {
      percentage *= 10;
      percentage += incomingByte - '0';
      Serial.print("Percentage Set to: ");
      Serial.println(percentage);
    }
    //decode rpm
    if (state == recrpm && incomingByte >= '0' && incomingByte <= '9')
    {
      rpmt *= 10;
      rpmt += incomingByte - '0';
      Serial.print("rpm Set to: ");
      Serial.println(rpmt);
    }
    //find start and stop Bytes A R and stop E r
    if (incomingByte == 'A')
    {
      state = rec;
    }
    if (incomingByte == 'R')
    {
      rpmt = 0;
      state = recrpm;
    }
    if (incomingByte == 'E' && state == rec)
    {
      state = fin;
    }
    if (incomingByte == 'r' && state == recrpm)
    {
      state = idle;
      rpm = rpmt;
    }
  }
  //apply received values
  if (state == fin)
  {
    state = idle;
    if (percentage > 100) {
      percentage = 0;
      return;
    }
    if (percentage > 50)
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
  if (rpm > maxrpm) maxrpm = rpm;
  //TODO: Filter downshifts --> driving fullspeed in the 6th gear and dunshifting rapidly brings engine to 15000 rpm which is definately not maxrpm

  //LED Controll for max rpm
  if ((rpm > (maxrpm * 95 / 100)))
  {
    if (((millis() / 50) % 2) == 0)
      digitalWrite(ledPin, HIGH);
    else
      digitalWrite(ledPin, LOW);
  }
  else if ((rpm > (maxrpm * 85 / 100)))
  {
    digitalWrite(ledPin, HIGH);
  }
  else
    digitalWrite(ledPin, LOW);


  for (int i = 0; i < NUM_LEDS; ++i)
  {
    CRGB Color = CRGB::Green;
    if (i >= 24) Color = CRGB::Yellow;
    if (i >= 28) Color = CRGB::Red;
    if ((((long)rpm) * NUM_LEDS / maxrpm) > i)
      leds[i] = Color;
    else
      leds[i] = CRGB::Black;
  }
  FastLED.show();
}


