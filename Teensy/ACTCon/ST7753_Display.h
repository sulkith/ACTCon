TFT TFTscreen = TFT(ST7753_Display_CS, ST7753_Display_DC, ST7753_Display_RST);

// char array to print to the screen
char sensorPrintout[4];
void ST7735_Display_DrawCar()
{
  TFTscreen.stroke(255, 0, 0);
  TFTscreen.rect(35,80,10,16);
  TFTscreen.rect(80,80,10,16);
  TFTscreen.line(45,88,80,88);
  TFTscreen.rect(35,140,10,16);
  TFTscreen.rect(80,140,10,16);
  TFTscreen.line(45,148,80,148);
  TFTscreen.line(47,156,57,80);
  TFTscreen.line(78,156,68,80);
  TFTscreen.line(68,80,57,80);
  TFTscreen.line(78,156,47,156);    
}
void ST7735_Display_DrawGrid()
{
  TFTscreen.stroke(255, 0, 0);
  TFTscreen.line(77,56,128,56);
  TFTscreen.line(0,76,77,76);
  TFTscreen.line(77,56,77,120);
  TFTscreen.line(0,120,128,120);
}
void ST7735_Display_ini()
{
  TFTscreen.begin();
  TFTscreen.setRotation(0);
  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);
  ST7735_Display_DrawGrid();
  // write the static text to the screen
  // set the font color to white
  TFTscreen.stroke(255, 255, 255);
  TFTscreen.setTextSize(2);
  TFTscreen.text("km/h", 5, 60);
}

//RED = TFTscreen.stroke(0, 0, 255);
//YELLOW = TFTscreen.stroke(0, 255, 255);
#define RED 0,0,255
#define YELLOW 0,255,255
#define GREEN 0,255,0

void ST7735_Display_cyclic()
{
  const uint8_t Vx = 5;
  const uint8_t Vy = 5;
  const uint8_t ABSx = 5;
  const uint8_t ABSy = 80;
  const uint8_t TCx = ABSx;
  const uint8_t TCy = 100;
  const uint8_t Gearx = 83;
  const uint8_t Geary = 60;
  const uint8_t cltx = 5;
  const uint8_t clty = 125;
  const uint8_t lltx = cltx;
  const uint8_t llty = 145;
  
  static char vfzg_ca_old[4];
  static char gearold[2] = " ";
  //Print v
  char vfzgMask[] = "   ";
  uint8_t differences = 0;
  TFTscreen.setTextSize(7); 
  for(uint8_t i = 0; i< 3;++i)
  {
    if(vfzg_ca_old[i] != vfzg_ca[i])
    {
      vfzgMask[i] = vfzg_ca_old[i];
      differences = 1;
    }
  }
  if(differences !=0)
  {
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.text(vfzgMask, 5, 5);
    TFTscreen.stroke(255, 255, 255);
    TFTscreen.text(vfzg_ca, 5, 5);
    memcpy(vfzg_ca_old,vfzg_ca,4);
  }
  TFTscreen.setTextSize(8); 
  if(gear[0] != gearold[0])
  {
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.text(gearold, Gearx, Geary);
    gearold[0] = gear[0];

  }
  if(rpmprc10>900)
    TFTscreen.stroke(0, 0, 255);
  else if(rpmprc10>800)
    TFTscreen.stroke(0, 255, 255);
  else
    TFTscreen.stroke(255, 255, 255);
  TFTscreen.text(gear, Gearx, Geary);
  
  TFTscreen.setTextSize(2); 
  if(ABS == off)
    TFTscreen.stroke(RED);
  if(ABS == on)
    TFTscreen.stroke(GREEN);
  if(ABS == actv)
    TFTscreen.stroke(YELLOW);
  TFTscreen.text("ABS", ABSx, ABSy);
  if(TC == off)
    TFTscreen.stroke(RED);
  if(TC == on)
    TFTscreen.stroke(GREEN);
  if(TC == actv)
    TFTscreen.stroke(YELLOW);
  TFTscreen.text("DTC", TCx, TCy);
  
  TFTscreen.stroke(255,255,255);
  //               " 00:00:00";
  char cltMask[] = "         ";
  static char curlaptimetext_old[9];
  differences = 0;
  for(uint8_t i = 0; i< 9;++i)
  {
    if(curlaptimetext_old[i] != curlaptimetext[i])
    {
      cltMask[i] = curlaptimetext_old[i];
      differences = 1;
    }
  }
  if(differences !=0)
  {
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.text(cltMask, cltx, clty);
    TFTscreen.stroke(255, 255, 255);
    TFTscreen.text(curlaptimetext, cltx, clty);
    memcpy(curlaptimetext_old,curlaptimetext,9);
  }

  char lltMask[] = "         ";
  static char lastlaptimetext_old[9];
  differences = 0;
  for(uint8_t i = 0; i< 9;++i)
  {
    if(lastlaptimetext_old[i] != lastlaptimetext[i])
    {
      lltMask[i] = lastlaptimetext_old[i];
      differences = 1;
    }
  }
  if(differences !=0)
  {
    TFTscreen.stroke(0, 0, 0);
    TFTscreen.text(lltMask, lltx, llty);
    TFTscreen.stroke(255, 255, 255);
    TFTscreen.text(lastlaptimetext, lltx, llty);
    memcpy(lastlaptimetext_old,lastlaptimetext,9);
  }
  
  //TFTscreen.text("00:00:00", 17, 145);

  

}
