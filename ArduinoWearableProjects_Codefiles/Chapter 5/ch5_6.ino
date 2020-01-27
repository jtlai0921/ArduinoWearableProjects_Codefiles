#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_GPS GPS(&Serial1);

#define OLED_RESET 6
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

void setup()
{
  // connect at 115200 so we can read the GPS fast enough and echo without dropping chars
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // Clear the buffer.
  display.clearDisplay();
  Serial.println("Testing GPS");

  // 9600 NMEA is the default baud rate for MTK3339
  GPS.begin(9600);

  // Set the update rate of the GPS
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ); 

  delay(1000);
  // Ask for firmware version
  Serial1.println(PMTK_Q_RELEASE);
}

uint32_t timer = millis();
void loop() 
{
  // read data from the GPS 
  char c = GPS.read();


  // if there is data we parse it...
  if (GPS.newNMEAreceived()) {
    //
    if (!GPS.parse(GPS.lastNMEA())) // this also sets the newNMEAreceived() flag to false
      return; // we can fail to parse a sentence in which case we should just wait for another
  }
  // if millis() or timer wraps around, we'll just reset it
  if (timer > millis()) timer = millis();

  // char 
  if (millis() - timer > 1000) {
    //
    timer = millis(); 
    display.clearDisplay();
    //
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print(GPS.hour, DEC);
    display.print(':');
    //
    if(GPS.minute<10){
      display.print('0');  
      display.print(GPS.minute, DEC); 
    }
    else{
      display.print(GPS.minute, DEC);
    } 
    display.print(':');
    //
    if(GPS.seconds<10){
      display.print('0');  
      display.print(GPS.seconds, DEC); 
    }
    else{
      display.print(GPS.seconds, DEC);
    }
    //
    display.print(" ");
    display.print(GPS.day, DEC); 
    display.print('/');
    display.print(GPS.month, DEC); 
    display.print("/20");
    display.println(GPS.year, DEC);
    //
   // if (GPS.fix) {  
      //
      display.print("Longitude:");
      display.print(GPS.latitude, 4); 
      display.println(GPS.lat);
      display.print("Latitude:");
      display.print(GPS.longitude, 4); 
      display.println(GPS.lon);
      //
      display.print("Speed:"); 
      display.print(GPS.speed);
      display.print(" Alt:");
      display.println(GPS.altitude); 
  //  }   
    //
    display.display();

  }
}



