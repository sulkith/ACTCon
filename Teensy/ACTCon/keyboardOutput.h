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
uint8_t keyboardOutput_key1;
uint8_t keyboardOutput_key2;
uint8_t keyboardOutput_key3;
enum keyboardOutputState_t
{
  idle,
  key2_state,
  key3_state,
  releaseKeys
} keyboardOutputState;
void keyboardOutput_ini()
{
  Keyboard.begin();
  keyboardOutputState = idle;
}
void KeyboardOutput_SchedulerAction()
{
  switch (keyboardOutputState)
  {
    case key2_state:
      Keyboard.press(keyboardOutput_key2);
      Serial.print("pushed Key2 @ ");
      Serial.println(millis());
      if (keyboardOutput_key3 == 0)
        keyboardOutputState = releaseKeys;
      else
        keyboardOutputState = key3_state;
      break;
    case key3_state:
      Serial.print("pushed Key3 @ ");
      Serial.println(millis());
      Keyboard.press(keyboardOutput_key3);
      keyboardOutputState = releaseKeys;
      break;
    case releaseKeys:
      Serial.print("Released Keys @ ");
      Serial.println(millis());
      Keyboard.releaseAll();
      //if (keyboardOutput_key3 != 0)Keyboard.release(keyboardOutput_key3);
      //if (keyboardOutput_key2 != 0)Keyboard.release(keyboardOutput_key2);
      //if (keyboardOutput_key1 != 0)Keyboard.release(keyboardOutput_key1);
      keyboardOutputState = idle;
      break;
    case idle:
    default:
      break;
  }
}
void KeyboardOutput_Release()
{
  Keyboard.releaseAll();
}
void KeyboardOutput_Press(uint8_t key1 , uint8_t key2, uint8_t key3)
{
  Serial.print("pushed Key1 @ ");
  Serial.println(millis());
  Keyboard.press(key1);
  keyboardOutput_key1 = key1;
  keyboardOutput_key2 = key2;
  keyboardOutput_key3 = key3;
  if (key3 != 0) keyboardOutputState = key3_state;
  if (key2 != 0) keyboardOutputState = key2_state;
  else keyboardOutputState = releaseKeys;
  uint8_t delayTime = 0;
  if (key2 != 0)scheduleAction(&KeyboardOutput_SchedulerAction, 100);//key2
  if (key3 != 0)scheduleAction(&KeyboardOutput_SchedulerAction, 200);//key3
  scheduleAction(&KeyboardOutput_SchedulerAction, 300);//release
}

