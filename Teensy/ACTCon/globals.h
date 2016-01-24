
char inputA[3]; //SignalsConversions --> ComStack
char inputR[5]; //SignalsConversions --> ComStack
uint16_t vfzg; //SignalsConversions --> ComStack
char gear; //SignalsConversions --> ComStack

int percentage; //SignalsConversions --> ForceFeedback

int rpm; //SignalsConversions --> rpm, rpmDisplayWS2812
char vfzg_ca[4] = "000"; ////SignalsConversions --> ST7753_Display
long maxrpm; //rpm --> rpmDisplayWS2812
int rpmprc10; //rpm --> rpmDisplayWS2812
