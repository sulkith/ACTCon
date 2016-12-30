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
#define WS2812_NUM_LEDS    24+24+8
#define WS2812_BRIGHTNESS  255
#define WS2812_LOWEST_LED_PERC 80
#define WS2812_HIGHEST_LED_PERC 98

#define WS2812_WHITE 0x202020
#define WS2812_GREEN 0x002000
#define WS2812_YELLOW 0x202000
#define WS2812_RED 0x301000
#define WS2812_BRIGHT_RED CRGB::Red
#define WS2812_BLUE 0x000020
//CRGB WS2812_LED_COLORS[WS2812_NUM_LEDS] =      {CRGB::White,WS2812_GREEN,WS2812_GREEN,WS2812_YELLOW,WS2812_YELLOW,WS2812_RED,WS2812_RED,WS2812_RED};
//int WS2812_LED_ACTIVE_POINT[WS2812_NUM_LEDS] = {650,        700,        750,        800,         850,         900,      950,      980};

#define CONFIG_H_WS2812_CompareType_t
#include "configTypes.h"

enum WS2812_inputValue_t
{
  //remember to add value in the WS2812_getValue function too!!!
  WS2812_getValue_enum(rpmprc10)
  WS2812_getValue_enum(rpm)
  WS2812_getValue_enum(vfzg)
  WS2812_getValue_enum(gVertical)
  WS2812_getValue_enum(gFrontal)
  dummy
};

int WS2812_getValue(enum WS2812_inputValue_t valueKey)
{
  switch (valueKey)
  {
      WS2812_getValue_case(rpmprc10)
      WS2812_getValue_case(rpm)
      WS2812_getValue_case(vfzg)
    case idgVertical:
      return gForce[gForceIdxVertical];
    case idgFrontal:
      return gForce[gForceIdxFrontal];
    default:
      return -1;
  }
  return 0;
}

#define START_LED_STRIP1 48
#define START_LED_DIAL1 0
#define START_LED_DIAL2 24

#define CONFIG_H_WS2812_Action_t
#include "configTypes.h"
/*Valid Compares are less, less_equal, equal, more_equal, more, not_equal, always_true*/
/*Pay Attention. the Actions a checked from first to last. later Actions override previous ones*/
WS2812_Action_t WS2812_Actions[] =
{ 
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_STRIP1 + 0, WS2812_GREEN, more_equal, rpmprc10, 650)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_STRIP1 + 1, WS2812_GREEN, more_equal, rpmprc10, 700)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_STRIP1 + 2, WS2812_YELLOW, more_equal, rpmprc10, 750)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_STRIP1 + 3, WS2812_YELLOW, more_equal, rpmprc10, 800)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_STRIP1 + 4, WS2812_RED, more_equal, rpmprc10, 850)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_STRIP1 + 5, WS2812_RED, more_equal, rpmprc10, 900)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_STRIP1 + 6, WS2812_BRIGHT_RED, more_equal, rpmprc10, 950)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_STRIP1 + 7, WS2812_BRIGHT_RED, more_equal, rpmprc10, 950)
  
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_STRIP1 + 0, WS2812_BRIGHT_RED, more_equal, rpmprc10, 950)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_STRIP1 + 1, WS2812_BRIGHT_RED, more_equal, rpmprc10, 950)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_STRIP1 + 2, WS2812_BRIGHT_RED, more_equal, rpmprc10, 950)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_STRIP1 + 3, WS2812_BRIGHT_RED, more_equal, rpmprc10, 950)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_STRIP1 + 4, WS2812_BRIGHT_RED, more_equal, rpmprc10, 950)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_STRIP1 + 5, WS2812_BRIGHT_RED, more_equal, rpmprc10, 950)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_STRIP1 + 6, WS2812_BRIGHT_RED, more_equal, rpmprc10, 950)

  //RPM DIAL
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 15, WS2812_WHITE, more_equal, rpmprc10, 50)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 16, WS2812_WHITE, more_equal, rpmprc10, 100)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 17, WS2812_WHITE, more_equal, rpmprc10, 150)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 18, WS2812_WHITE, more_equal, rpmprc10, 200)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 19, WS2812_WHITE, more_equal, rpmprc10, 250)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 20, WS2812_WHITE, more_equal, rpmprc10, 300)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 21, WS2812_WHITE, more_equal, rpmprc10, 350)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 22, WS2812_WHITE, more_equal, rpmprc10, 400)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 23, WS2812_WHITE, more_equal, rpmprc10, 450)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 0, WS2812_WHITE, more_equal, rpmprc10, 500)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 1, WS2812_WHITE, more_equal, rpmprc10, 550)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 2, WS2812_WHITE, more_equal, rpmprc10, 600)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 3, WS2812_WHITE, more_equal, rpmprc10, 650)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 4, WS2812_WHITE, more_equal, rpmprc10, 700)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 5, WS2812_YELLOW, more_equal, rpmprc10, 750)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 6, WS2812_YELLOW, more_equal, rpmprc10, 800)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 7, WS2812_RED, more_equal, rpmprc10, 850)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 8, WS2812_RED, more_equal, rpmprc10, 900)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 9, WS2812_BRIGHT_RED, more_equal, rpmprc10, 950)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL1 + 10, WS2812_BRIGHT_RED, more_equal, rpmprc10, 980)

  //VFZG DIAL
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 15, WS2812_WHITE, more_equal, vfzg, 18)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 16, WS2812_WHITE, more_equal, vfzg, 18 * 2)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 17, WS2812_WHITE, more_equal, vfzg, 18 * 3)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 18, WS2812_WHITE, more_equal, vfzg, 18 * 4)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 19, WS2812_WHITE, more_equal, vfzg, 18 * 5)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 20, WS2812_WHITE, more_equal, vfzg, 18 * 6)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 21, WS2812_WHITE, more_equal, vfzg, 18 * 7)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 22, WS2812_WHITE, more_equal, vfzg, 18 * 8)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 23, WS2812_WHITE, more_equal, vfzg, 18 * 9)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 0, WS2812_WHITE, more_equal, vfzg, 18 * 10)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 1, WS2812_WHITE, more_equal, vfzg, 18 * 11)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 2, WS2812_WHITE, more_equal, vfzg, 18 * 12)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 3, WS2812_WHITE, more_equal, vfzg, 18 * 13)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 4, WS2812_WHITE, more_equal, vfzg, 18 * 14)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 5, WS2812_WHITE, more_equal, vfzg, 18 * 15)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 6, WS2812_WHITE, more_equal, vfzg, 18 * 16)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 7, WS2812_WHITE, more_equal, vfzg, 18 * 17)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 8, WS2812_WHITE, more_equal, vfzg, 18 * 18)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 9, WS2812_WHITE, more_equal, vfzg, 18 * 19)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(START_LED_DIAL2 + 10, WS2812_WHITE, more_equal, vfzg, 18 * 20)

  /*
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(0,WS2812_RED,less_equal,gFrontal,-400)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(23,WS2812_RED,less_equal,gFrontal,-600)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(1,WS2812_RED,less_equal,gFrontal,-600)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(22,WS2812_RED,less_equal,gFrontal,-800)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(2,WS2812_RED,less_equal,gFrontal,-800)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(21,WS2812_RED,less_equal,gFrontal,-1000)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(3,WS2812_RED,less_equal,gFrontal,-1000)

    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(12,WS2812_GREEN,more_equal,gFrontal,400)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(11,WS2812_GREEN,more_equal,gFrontal,600)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(13,WS2812_GREEN,more_equal,gFrontal,600)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(10,WS2812_GREEN,more_equal,gFrontal,800)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(14,WS2812_GREEN,more_equal,gFrontal,800)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(9,WS2812_GREEN,more_equal,gFrontal,1000)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(15,WS2812_GREEN,more_equal,gFrontal,1000)

    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(18,WS2812_YELLOW,less_equal,gVertical,-400)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(17,WS2812_YELLOW,less_equal,gVertical,-600)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(19,WS2812_YELLOW,less_equal,gVertical,-600)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(16,WS2812_YELLOW,less_equal,gVertical,-800)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(20,WS2812_YELLOW,less_equal,gVertical,-800)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(15,WS2812_YELLOW,less_equal,gVertical,-1000)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(21,WS2812_YELLOW,less_equal,gVertical,-1000)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(14,WS2812_YELLOW,less_equal,gVertical,-1200)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(20,WS2812_YELLOW,less_equal,gVertical,-1200)

    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(6,WS2812_YELLOW,more_equal,gVertical,400)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(5,WS2812_YELLOW,more_equal,gVertical,600)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(7,WS2812_YELLOW,more_equal,gVertical,600)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(4,WS2812_YELLOW,more_equal,gVertical,800)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(8,WS2812_YELLOW,more_equal,gVertical,800)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(3,WS2812_YELLOW,more_equal,gVertical,1000)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(9,WS2812_YELLOW,more_equal,gVertical,1000)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(2,WS2812_YELLOW,more_equal,gVertical,1200)
    ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(10,WS2812_YELLOW,more_equal,gVertical,1200)
    */

};





