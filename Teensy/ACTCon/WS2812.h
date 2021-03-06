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

const uint8_t WS2812_Actions_SIZE = sizeof(WS2812_Actions)/sizeof(WS2812_Action_t);
#define WS2812_CHIPSET     WS2811
#define WS2812_COLOR_ORDER GRB
CRGB leds[WS2812_NUM_LEDS];
bool WS2812_disabled;
CRGB WS2812_disabled_color;

void WS2812_ini()
{
  FastLED.addLeds<WS2812_CHIPSET, WS2812_LED_PIN, WS2812_COLOR_ORDER>(leds, WS2812_NUM_LEDS).setCorrection( TypicalSMD5050 );
  FastLED.setBrightness( WS2812_BRIGHTNESS );
  WS2812_disabled = false;
  WS2812_disabled_color = CRGB::Black;
  for (int i = 0; i < WS2812_Actions_SIZE; ++i)
  {
    if (WS2812_Actions[i].ledNumber >= WS2812_NUM_LEDS)
    {
      WS2812_disabled = true;
      WS2812_disabled_color = CRGB::Red; //Red Color on all leds means there is a lednumber detectet which is out of range.
    }
  }
}

bool WS2812_doCompare(enum WS2812_CompareType_t compareType, enum WS2812_inputValue_t inputValue, int compareValue)
{
  switch (compareType)
  {
    case less:
      return WS2812_getValue(inputValue) < compareValue;
    case less_equal:
      return WS2812_getValue(inputValue) <= compareValue;
    case equal:
      return WS2812_getValue(inputValue) == compareValue;
    case more_equal:
      return WS2812_getValue(inputValue) >= compareValue;
    case more:
      return WS2812_getValue(inputValue) > compareValue;
    case not_equal:
      return WS2812_getValue(inputValue) != compareValue;
    case always_true:
      return true;
    default:
      return false;
  }
}

void WS2812_cyclic()
{

  for (int i = 0; i < WS2812_NUM_LEDS; ++i)
  {
    leds[i] = WS2812_disabled_color;
  }
  if (!WS2812_disabled && T15_st)    for (int i = 0; i < WS2812_Actions_SIZE; ++i)
    {
      if (WS2812_doCompare(WS2812_Actions[i].compareType, WS2812_Actions[i].inputValue, WS2812_Actions[i].compareValue))
      {
        leds[WS2812_Actions[i].ledNumber] = WS2812_Actions[i].ledColor;
      }
    }
  FastLED.show();
}

