int powerPin[]={
19,18,17,16,14,9,8,6,5,4,3};
int gndPins[]={
12,11,10};
int refreshRate=200;
void setup(){
for(int i=0; i<20;i++){
pinMode(i,OUTPUT);
}
//
for(int j=0;j<3;j++){
digitalWrite(gndPins[j],HIGH);
}
}
void loop(){
nightrider();
}
//
void nightrider()
{
/*Instead of starting to loop through the columns we loop through
the row*/
for(int i=0; i<11; i++){
//Then we loop through the column
for(int j=0; j<3; j++){
/*In order to perceive that the column is lit we need to loop it a few
times*/
for(int k=0; k<50; k++){
//Then we light the column

digitalWrite(powerPin[i],HIGH);
digitalWrite(gndPins[j],LOW);
delayMicroseconds(refreshRate);
digitalWrite(powerPin[i],LOW);
digitalWrite(gndPins[j],HIGH);
}
}
}
/*Once we have reached the end of the glasses we do the same thing
backward*/
for(int i=11; i>0; i--){
for(int j=3; j>0; j--){
for(int k=0; k<50; k++){
digitalWrite(powerPin[i],HIGH);
digitalWrite(gndPins[j],LOW);
delayMicroseconds(refreshRate);
digitalWrite(powerPin[i],LOW);
digitalWrite(gndPins[j],HIGH);
}
}
}
}
