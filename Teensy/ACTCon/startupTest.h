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
void startupTest_ini()
{
  startupTest_act = T15_st;
}

void startupTest_cyclic()
{
  const short stepsize = 12;
  static bool cycleup = true;
  static uint8_t hold = 10;
  static bool T15_st_old = T15_st;
  if (T15_st_old != T15_st)
  {
    startupTest_act = T15_st;
    T15_st_old = T15_st;
    cycleup = true;
    rpm = 0;
    hold = 10;
    vfzg = 0;
  }

  if (startupTest_act)
  {
    if (rpm < VMAX && cycleup)
    {
      rpm += stepsize;
      vfzg = rpm;
    }
    else if (hold > 0)
    {
      cycleup = false;
      hold--;
    }
    else if (rpm > 0)
    {
      rpm -= stepsize;
      vfzg = rpm;
    }
    else
    {
      vfzg = 0;
      rpm = 0;
      startupTest_act = false;
    }
  }
}
