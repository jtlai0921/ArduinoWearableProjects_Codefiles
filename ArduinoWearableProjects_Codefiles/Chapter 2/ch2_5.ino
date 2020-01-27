/*Import the necessary libraries. Wire.h and SPI.h are included in the
IDE and does not need to be downloaded*/
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS0.h>
#include <Adafruit_Sensor.h>
// set up i2c
Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();
void setupSensor()

{
/*Set the accelerometer range where the range can be changed to
4G,8G or 16G*/
lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_2G);
//lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_4G);
//lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_6G);
//lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_8G);
//lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_16G);
}
void setup()
{
//Wait for communication to start
while (!Serial);
//Set the baud rate
Serial.begin(9600);
//Print message to serial monitor
Serial.println("Starting communication");
// Try to initialise and warn if we couldn't detect the chip
if (!lsm.begin())
{
Serial.println("Something went wrong, check you connections");
while (1);
}
Serial.println("Connection established");
Serial.println("");
Serial.println("");
}
void loop()
{
//Get data from the sensor
lsm.read();
//Print the accelrometer sensor data to the serial monitor
Serial.print("Accel X: ");
Serial.print((int)lsm.accelData.x);
Serial.print(" ");
Serial.print("Y: ");
Serial.print((int)lsm.accelData.y);
Serial.print(" ");
Serial.print("Z: ");
Serial.println((int)lsm.accelData.z);
Serial.print(" ");
delay(200);
}
