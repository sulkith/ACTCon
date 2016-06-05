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
/* * A0 -> WHITE      --> show Damage Display
 * A1 -> KEY-Switch --> T15 Sim
 * A2 -> YELLOW     --> ABS
 * A3 -> BLUE       --> TC * 14 -> RED        --> Reset
 *  2 -> GREEN      --> Toggle Player names
 *
 * NC -> BLACK
 */

#define DIGITAL_INPUT_CONFIG_TYPES
#include "configTypes.h"

digitalInputPin_t digitalInputPins[] =
{
  ACTION_KEYBOARD_PIN_KEY_1_2_3_DEBOUNCING(A3, KEY_LEFT_CTRL, 't', 0, 3) //TC
  ACTION_KEYBOARD_PIN_KEY_1_2_3_DEBOUNCING(A2, KEY_LEFT_CTRL, 'a', 0, 3) //ABS
  ACTION_KEYBOARD_PIN_KEY_1_2_3_DEBOUNCING( 2, KEY_LEFT_CTRL, 'l', 0, 3) //show Player Names
  ACTION_KEYBOARD_PIN_KEY_1_2_3_DEBOUNCING(A0, KEY_LEFT_CTRL, 'j', 0, 3) //show Player Names

  ACTION_RESET_PIN_DEBOUNCING(14, 5)
};
