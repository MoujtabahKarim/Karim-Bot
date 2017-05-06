#include <IRControl.h>
#include <MotorControl.h>
#include <UltrasonicControl.h>

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    
    //pins for ultrasonic sensor
  pinMode(9, OUTPUT);
  pinMode(10, INPUT);


}

void loop() {
 
Serial.println(getDistance());
       
  



}

//Method used to return the distance
int getDistance() {
    long duration, distance;
    digitalWrite(9, LOW); //esure output to the sensor is clean
    delayMicroseconds(2);
    
  digitalWrite(9, HIGH); //trigger for 10 ms
  delayMicroseconds(10);
  
  digitalWrite(9, LOW); //end pulse
  
  
  duration = pulseIn(10, HIGH); //wait for return pulse for 1/4 second
  
  distance = (duration/2) / 29.1; //calculate distance
                //round trip so divide by two 
                
  if (distance>=200||distance<=0) return -1; //error state
  return (int)distance; //cast it to an int. I dont think a long is nessisary
    
}

