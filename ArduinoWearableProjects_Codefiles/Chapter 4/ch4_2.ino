/*Collect all the positive columns pins in one array. You need to
make sure that these pins correspond to the direction you have placed
the columns in the glasses*/
int powerPin[]={
19,18,17,16,14,9,8,6,5,4,3};
/*Collect all the negative row pins in one array. Again make sure
they are added in the same order corresponding to the glasses*/
int gndPins[]={12,11,10};
//This is a two dimensional array that holds the pattern
int pattern[3][11] = {
{1,1,1,1,0,0,0,1,1,1,1 },
{0,1,1,0,0,0,0,1,0,0,1 },
{0,1,1,0,0,0,0,1,1,1,1 }
,
};
//Variable to store the refresh rate on the led display
int refreshRate=200;
void setup(){
//Declare all pins as outputs
Serial.begin(9600);
for(int i=0; i<20;i++){
pinMode(i,OUTPUT);
}
//turn all the gnd ports High to keep them blocked
for(int j=0;j<3;j++){
digitalWrite(gndPins[j],HIGH);
}
}
void loop(){
//Run the pattern function
displayPattern();
}
/*Function that runs through all the positions in the pattern array*/
void displayPattern()
{
for (byte x=0; x<3; x++) {
for (byte y=0; y<11; y++) {
int data =pattern[x][y];
//If the data stored in the array is 1 turn on the led
if (data==1) {
digitalWrite(powerPin[y],HIGH);
digitalWrite(gndPins[x],LOW);
delayMicroseconds(refreshRate);
digitalWrite(powerPin[y],LOW);
digitalWrite(gndPins[x],HIGH);
}
//If it is something else turn the led off
else {

digitalWrite(powerPin[y],LOW);
digitalWrite(gndPins[x],HIGH);
}
}
}
}
