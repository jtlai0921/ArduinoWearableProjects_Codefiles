/*Collect all the positive columns pins in one array. You need to make
sure that these pins correspondto the direction you have placed the
columns in the glasses*/
int powerPin[]={
3,4,5,6,8,9,14,16,17,18,19};
/*Collect all the negative row pins in one array. Again make sure they
are added in the same order corresponding to the glasses*/
int gndPins[]={
10,11,12};
void setup(){
/*In order for the matrix to work we need to be able to control
our gnd lines in the matrix. The trick is to use all pins as output.
When we turn the gnd pins HIGH we will be able to block the ground
connection*/
for(int i=0; i<20;i++){
pinMode(i,OUTPUT);
}
//Turn all the gnd pins HIGH in order to keep all LEDs off
for(int j=0;j<3;j++){
digitalWrite(gndPins[j],HIGH);
}
}
void loop(){
//Run the function
looper();
}
void looper(){
/*In this function we run through all the LEDs using two for loops
starting by opening a gnd connection*/
for(int i=0; i<11;i++){
digitalWrite(powerPin[i],HIGH);
//Once a gnd pin is accessible we turn on one of the LEDs
for(int j=0;j<3;j++){
digitalWrite(gndPins[j],LOW);
delay(50);
digitalWrite(gndPins[j],HIGH);
delay(50);

}
digitalWrite(powerPin[i],LOW);
}
//Loop everything backwards
for(int i=10; i>=0;i--){
digitalWrite(powerPin[i],HIGH);
for(int j=3;j>=0;j--){
digitalWrite(gndPins[j],LOW);
delay(50);
digitalWrite(gndPins[j],HIGH);
delay(50);
}
digitalWrite(powerPin[i],LOW);
}
}
