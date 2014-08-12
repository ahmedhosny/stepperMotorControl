int myDiecrtion = 3;
int mySteps = 2;
int myInput = 0;

void setup() {
pinMode(myDiecrtion, OUTPUT);
pinMode(mySteps, OUTPUT);
Serial.begin(9600);
while(!Serial);
Serial.println("//WELCOME BOSS//");
Serial.println("//Beaders Stepper Control Console//");

}

void loop(){
  if(Serial.available()){
  myInput = Serial.parseInt();
  }
  myProgram();
}
// All odd values of myInput move DOWN, All even values move UP.
void myProgram(){
  if(myInput == 1){
    Serial.println("1:Moving DOWN 2mm");
// Low is clockwise ie pushes the wheel down
  digitalWrite(myDiecrtion, LOW);     
  delay(100);
// The count here is in microsteps. 1 step = 0.04mm of linear movement = 8 microsteps... ie 200microsteps is 1 mm of movement.
  for (int i = 0; i<400; i++){
    digitalWrite(mySteps, LOW);  
    digitalWrite(mySteps, HIGH); 
    //The smaller this value, the faster the motion. Can potentially use a large value for varying depth along a long line
    delayMicroseconds(500); 
  }  
myInput = 0;
  }
  if(myInput == 2){
  // High is counter-clockwise ie pushes the wheel up
      Serial.println("2:Moving UP 2mm");
      digitalWrite(myDiecrtion, HIGH);    
  delay(100);
  for (int i = 0; i<400; i++){
    digitalWrite(mySteps, LOW);  
    digitalWrite(mySteps, HIGH); 
    delayMicroseconds(500);     
  } 
myInput = 0;
  }
}
