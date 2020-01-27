//Include the libraries needed
#include <Wire.h>
/*If you a missing the Adafruit sensor library have a look at chapet 2
for a link to the library and install instructions*/
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>
//Give the sensor a ID which in this case is 12345
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);
//Function to configure the sensor
void configureSensor()
{
/* This set the gain to auto, you can also manual set the gain to no
gain or 16x the gain.*/
tsl.enableAutoRange(true);
// To manually set the gain use the following commans
// tsl.setGain(TSL2561_GAIN_1X);
// tsl.setGain(TSL2561_GAIN_16X);
/* modifying the integration time gives you better a resolution on
you readings (402ms = 16-bit data) */
/*Faster reading but lower resolution
tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);
Medium speed and medium resolution tsl.setIntegrationTime(TSL2561_
INTEGRATIONTIME_101MS);
High resoulution but slow speed which we will be using for this
example*/
tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_402MS);
}
void setup()
{
//Start serial cummincation
Serial.begin(9600);
//Print test message
Serial.println("Light Sensor Test");
/* Initialise the sensor */
if(!tsl.begin())
{
/* There was a problem detecting the sensor check your wires */
Serial.print("Cant detect the TSL2561 detected Check yourwiring");
while(1);
}
/* Setup the sensor gain and integration time */
configureSensor();
}
void loop()
{
/* Get a new sensor event */
sensors_event_t event;
tsl.getEvent(&event);
/* If there is light display the results */
if (event.light)
{
Serial.print(event.light); Serial.println(" lux");
}
else
{
/* If there is no light */
Serial.println("Cant see anything..Show me some light");
}
delay(250);
}
