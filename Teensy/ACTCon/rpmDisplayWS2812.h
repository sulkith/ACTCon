#define RPM_WS2812_CHIPSET     WS2811
#define RPM_WS2812_COLOR_ORDER GRB
CRGB leds[RPM_WS2812_NUM_LEDS];

void rpmDisplayWS2812_ini()
{
  FastLED.addLeds<RPM_WS2812_CHIPSET, RPM_WS2812_LED_PIN, RPM_WS2812_COLOR_ORDER>(leds, RPM_WS2812_NUM_LEDS).setCorrection( TypicalSMD5050 );
  FastLED.setBrightness( RPM_WS2812_BRIGHTNESS );
}

void rpmDisplayWS2812_cyclic()
{
  
  for (int i = 0; i < RPM_WS2812_NUM_LEDS; ++i)
  {
    if(rpmprc10>= RPM_WS2812_LED_ACTIVE_POINT[i])
      leds[i] = RPM_WS2812_LED_COLORS[i];
    else
      leds[i] = CRGB::Black;
  }
  FastLED.show();
}

