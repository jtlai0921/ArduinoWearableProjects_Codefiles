//declare variables to store pin numbers
int pressureSensor=12;
int led=13;
void setup() {
//declar pin as an output
pinMode(led,OUTPUT);
}
void loop() {
// read the input on analog pin 12:
int pressureValue = analogRead(pressureSensor);
//turn the led on
digitalWrite(led,HIGH);
//wait using the value from the sensor
delay(pressureValue);
//turn the led off
digitalWrite(led,LOW);
//Tturn the led on
delay(pressureValue);
}
