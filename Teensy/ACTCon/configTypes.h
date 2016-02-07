#ifdef CONFIG_H_WS2812_CompareType_t
enum WS2812_CompareType_t
{
  less,
  less_equal,
  equal,
  more_equal,
  more,
  not_equal,
  always_true
};

#define WS2812_getValue_enum(value) id##value,
#define WS2812_getValue_case(value) case id##value: return (int)value;

#undef CONFIG_H_WS2812_CompareType_t
#endif

#ifdef CONFIG_H_WS2812_Action_t

struct WS2812_Action_t
{
  uint8_t ledNumber;
  CRGB ledColor;
  enum WS2812_CompareType_t compareType;
  enum WS2812_inputValue_t inputValue;
  int compareValue;
};

#define ACTION_NR_COLOR_COMPARE_INPUTVALUE_COMPAREVALUE(nr,color,compt,val,cval) {nr,color,compt,id##val,cval},

#undef CONFIG_H_WS2812_Action_t
#endif

#ifdef CONFIG_H_FOOTER


#undef CONFIG_H_FOOTER
#endif
