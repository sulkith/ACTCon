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
