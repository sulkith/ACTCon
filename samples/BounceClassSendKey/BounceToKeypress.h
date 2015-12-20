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
#include <Bounce.h>
#include <usb_keyboard.h>
class BounceToKeypress
{
  private:
    const int pin;
    const bool highActive;
    const int modifier;

    const int key1;
    const int key2;
    const int key3;
    const int key4;
    const int key5;
    bool keyActive = false;
    Bounce bouncer;
  public:
    BounceToKeypress(int _pin, bool _highActive, int _modifier, int _key1, int _key2 = 0, int _key3 = 0, int _key4 = 0, int _key5 = 0):
      pin(_pin), highActive(_highActive), modifier(_modifier), key1(_key1), key2(_key2), key3(_key3), key4(_key4), key5(_key5), bouncer(pin, 5)
    {}
    void update()
    {
      if ( bouncer.update() ) {
        if ( bouncer.read() == highActive) {
          Keyboard.set_modifier(modifier);
          Keyboard.send_now();
          Keyboard.set_key1(key1);
          Keyboard.set_key2(key2);
          Keyboard.set_key3(key3);
          Keyboard.set_key4(key4);
          Keyboard.set_key5(key5);
          Keyboard.send_now();
          keyActive = true;
        }
      }
    }
    void release()
    {
      if (keyActive)
      {
        Keyboard.set_key1(0);
        Keyboard.set_key2(0);
        Keyboard.set_key3(0);
        Keyboard.set_key4(0);
        Keyboard.set_key5(0);
        Keyboard.send_now();
        Keyboard.set_modifier(0);
        Keyboard.send_now();
        keyActive = false;
      }
    }
};
