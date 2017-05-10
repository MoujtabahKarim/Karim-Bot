

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

void loop() {               // the loop function runs over and over again forever
followBlackLine(); 
}

void followBlackLine() {
  float LSensor = analogRead(pot1);
  float RSensor = analogRead(pot2);
  
  if(RSensor < 150 && LSensor < 150) {
    goForwards(255); 
  } else  if(LSensor < 300) {
    turnRight(255, 10);
  }
  else if(RSensor < 300) {
  turnLeft(255, 10); 
  }
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







