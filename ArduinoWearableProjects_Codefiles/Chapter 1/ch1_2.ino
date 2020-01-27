int led = 12; //declares a variable called led connected to pin 12
void setup() {
pinMode(led, OUTPUT); //declares led as an output pin
}
void loop() {
//start looping until the counter is bigger then 5
for(int i=0; i<5; i++){
digitalWrite(led, HIGH); //turn the led on
delay(1000); //wait for a bit
digitalWrite(led, LOW); //turn the led off
delay(1000); //wait some more
}
//start looping until the counter is bigger then 5
for(int j=0; j<5; j++){
digitalWrite(led, HIGH); //turn the led on
delay(500); //wait for a bit
digitalWrite(led, LOW); //turn the led off
delay(500); //wait some more
}
//start looping until the counter is bigger then 5
for(int k=0; k<5; k++){
digitalWrite(led, HIGH); //turn the led on
delay(100); //wait for a bit
digitalWrite(led, LOW); //turn the led off
delay(100); //wait some more
}
}
