void setup() {
  //Setup the usb serial 
  Serial.begin(9600);
  //Set up the flora serial 
  Serial1.begin(9600);
}

     
void loop() {
  //If there is data comming in on the flora serial port
  if (Serial1.available()) {
    //Store it 
    char c = Serial1.read();
    //Print it back over the usb serial
    Serial.write(c);
  }
}
