#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS0.h>
#include <Adafruit_Sensor.h>
// i2c
Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();
void setupSensor()
{
//Set range of the accelerometer
lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_2G);
}
void setup()
{
//wait until serial starts
while (!Serial);
Serial.begin(9600);
// Try to initialise sensor and warn if it cant find it
if (!lsm.begin())
{
Serial.println("Cant find the sensor, Check your connections!");
while (1);
}
Serial.println("Found the sensor");
Serial.println("");
Serial.println("");
}
void loop()

{
//read the sensor
lsm.read();
if(lsm.accelData.x<0 && lsm.accelData.y<0){
Serial.println("Holding handlebar");
}
if(lsm.accelData.y>1000 && lsm.accelData.x<0){
Serial.println("Stopping");
}
if(lsm.accelData.x<-1000 && lsm.accelData.y<3000){
Serial.println("Turning");
}
delay(500);
}
