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
void ST7735_Display_ini()
{
  TFTscreen.begin();
  TFTscreen.setRotation(0);
  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);
  ST7735_Display_DrawCar();
  // write the static text to the screen
  // set the font color to white
  TFTscreen.stroke(255, 255, 255);
  TFTscreen.setTextSize(2);
  TFTscreen.text("km/h", 75, 60);
}


void ST7735_Display_cyclic()
{
  static char vfzg_ca_old[4];
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


  
  /*static int counter = 0;
  counter++;
  if(counter %250 == 0)
  {
  //TFTscreen.background(0, 0, 0);
  
  TFTscreen.stroke(255, 255, 255);
  String sensorVal = String(250);
  sensorVal.toCharArray(sensorPrintout, 4);
  TFTscreen.setTextSize(7);
  TFTscreen.stroke(255, 255, 255);
  TFTscreen.text(sensorPrintout, 5, 5);
  TFTscreen.stroke(255, 255, 255);
  sensorPrintout[2]++;
  TFTscreen.text(sensorPrintout, 5, 5);
  
  
  // write the text to the top left corner of the screen*/
  
  TFTscreen.setTextSize(2);
  char temp[] = "90";
  char temp2[] = "40";
  char temp3[] = "60";
  TFTscreen.stroke(0, 0, 255);
  TFTscreen.text(temp, 100, 80);
  TFTscreen.stroke(0, 255, 0);
  TFTscreen.text(temp2, 5, 80);
  TFTscreen.stroke(0, 255, 255);
  TFTscreen.text(temp3, 100, 140);
  TFTscreen.text(temp3, 5, 140);

  

}
