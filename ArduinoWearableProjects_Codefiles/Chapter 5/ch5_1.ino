#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 6
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 


void setup()   {                
  Serial.begin(9600);

  //initialize with the I2C addr 0x3C (for the 128x32) 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 

}


void loop() {
    display.clearDisplay();
    display.drawPixel(random(0,128), random(0,32), WHITE);
    display.display();
    delay(100); 
}




