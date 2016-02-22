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
#define ACTION_SCHEDULER_MAX_ACTIONS 5
struct scheduledAction
{
  long timeToExecute;
  void (*action)();
} actionSchedulerActions[ACTION_SCHEDULER_MAX_ACTIONS];

void scheduleAction(void (*_action)(), long delayInMs)
{
  for (uint8_t i = 0 ; i < ACTION_SCHEDULER_MAX_ACTIONS; ++i)
  {
    if(actionSchedulerActions[i].action == 0)
    {
        actionSchedulerActions[i].action = _action;
        actionSchedulerActions[i].timeToExecute = (millis() + delayInMs);
        //Serial.print("Schedule Action ");
        //Serial.print(millis());
        //Serial.print(" + ");
        //Serial.print(delayInMs);
        //Serial.print(" = ");
        //Serial.println(actionSchedulerActions[i].timeToExecute);
        break;
    }
  }
}

void actionScheduler_ini()
{
  for (uint8_t i = 0 ; i < ACTION_SCHEDULER_MAX_ACTIONS; ++i)
  {
      actionSchedulerActions[i].timeToExecute = 0;
      actionSchedulerActions[i].action = 0;
  }
}
void actionScheduler_cyclic()
{
  long currentTime = millis();
  for (uint8_t i = 0 ; i < ACTION_SCHEDULER_MAX_ACTIONS; ++i)
  {
    if((actionSchedulerActions[i].action != 0)&&(currentTime > actionSchedulerActions[i].timeToExecute))
    {
        actionSchedulerActions[i].action();
        actionSchedulerActions[i].action = 0;
    }
  }
}
