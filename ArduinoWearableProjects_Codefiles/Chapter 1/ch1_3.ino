int led = 12;
void setup() {
pinMode(led, OUTPUT);
}
void loop() {
for(int i=0; i<5; i++){
blinkLed(1000); //call the function and add the delay time
}
for(int j=0; j<5; j++){
blinkLed(500); //call the function and add the delay time
}
for(int k=0; k<5; k++){
blinkLed(100); //call the function and add the delay time
}
}
/*declares the function blinkLed and adds a parameter that needs to be
included with the use of the function*/
void blinkLed(int delayTime){
digitalWrite(led, HIGH); //turn the led on
delay(delayTime); //wait for a bit
digitalWrite(led, LOW); //turn the led off
delay(delayTime); //wait some more
}
