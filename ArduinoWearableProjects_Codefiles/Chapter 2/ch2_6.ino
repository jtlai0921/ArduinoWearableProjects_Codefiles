//Import the necessary libraries
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
/*Set the magnetometer sensitivity where the range can be changed to
4GAUSS, 8GAUSS or 12GAUSS*/
lsm.setupMag(lsm.LSM9DS0_MAGGAIN_2GAUSS);
/*Setup the gyroscope sensitivity where the range can be changed
500DPS or 2000DPS*/
lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_245DPS);
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
//Get data from the sensors
lsm.read();
//Print the accelrometer sensor data to the serial monitor
Serial.print("Accel X: "); Serial.print((int)lsm.accelData.x);
Serial.print(" ");
Serial.print("Y: "); Serial.print((int)lsm.accelData.y);
Serial.print(" ");
Serial.print("Z: "); Serial.println((int)lsm.accelData.z);
Serial.print(" ");
//Print the compass sensor data to the serial monitor
Serial.print("Compass X: "); Serial.print((int)lsm.magData.x);
Serial.print(" ");
Serial.print("Y: "); Serial.print((int)lsm.magData.y);
Serial.print(" ");
Serial.print("Z: "); Serial.println((int)lsm.magData.z);
Serial.print(" ");
//Print the gyro sensor data to the serial monitor
Serial.print("Gyro X: "); Serial.print((int)lsm.gyroData.x);
Serial.print(" ");
Serial.print("Y: "); Serial.print((int)lsm.gyroData.y);
Serial.print(" ");
Serial.print("Z: "); Serial.println((int)lsm.gyroData.z);
Serial.println(" ");
//wait for a bit
delay(200);
}
