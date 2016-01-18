void rpm_cyclic();
void rpm_ini()
{
  maxrpm=1000;
  rpm_cyclic(); //initializes rpmprc10
}
void rpm_cyclic()
{
  //find max rpm
  if (rpm > maxrpm) maxrpm = rpm;
  //TODO: Filter downshifts --> driving fullspeed in the 6th gear and dunshifting rapidly brings engine to 15000 rpm which is definately not maxrpm

  rpmprc10 = (rpm * 1000UL)/maxrpm;
}
