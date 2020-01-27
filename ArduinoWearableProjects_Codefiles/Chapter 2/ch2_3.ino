//declare variables to store pin number
int pressureSensor=10;
int led=7;
void setup() {
//declare pin as an output
pinMode(led,OUTPUT);
Serial.begin(9600);
}
void loop() {
//read the input on analog pin 12:
int pressureValue = analogRead(pressureSensor);
//as long as the value is inbetween 500 and 700 keep on looping
while(pressureValue>500 && pressureValue<700){
//turn the led on
digitalWrite(led,HIGH);
//check so that the value
pressureValue = analogRead(pressureSensor);
}
//turn the led off
digitalWrite(led,LOW);
}
