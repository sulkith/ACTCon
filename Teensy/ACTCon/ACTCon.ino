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
#include <TFT.h>  // Arduino LCD library
#include <SPI.h>
//#include <usb_keyboard.h>
#include "globals.h"
#include "config.h"
#include "pinning.h"
#include "util.h"
#include "SerialConf.h"
#include "SerialComStack.h"
#include "SignalConversions.h"
#include "ForceFeedback.h"
#include "rpm.h"
#include "WS2812.h"
#include "ST7753_Display.h"
#include "actionScheduler.h"
#include "keyboardOutput.h"
#include "digitalInput.h"



// Information about the LED strip itself


void setup()
{
  SerialComStack_ini();
  SignalConversion_ini();
  ForceFeedback_ini();
  rpm_ini();
  WS2812_ini();
  ST7735_Display_ini();
  actionScheduler_ini();
}

void reIniSystem()
{
  SerialComStack_ReIni();
  SignalConversion_ini();
  ForceFeedback_ini();
  rpm_ini();
  WS2812_ini();
  ST7735_Display_cyclic(); // Cyclic Task is called to not redraw everything on the Display only the new Data
  keyboardOutput_ini();
  digitalInput_ini();
  actionScheduler_ini();
}


void loop()
{
  static int ctr = 0;
  ctr++;
  SerialComStack_cyclic();
  if (ctr % 1 == 0)
  {
    SignalConversion();
    ForceFeedback_cyclic();
    rpm_cyclic();
    WS2812_cyclic();
    ST7735_Display_cyclic();
    digitalInput_cyclic();
  }
  actionScheduler_cyclic();
}


