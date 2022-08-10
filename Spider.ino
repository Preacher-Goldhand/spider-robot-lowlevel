#include <Servo.h>

#define buzzer 11 // Buzzer at Pin 11
#define trigPin 12 // Trig at Pin 12
#define echoPin 13 // Echo at Pin 13

Servo servoPin2; // Head
Servo servoPin3; // Left up leg (horizontal)
Servo servoPin4; // Left up leg (vertical)
Servo servoPin5; // Left down leg (horizontal)
Servo servoPin6; // Left down leg (vertical)
Servo servoPin7;  // Right up leg (horizontal)
Servo servoPin8; // Right up leg (vertical)
Servo servoPin9; // Right down leg (horizontal)
Servo servoPin10; // Right down leg (vertical)

void setup() {
  servoPin2.attach(2);
  servoPin3.attach(3);
  servoPin4.attach(4);
  servoPin5.attach(5);
  servoPin6.attach(6);
  servoPin7.attach(7);
  servoPin8.attach(8);
  servoPin9.attach(9);
  servoPin10.attach(10);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
}
void moveLegs()
{
   /*
      HORIZONTAL LEGS' MOVEMENT
  */
 
  for(int pos = 0; pos < 180; pos += 1)  
  {                                  
    servoPin3.write(pos); 
    servoPin5.write(pos);
    servoPin7.write(pos);
    servoPin9.write(pos);          
    delay(15);                      
  } 
  for(int pos = 180; pos >=1; pos-=1)     
  {                                
    servoPin3.write(pos); 
    servoPin5.write(pos);
    servoPin7.write(pos);
    servoPin9.write(pos);              
    delay(15);                      
  } 

  /*
      VERTICAL LEGS' MOVEMENT
   */
  for(int pos = 0; pos < 90; pos += 1)  
  {                                  
    servoPin4.write(pos); 
    servoPin6.write(pos);
    servoPin8.write(pos);
    servoPin10.write(pos);          
    delay(15);                      
  } 
  for(int pos = 90; pos >=1; pos-=1)     
  {                                
    servoPin4.write(pos); 
    servoPin6.write(pos);
    servoPin8.write(pos);
    servoPin10.write(pos);              
    delay(15);                      
  }   
}
void moveHead()
{
  for(int pos = 0; pos < 120; pos += 1)  
  {                                  
    servoPin2.write(pos);         
    delay(15);                      
  } 
  for(int pos = 120; pos >=1; pos-=1)     
  {                                
    servoPin2.write(pos);              
    delay(15);                      
  } 
}
void detectObstacle()
{
  /*
    TRIGPIN ACTIVATION (IN mS)
  */
  dur, dist;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);

  /*
     ECHOPIN ACTIVATION AND SETTINGS FOR DURATION (IN mS) AND DISTANCE
  */
  dur = pulseIn(echoPin, HIGH);
  dist = (dur/2)/29.1;

  /*
    CHECK DISTANCE (IN cm) FROM OBSTACLE AND ACTIVATION OF BUZZER
  */

  if ((dist >= 0) && (dist <= 30))
  {
    digitalWrite(buzzer, HIGH);
  }
  else 
  {
    digitalWrite(buzzer, LOW);
  }
}
void loop() {
  moveLegs();
  moveHead();
  detectObstacle();

}
