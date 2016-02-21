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

#ifdef DIGITAL_INPUT_CONFIG_TYPES
enum digitalInputAction
{
  none,
  reset,
  keyboardPress
};
struct digitalInputPin_t
{
  const uint8_t pinID;
  const digitalInputAction actionType;
  const uint8_t param1;
  const uint8_t param2;
  const uint8_t param3;
  const int8_t debouncing;
  uint8_t cntr;
};
#define ACTION_KEYBOARD_PIN_KEY_1_2_3_DEBOUNCING(pin,k1,k2,k3,d) {pin,keyboardPress,k1,k2,k3,d,0},
#define ACTION_RESET_PIN_DEBOUNCING(pin,d) {pin,reset,0,0,0,d,0},

#undef DIGITAL_INPUT_CONFIG_TYPES
#endif

#ifdef CONFIG_H_FOOTER


#undef CONFIG_H_FOOTER
#endif
