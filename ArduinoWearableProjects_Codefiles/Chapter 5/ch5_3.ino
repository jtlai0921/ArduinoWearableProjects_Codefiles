#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//Make sure to set the resetpin to the one you are using 
#define OLED_RESET 6
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
//Variables for the clock 
int s=0;
int m=0;
int h=0;

void setup()   {                
  Serial.begin(9600);

  //initialize with the I2C addr 0x3C (for the 128x32)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  

}


void loop() {
  s++;
  //
  display.clearDisplay();
  //
  display.setTextSize(3);
  //
  display.setTextColor(WHITE);
  //
  display.setCursor(0,0);
  //
  display.print(h);
  display.print(":");
  display.print(m);
  display.print(":");
  display.print(s);
  //
  if(s>59){
    s=0;
    m++; 
  }
  if(m>59){
    m=0;
    h++; 
  }
  if(h>23){
    h=0;
  }
  //
  display.display(); 
  //
  delay(1); 
}





