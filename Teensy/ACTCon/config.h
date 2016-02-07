
//#define FORCE_FEEDBACK

#define RPM_LED_DISPLAY

#define WS2812_DIPLAY
#define WS2812_NUM_LEDS    8
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
  dummy
};

int WS2812_getValue(enum WS2812_inputValue_t valueKey)
{
  switch(valueKey)  
  {
    WS2812_getValue_case(rpmprc10)
    WS2812_getValue_case(rpm)
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
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(0,CRGB::White,more_equal,rpmprc10,650)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(1,CRGB::Green,more_equal,rpmprc10,700)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(2,CRGB::Green,more_equal,rpmprc10,750)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(3,CRGB::Yellow,more_equal,rpmprc10,800)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(4,CRGB::Yellow,more_equal,rpmprc10,850)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(5,CRGB::Red,more_equal,rpmprc10,900)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(6,CRGB::Red,more_equal,rpmprc10,950)
  ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(7,CRGB::Red,more_equal,rpmprc10,980)
};
#define WS2812_Actions_SIZE sizeof(WS2812_Actions)/sizeof(WS2812_Action_t)




