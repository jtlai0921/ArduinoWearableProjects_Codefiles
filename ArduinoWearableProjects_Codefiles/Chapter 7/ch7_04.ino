
#include <Adafruit_GFX.h>
#include <Adafruit_SharpMem.h>
#include <SPI.h>
#include <EEPROM.h>
#include <boards.h>
#include <RBL_nRF8001.h>

#define SCK 10
#define MOSI 11
#define SS 13

Adafruit_SharpMem display(SCK, MOSI, SS);

#define BLACK 0
#define WHITE 1
unsigned char buf[16] = {0};
unsigned char len = 0;

void setup(void) 
{
    ble_begin();
  Serial.begin(57600);
  // start & clear the display
  display.begin();
  display.clearDisplay();

  // text display tests
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Redy to recive");
 
  delay(2000);
}

void loop(void) 
{
    if ( ble_available() )
  {
    display.clearDisplay(); 
    display.setTextSize(2);
      display.setTextColor(BLACK);
      display.setCursor(5,0);
    while ( ble_available() ){
      
     char printChar=ble_read();
     if(printChar==' '){
       display.println();
     }else{
      display.print(printChar);  
     }
       display.refresh();
    }
      
   // Serial.println();
  }
    ble_do_events();
  display.refresh();
  delay(500);
}



