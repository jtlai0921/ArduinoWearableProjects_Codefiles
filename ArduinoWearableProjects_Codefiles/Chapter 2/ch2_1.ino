//variable to store the analog pin
int bendSensor = 10;

void setup(){
//Start the serial communication
Serial.begin(9600);
}
void loop(){
//Save the data from the sensor into storeData
int storeData=analogRead(bendSensor);
//Print the data and add a new line
Serial.println(storeData);
//Give the computer some time to receive the data
delay(200);
}
