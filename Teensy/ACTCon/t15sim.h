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
enum T15SimState_t
{
  not_avaliable,
  T15_on,
  T15_on_deb,
  T15_off,
  T15_off_deb
} T15SimState;

#define T15Sim_DebounceVal 6
uint8_t T15Sim_cntr;
void T15Sim_ini()
{
#ifdef T15Sim_PIN
  pinMode(T15Sim_PIN, INPUT_PULLUP);
  T15Sim_cntr = 0;
  if (digitalRead(T15Sim_PIN) == LOW)
  {
    T15SimState = T15_on;
    T15_st = true;
  }
  else
  {
    T15SimState = T15_off;
    T15_st = false;
  }
#else
  T15SimState = not_avaliable;
  T15_st = true;
#endif
}

#ifdef T15Sim_PIN
void T15Sim_cyclic()
{
  bool T15_State = (digitalRead(T15Sim_PIN) == LOW);
  switch (T15SimState)
  {
    case T15_on:
      if (T15_State == false)
      {
        T15SimState = T15_off_deb;
        T15Sim_cntr = T15Sim_DebounceVal;
      }
      break;
    case T15_off:
      if (T15_State == true)
      {
        T15SimState = T15_on_deb;
        T15Sim_cntr = T15Sim_DebounceVal;
      }
      break;
    case T15_on_deb:
      if (T15_State == false)
      {
        T15SimState = T15_off;
        T15_st = false;
      }
      else if (T15Sim_cntr == 0)
      {
        T15SimState = T15_on;
        T15_st = true;
      }
      else
        T15Sim_cntr--;
      break;
    case T15_off_deb:
      if (T15_State == true)
      {
        T15SimState = T15_on;
        T15_st = true;
      }
      else if (T15Sim_cntr == 0)
      {
        T15SimState = T15_off;
        T15_st = false;
      }
      else
        T15Sim_cntr--;
      break;
  }
}
#else
#define T15Sim_cyclic()
#endif
