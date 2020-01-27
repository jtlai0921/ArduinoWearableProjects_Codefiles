#include <Wire.h>
#include <SPI.h>
#include <Adafruit_PN532.h>
#include <Servo.h> 

// Define the I2C pins 
#define PN532_IRQ   (2)
#define PN532_RESET (3)  // Not connected by default on the NFC Shield
//Connect the shield I2C connection:
Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);
//Create servo object  
Servo myservo;  


void setup(void) {
  Serial.begin(115200);
  Serial.println("Starting the NFC shield");
  nfc.begin();
  //Check the firmware version of the shield 
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print("Cant find the shield, check you connection");
    while (1); // wait 
   //Name the signal pin 
  myservo.attach(9);  
    myservo.write(0);              
    delay(1000);                      


  }
  
  // Got ok data, print it out!
  Serial.println("Connected"); 
  //Print out the firmware version 
  Serial.print("Firmware ver. "); 
  Serial.print((versiondata>>16) & 0xFF, DEC); 
  Serial.print('.'); Serial.println((versiondata>>8) & 0xFF, DEC);
  
  // Set the number of retry attempts to read from a card
  nfc.setPassiveActivationRetries(0xFF);
  
  // configure the board to read RFID tags
  nfc.SAMConfig();
  
  Serial.println("Waiting for a tag");
}

void loop(void) {
  //Decalre a variable to store state 
  boolean success;
  //Buffer to store the ID of the card 
  byte uid[] = { 0, 0, 0, 0, 0, 0, 0 };	
  //Keychain that stores the card information 
  byte keyID[] = {39, 246, 64, 175}; 
  int counter=0; 
  //Variable to store the length of the ID
  byte uidLength;				
  
// Waits for and tag and reads the length of the package and the //ID 
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength);
  
  if (success) {
    
    for (uint8_t i=0; i < uidLength; i++) 
    {
      if(uid[i]==keyID[i]){
       counter++; 
      }

    }
    Serial.println(); 
    //If 4 out of 4 i right we unlock 
    if(counter==4){
      Serial.println("Open door");
      myservo.write(180);  
      //Keep the door open for 20sec
      delay(2000);
      Serial.println("Close door");
      myservo.write(0);         
     //if not the card is wrong 
    }else{
      Serial.println("wrong card try again");
    }
	// Wait 1 second before continuing
	delay(1000);
  }

}

