void startupTest_ini()
{
  startupTest_act = true;
}

void startupTest_cyclic()
{
  const short stepsize = 5;
  static bool cycleup = true;
  if(vfzg<VMAX && cycleup)
  {
    rpm+=stepsize;
    vfzg = rpm; 
  }
  else if(vfzg>0)
  {
    cycleup = false;
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
