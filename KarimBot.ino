

int trigPin = 9;
int echoPin = 10;
int LBack = 4;
int RBack = 7;
int LMotor = 5;
int RMotor = 6;
int pot2 = A1;
int pot1 = A0;





void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LBack, OUTPUT);
  pinMode(LBack, OUTPUT);
  pinMode(RMotor, OUTPUT);
  pinMode(LMotor, OUTPUT);
  Serial.begin(9600); 
}

void loop() {            
followBlackLine(); 
}

void followBlackLine(){
  float LSensor = analogRead(pot1);
  float RSensor = analogRead(pot2);
  
  //Method used to update position of bot on the board
  updatePosition() ; 
  
  // ----- Series of if/else statments allows for the bot to follow the black line --
  //Both sensors on white 
  if(!isBlack(RSensor) && !isBlack(LSensor)) {
    goForwards(255);   
  } 
  //Right senses black and Left senses White (ALSO REACHED AN INTERSECTION)
  else  if(isBlack(RSensor) && !isBlack(LSensor)) {
    turnRight(255, 10);
  }
  //Left senses black and Right senses white (ALSO REACHED AN INTERSECTION 
  else if(isBlack(LSensor) && !isBlack(RSensor)) { 
  turnLeft(255, 10); 
  }
}

boolean isBlack(int var) {
  int maxWhiteColor = 100 ; 
  int minBlackColor = 250 ; 
  
  //If it is less than the maxWhiteColor then it is sensing the color white 
  //If it is greater than the minBlackColor then it is sensing the color black (most likely) ..
  //Remember to improve the method in which the program retrieves colors!!!
  
  if(var <= maxWhiteColor) {
    return false; 
  }
  else return true ; 
  
}

int getDistance() {
  long duration, distance;
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);

  return distance; 
}

void goForwards(int speed) {
   analogWrite(LMotor, speed);
   analogWrite(RMotor, speed);
   analogWrite(LBack, 0);
   analogWrite(RBack, 0);
}

void stopMoving() {
  digitalWrite(RBack, LOW);
  digitalWrite(RMotor, LOW);
  digitalWrite(LBack, LOW);
  digitalWrite(LMotor, LOW);
}

void goBackwards(int speed) {
  analogWrite(LMotor, 0);
  analogWrite(RMotor, 0);
  analogWrite(LBack, speed);
  analogWrite(RBack, speed);
}

void turnRight(int speed, int time) {
   analogWrite(LMotor, speed);
   analogWrite(RMotor, speed);
   digitalWrite(LBack, LOW);
   analogWrite(RBack, speed);
   delay(time); 
   digitalWrite(LMotor, LOW);
   digitalWrite(RMotor, LOW);
   digitalWrite(RBack, LOW);
}

void turnLeft(int speed, int time) {
   analogWrite(LMotor, speed);
   analogWrite(RMotor, speed);
   analogWrite(LBack, speed);
   digitalWrite(RBack, LOW);
   delay(time);
   digitalWrite(RMotor, LOW);
   digitalWrite(LMotor, LOW);
   digitalWrite(LBack, LOW);
}







