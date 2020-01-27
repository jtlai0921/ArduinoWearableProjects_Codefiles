//Variable to store the pin
int ldrSensor = 10;
void setup(){
//Start the serial communication
Serial.begin(9600);
}
void loop(){
//Save the data from the sensor into storeData
int storeData=analogRead(ldrSensor);
//Re-map storeData to a new range of values
int mapValue=map(storeData,130,430,0,2000);
//Print the re-maped value
Serial.println(mapValue);
//Give the computer some time to print
delay(200);
}
