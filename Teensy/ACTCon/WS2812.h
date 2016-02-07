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
  if (!WS2812_disabled)
    for (int i = 0; i < WS2812_Actions_SIZE; ++i)
    {
      if (WS2812_doCompare(WS2812_Actions[i].compareType, WS2812_Actions[i].inputValue, WS2812_Actions[i].compareValue))
      {
        leds[WS2812_Actions[i].ledNumber] = WS2812_Actions[i].ledColor;
      }
    }
  FastLED.show();
}

