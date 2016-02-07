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
void rpm_cyclic();
void rpm_ini()
{
  maxrpm=1000;
  rpm_cyclic(); //initializes rpmprc10
}
void rpm_cyclic()
{
  static int maxrpm_temp = maxrpm;
  static int maxrpm_deb = 0;
  
  //find max rpm
  if (rpm > maxrpm_temp)
  {
      maxrpm_temp = rpm;
      maxrpm_deb = 50;    
  }
  
  if(gear[0] == 'N')
  {
    maxrpm_deb--;  
  }
  else
  {
    maxrpm_temp = maxrpm;
    maxrpm_deb = 0;
  }
  
  if(maxrpm_deb == 1)
  {
      maxrpm = maxrpm_temp;
  }
  //TODO: Filter downshifts --> driving fullspeed in the 6th gear and dunshifting rapidly brings engine to 15000 rpm which is definately not maxrpm

  rpmprc10 = (rpm * 1000UL)/maxrpm;
}
