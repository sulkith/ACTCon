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
char inputA[3]; //SignalsConversions --> ComStack
char inputR[5]; //SignalsConversions --> ComStack
uint16_t vfzg; //SignalsConversions --> ComStack
char gear[2]; //SignalsConversions --> ComStack
uint8_t abstc; //SignalsConversions --> ComStack
uint32_t curlaptime; //SignalsConversions --> ComStack
uint32_t lastlaptime; //SignalsConversions --> ComStack
#define gForceIdxFrontal 0
#define gForceIdxVertical 1
int16_t gForce[2]; //SignalsConversions --> ComStack

int percentage; //SignalsConversions --> ForceFeedback

int rpm; //SignalsConversions --> rpm, rpmDisplayWS2812
char vfzg_ca[4] = "000"; ////SignalsConversions --> ST7753_Display
long maxrpm; //rpm --> rpmDisplayWS2812
int rpmprc10; //rpm --> rpmDisplayWS2812
char curlaptimetext[10] = " 00:00:00"; //SignalsConversions --> ST7753_Display
char lastlaptimetext[10] = " 00:00:00"; //SignalsConversions --> ST7753_Display

enum DriverAssistance_t
{
  off = 0,
  on = 1,
  actv = 3
};
DriverAssistance_t ABS;
DriverAssistance_t TC;
