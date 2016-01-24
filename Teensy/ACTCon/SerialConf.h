struct SerialData_cs
{
  uint8_t ID;
  uint8_t len;
  void* ptr;
};

#define COMMAXLEN 30
SerialData_cs SerialData[] = 
{ 
  {
    'A',
    3,
    inputA
  },
  {
    'R',
    5,
    inputR
  },
  {
    'V',
    2,
    &vfzg
  },
  {
    'G',
    1,
    &gear
  }
};
