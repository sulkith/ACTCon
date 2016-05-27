void startupTest_ini()
{
  startupTest_act = true;
}

void startupTest_cyclic()
{
  const short stepsize = 12;
  static uint8_t hold = 10;
  static bool cycleup = true;
  if(vfzg<VMAX && cycleup)
  {
    rpm+=stepsize;
    vfzg = rpm; 
  }
  else if(hold>0)
  {
      cycleup = false;
      hold--;
  }
  else if(vfzg>0)
  {
    rpm-=stepsize;
    vfzg = rpm;
  }
  else
  {
    vfzg = 0;
    rpm = 0;
    startupTest_act = false;
  }
}
