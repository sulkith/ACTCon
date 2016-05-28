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

const int digitalInputPinActionslenght = sizeof(digitalInputPins) / sizeof(digitalInputPin_t);

void digitalInput_ini()
{
  for (int i = 0; i < digitalInputPinActionslenght; ++i)
  {
    digitalInputPins[i].cntr = 0;
    pinMode(digitalInputPins[i].pinID, INPUT_PULLUP);

  }
}
uint8_t digitalInput_doAction(uint8_t index)
{
  switch (digitalInputPins[index].actionType)
  {
    case reset:
      reIniSystem();
      return 1;
    case keyboardPress:
      KeyboardOutput_Press(digitalInputPins[index].param1, digitalInputPins[index].param2, digitalInputPins[index].param3);
      break;
    case none:
    default:
      break;
  }
  return 0;
}
void digitalInput_cyclic()
{
  for (int i = 0; i < digitalInputPinActionslenght; ++i)
  {
    if (digitalRead(digitalInputPins[i].pinID) == LOW)
    {
      if (digitalInputPins[i].cntr < abs(digitalInputPins[i].debouncing))
      {
        digitalInputPins[i].cntr++;
        //Serial.print("incrementing Counter for ");
        //Serial.println(i);
      }
      else
      {
        if (digitalInputPins[i].cntr != 255)
        {
          //Serial.print("doing Action for ");
          //Serial.println(i);
          if (digitalInput_doAction(i) == 1)return; //return to reset System
          digitalInputPins[i].cntr = 255;
        }
      }
    }
    else
    {
      if (digitalInputPins[i].cntr == 255)
        digitalInputPins[i].cntr = 0;
      if (digitalInputPins[i].cntr > 0)
      {
        digitalInputPins[i].cntr--;
        //Serial.print("decrementing Counter for ");
        //Serial.println(i);
      }
    }

  }
}
