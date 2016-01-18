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
#include "config.h"
#include "globals.h"
#include "pinning.h"
#include "util.h"
#include "SerialConf.h"
#include "SerialComStack.h"
#include "SignalConversions.h"
#include "ForceFeedback.h"
#include "rpm.h"
#include "rpmDisplayWS2812.h"



// Information about the LED strip itself


void setup()
{
  SerialComStack_ini();
  SignalConversion_ini();
  ForceFeedback_ini();
  rpm_ini();
  rpmDisplayWS2812_ini();
}


void loop()
{
  SerialComStack_cyclic();
  SignalConversion();
  ForceFeedback_cyclic();
  rpm_cyclic();

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


  rpmDisplayWS2812_cyclic();
}


