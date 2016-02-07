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
//#define FORCE_FEEDBACK

#define RPM_LED_DISPLAY

#define WS2812_DIPLAY
#define WS2812_NUM_LEDS    32
#define WS2812_BRIGHTNESS  40
#define WS2812_LOWEST_LED_PERC 80
#define WS2812_HIGHEST_LED_PERC 98
CRGB WS2812_LED_COLORS[WS2812_NUM_LEDS] =      {CRGB::White,CRGB::Green,CRGB::Green,CRGB::Yellow,CRGB::Yellow,CRGB::Red,CRGB::Red,CRGB::Red};
int WS2812_LED_ACTIVE_POINT[WS2812_NUM_LEDS] = {650,        700,        750,        800,         850,         900,      950,      980};

#define CONFIG_H_WS2812_CompareType_t
#include "configTypes.h"

enum WS2812_inputValue_t
{
  WS2812_getValue_enum(rpmprc10)
  WS2812_getValue_enum(rpm)
  WS2812_getValue_enum(gVertical)
  WS2812_getValue_enum(gFrontal)
  dummy
};

int WS2812_getValue(enum WS2812_inputValue_t valueKey)
{
  switch(valueKey)  
  {
    WS2812_getValue_case(rpmprc10)
    WS2812_getValue_case(rpm)
    case idgVertical:
      return gForce[gForceIdxVertical];
    case idgFrontal:
      return gForce[gForceIdxFrontal];
    default:
      return -1;
  }
  return 0;
}

#define CONFIG_H_WS2812_Action_t
#include "configTypes.h"
/*Valid Compares are less, less_equal, equal, more_equal, more, not_equal, always_true*/
/*Pay Attention. the Actions a checked from first to last. later Actions override previous ones*/
WS2812_Action_t WS2812_Actions[] = 
{
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(24+0,CRGB::White,more_equal,rpmprc10,650)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(24+1,CRGB::Green,more_equal,rpmprc10,700)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(24+2,CRGB::Green,more_equal,rpmprc10,750)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(24+3,CRGB::Yellow,more_equal,rpmprc10,800)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(24+4,CRGB::Yellow,more_equal,rpmprc10,850)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(24+5,CRGB::Red,more_equal,rpmprc10,900)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(24+6,CRGB::Red,more_equal,rpmprc10,950)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(24+7,CRGB::Red,more_equal,rpmprc10,980)

  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(0,CRGB::Red,less_equal,gFrontal,-400)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(23,CRGB::Red,less_equal,gFrontal,-600)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(1,CRGB::Red,less_equal,gFrontal,-600)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(22,CRGB::Red,less_equal,gFrontal,-800)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(2,CRGB::Red,less_equal,gFrontal,-800)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(21,CRGB::Red,less_equal,gFrontal,-1000)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(3,CRGB::Red,less_equal,gFrontal,-1000)
  
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(12,CRGB::Green,more_equal,gFrontal,400)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(11,CRGB::Green,more_equal,gFrontal,600)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(13,CRGB::Green,more_equal,gFrontal,600)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(10,CRGB::Green,more_equal,gFrontal,800)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(14,CRGB::Green,more_equal,gFrontal,800)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(9,CRGB::Green,more_equal,gFrontal,1000)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(15,CRGB::Green,more_equal,gFrontal,1000)
  
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(18,CRGB::Yellow,less_equal,gVertical,-400)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(17,CRGB::Yellow,less_equal,gVertical,-600)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(19,CRGB::Yellow,less_equal,gVertical,-600)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(16,CRGB::Yellow,less_equal,gVertical,-800)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(20,CRGB::Yellow,less_equal,gVertical,-800)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(15,CRGB::Yellow,less_equal,gVertical,-1000)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(21,CRGB::Yellow,less_equal,gVertical,-1000)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(14,CRGB::Yellow,less_equal,gVertical,-1200)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(20,CRGB::Yellow,less_equal,gVertical,-1200)
  
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(6,CRGB::Yellow,more_equal,gVertical,400)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(5,CRGB::Yellow,more_equal,gVertical,600)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(7,CRGB::Yellow,more_equal,gVertical,600)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(4,CRGB::Yellow,more_equal,gVertical,800)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(8,CRGB::Yellow,more_equal,gVertical,800)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(3,CRGB::Yellow,more_equal,gVertical,1000)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(9,CRGB::Yellow,more_equal,gVertical,1000)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(2,CRGB::Yellow,more_equal,gVertical,1200)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(10,CRGB::Yellow,more_equal,gVertical,1200)
};
#define WS2812_Actions_SIZE sizeof(WS2812_Actions)/sizeof(WS2812_Action_t)




