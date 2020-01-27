#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS0.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>
// i2c
Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();
//Give the accelerometer a name
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);
//Declare names for all the led pins
int redLed1=9;
int redLed2=10;
int whiteLed1=12;
int whiteLed2=6;
void setup()
{
//Declare all the led pins as outputs
pinMode(redLed1,OUTPUT);
pinMode(redLed2,OUTPUT);
pinMode(whiteLed1,OUTPUT);
pinMode(whiteLed2,OUTPUT);
//Start the serial communication
Serial.begin(9600);

//Wait until the communication starts
while (!Serial);
// Setup both sensor
configureSensors();
if(!tsl.begin())
{
/* Cant find the TSL2561, check your connections */
Serial.print("Cant detect the TSL2561 detected Check your wiring");
while(1);
}
// Try to initialise the light sensor
if (!lsm.begin())
{
Serial.println("Can not find the sensor, Check your connections!");
}
}
void loop()
{
/* Get a new sensor event */
sensors_event_t event;
tsl.getEvent(&event);
/* If the lux goes below 70 then its dark and we can start using the
leds */
if (event.light>70){
lsm.read();
//If the hand is in the turn position light the white leds
if(lsm.accelData.x<-1000 && lsm.accelData.y<3000){
digitalWrite(whiteLed1,HIGH);
delay(500);
digitalWrite(whiteLed1,LOW);
digitalWrite(whiteLed2,HIGH);
delay(500);
digitalWrite(whiteLed2,LOW);
}
//If the hand is in the turn position light the red leds
if(lsm.accelData.y>1000 && lsm.accelData.x<0){
digitalWrite(redLed1,HIGH);

delay(500);
digitalWrite(redLed1,LOW);
digitalWrite(redLed2,HIGH);
delay(500);
digitalWrite(redLed2,LOW);
}
}
delay(500);
}
//Configure both the sensors
void configureSensors()
{
tsl.enableAutoRange(true);
tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_402MS);
lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_2G);
}
