#include <Servo.h> 
//Create servo object  
Servo myservo;  
  
void setup() 
{ 
  //Name the signal pin 
  myservo.attach(9);  
} 
 
 
void loop() 
{ 
    //Rotate the motor from position 0 to 180 degrees                       
    myservo.write(0);              
    delay(1000);                      
    myservo.write(180);              
    delay(1000);   
} 

