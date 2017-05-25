

int trigPin = 9;
int echoPin = 10;
int LBack = 4;
int RBack = 7;
int LMotor = 5;
int RMotor = 6;
int pot2 = A1;
int pot1 = A0;

//Actions
boolean TurningRight = false ; 
boolean TurningLeft = false ; 
boolean GoingStraight = false ; 

//INITIAL SPEED
int lSpeed = 200; 
int rSpeed = 200 ;

int BlessUp = 0; 

char Direction[] = {'N', 'E', 'S', 'W'};
String Action[] = {"Turning Left", "Going Straight", "Turning Right"};

int currentAction = 1 ; 

//Counter 
int counter = 0 ;

//Current Ticks
int XTicks  = 0 ; 
int YTicks  = 0;

int currentDirection = 1;

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

currentAction = 1 ;   
  float LSensor = analogRead(pot1);
  float RSensor = analogRead(pot2);

 
  
//followBlackLine() ;

//updateTicks() ; 


//Serial.println(getDistance());
if(getDistance() <= 15) {
    //Turn Left Or Right 
    //If Facing East (Turn Right)
    if(currentDirection == 1) {
      turnRight(255, 5000) ;
    }
  
    //If Facing South (Turn Left)
    else if(currentDirection == 2) {
       turnLeft(255, 245) ;
    }
    //If Facing West (Turn Left)
    else if(currentDirection == 3 ) {
      turnLeft(255, 245) ; 
    }

    //If Facing North (Turn Right)
    else if(currentDirection == 0) {
       turnRight(255, 245) ;
    }

    counter = 0 ;
  }
}


  




void followBlackLine() {
  
  float LSensor = analogRead(pot1);
  float RSensor = analogRead(pot2);

  analogWrite(LMotor, lSpeed);
   analogWrite(RMotor, rSpeed);
   analogWrite(LBack, 0);
   analogWrite(RBack, 0);
   
  //goForwards(); 
   if(LSensor < 300 && RSensor > 300) {
    rSpeed = 50 ; 
    lSpeed = 255 ; 
  }
  else if(RSensor < 300 && LSensor > 300) {
    lSpeed = 50;
    rSpeed = 255 ; 
     
  }

  else {
  
    lSpeed =255 ; 
    rSpeed = 255 ; 
    }
  

  
}


void updateTicks() {
  
updateXTicks() ;
updateYTicks() ; 

}

void updateXTicks() {
 
}
void updateYTicks () {

}



int getDistance() {
  long duration, distance;
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  //Serial.print(distance);
 // Serial.println("CM");
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

  
 currentAction + 1 ; 

  if(counter == 0) {
  if(currentDirection == 3) {
    currentDirection-= 3 ; 

  } else {
     currentDirection++ ;

  }
  }
  rSpeed = 255; 
  lSpeed = 0 ; 
  /*
 
   analogWrite(LMotor, speed);
   analogWrite(RMotor, speed);
   digitalWrite(LBack, LOW);
   analogWrite(RBack, speed);
   delay(time); 
   digitalWrite(LMotor, LOW);
   digitalWrite(RMotor, LOW);
   digitalWrite(RBack, LOW);
   */
        counter++ ;  
}

void turnLeft(int speed, int time) {
  currentAction-- ; 
  if(counter == 0){
  if(currentDirection == 0) {
    currentDirection = currentDirection + 3 ; 
  } else {
    currentDirection-- ; 
  }
}
   rSpeed = 0 ; 
   lSpeed = 255 ; 
   /*
   analogWrite(LMotor, speed);
   analogWrite(RMotor, speed);
   analogWrite(LBack, speed);
   digitalWrite(RBack, LOW);
   delay(time);
   digitalWrite(RMotor, LOW);
   digitalWrite(LMotor, LOW);
   digitalWrite(LBack, LOW);
   */
   counter++ ; 
}







