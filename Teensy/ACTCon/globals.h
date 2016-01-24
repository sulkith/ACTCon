
char inputA[3]; //SignalsConversions --> ComStack
char inputR[5]; //SignalsConversions --> ComStack
uint16_t vfzg; //SignalsConversions --> ComStack
char gear[2]; //SignalsConversions --> ComStack
uint8_t abstc; //SignalsConversions --> ComStack
uint32_t curlaptime; //SignalsConversions --> ComStack
uint32_t lastlaptime; //SignalsConversions --> ComStack

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
