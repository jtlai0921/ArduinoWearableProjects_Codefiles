int samples=50; 
float sampleX; 
float sampleY; 
float sampleZ; 
int acc=20; 
float lastX=0; 
float lastY=0; 
float lastZ=0; 
float degreeX=0; 
float degreeY=0; 
float degreeZ=0; 
float zeroX;
float zeroY;
float zeroZ;
void setup(){
  //
  Serial.begin(57600);
  //
  zeroX=calibrateX();
  zeroY=calibrateY();
  zeroZ=calibrateZ();
}

void loop(){
  //
  float x=calibrateX();
  float y=calibrateY();
  float z=calibrateZ();
  //
  degreeX=x-zeroX;
  degreeY=y-zeroY;
  degreeZ=z-zeroZ;

  delay(200); 
  Serial.println(degreeX);
  //
  if(x<lastX-acc){
    Serial.print("X Degrees: ");
    Serial.print(degreeX);
    Serial.println(" Moving right");  
  }
  if(x>lastX+acc){
    Serial.print("X Degrees: ");
    Serial.print(degreeX);
    Serial.println("Moving left");  
  }
  if(y<lastY-acc){
    Serial.print("Y Degrees: ");
    Serial.print(degreeY);
    Serial.println("Moving backwards");  
  }
  if(y>lastY+acc){
    Serial.print("Y Degrees: ");
    Serial.print(degreeY);
    Serial.println("Moving forwards");  
  }
  if(z<lastZ-acc){
    Serial.print("Z Degrees: ");
    Serial.print(degreeZ);
    Serial.println("Moving up");  
  }
  if(z>lastZ+acc){
    Serial.print("Z Degrees: ");
    Serial.print(degreeZ);
    Serial.println("Moving down");  
  }
  lastX=x; 
  lastY=y; 
  lastZ=z; 
}
//
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
    sampleZ += analogRead(0);  
  }
  sampleZ = sampleZ/samples; 

  return sampleZ; 
}





