#include <SPI.h>
#include <EEPROM.h>
#include <boards.h>
#include <RBL_nRF8001.h>
unsigned char buf[16] = {
  0};
unsigned char len = 0;

int samples=50; 
float sampleX; 
float sampleY; 
float sampleZ; 
int acc=20; 
float lastX=0; 
float lastY=0; 
float lastZ=0; 
float v;
float cV;
void setup(){
  // Init. and start BLE library.
  ble_begin();
  Serial.begin(57600);
}

void loop(){

  float x=calibrateX();
  float y=calibrateY();
  float z=calibrateZ();

  if ( ble_connected() ){
    if(x<lastX-acc){
      ble_write('R'); 
      ble_write('i');
      ble_write('g');
      ble_write('h');
      ble_write('t');
      ble_write(' ');
    }
    if(x>lastX+acc){
      ble_write('L'); 
      ble_write('e');
      ble_write('f');
      ble_write('t');
      ble_write(' ');
    }
    if(y<lastY-acc){
      ble_write('B'); 
      ble_write('a');
      ble_write('c');
      ble_write('k');
      ble_write(' ');
    }
    if(y>lastY+acc){
      ble_write('F'); 
      ble_write('o');
      ble_write('r');
      ble_write('w');
      ble_write('a'); 
      ble_write('r');
      ble_write('d');
      ble_write(' ');
    }
    if(z<lastZ-acc){
      ble_write('U'); 
      ble_write('p');
      ble_write(' ');
    }
    if(z>lastZ+acc){
      ble_write('D'); 
      ble_write('o');
      ble_write('w'); 
      ble_write('n');
      ble_write(' '); 
    }
  }
  ble_do_events();
  lastX=x; 
  lastY=y; 
  lastZ=z; 
}

float calibrateX(){

  for(int i=0;i<samples;i++){
    sampleX += analogRead(2);  
  }
  sampleX = sampleX/samples; 

  return sampleX; 
}
float calibrateY(){

  for(int i=0;i<samples;i++){
    sampleY += analogRead(1);  
  }
  sampleY = sampleY/samples; 

  return sampleY; 
}
float calibrateZ(){

  for(int i=0;i<samples;i++){
    sampleZ += analogRead(1);  
  }
  sampleZ = sampleZ/samples; 

  return sampleZ; 
}




