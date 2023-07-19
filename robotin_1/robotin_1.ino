// ROBOTIN PART 1 (Arduino Uno)
// OSCAR POBLETE SAENZ
// INSTALL AFMotor AND NewPing LIBRARIES BEFORE UPLOADING THE PROGRAM
// NEWPING LIBRARY: https://www.arduino.cc/reference/en/libraries/newping/
// AFMOTOR LIBRARY: https://diegomgarduino.weebly.com/motorshield.html
// Sketch >> Include Library >> Add .Zip Library >> Choose zip files from both libraries>> Done) //

#include<NewPing.h>
#include<Servo.h>
#include<AFMotor.h>
#define RIGHT A2
#define LEFT A3
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 200
  

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


AF_DCMotor Motor1(1,MOTOR12_1KHZ);
AF_DCMotor Motor2(2,MOTOR12_1KHZ);
AF_DCMotor Motor3(3,MOTOR34_1KHZ);
AF_DCMotor Motor4(4,MOTOR34_1KHZ);

Servo myservo;
 
int pos =0; // POSITION IN DEGREES FOR SERVOMOTOR

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
myservo.attach(10);
// START SERVO TO RECOGNIZE SPACE
{
for(pos = 90; pos <= 180; pos += 1){
  myservo.write(pos);
  delay(15);
} for(pos = 180; pos >= 0; pos-= 1) {
  myservo.write(pos);
  delay(15);
}for(pos = 0; pos<=90; pos += 1) {
  myservo.write(pos);
  delay(15);
}
}
pinMode(RIGHT, INPUT);
pinMode(LEFT, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(50);
 unsigned int distance = sonar.ping_cm();
Serial.print("distance");
Serial.println(distance);


int Right_val = digitalRead(RIGHT);
int Left_val = digitalRead(LEFT);

Serial.print("RIGHT");
Serial.println(Right_val);
Serial.print("LEFT");
Serial.println(Left_val);

// DETECT POSITION AND FOLLOW 
if((Right_val==1) && (distance>=7 && distance<=70)&&(Left_val==1)){
  Motor1.setSpeed(120);
  Motor1.run(FORWARD);
  Motor2.setSpeed(120);
  Motor2.run(FORWARD);
  Motor3.setSpeed(120);
  Motor3.run(FORWARD);
  Motor4.setSpeed(120);
  Motor4.run(FORWARD);
}else if((Right_val==0) && (Left_val==1)) {
  Motor1.setSpeed(200);
  Motor1.run(FORWARD);
  Motor2.setSpeed(200);
  Motor2.run(FORWARD);
  Motor3.setSpeed(0);
  Motor3.run(RELEASE);
  Motor4.setSpeed(0);
  Motor4.run(RELEASE);
}else if((Right_val==1)&&(Left_val==0)) {
  Motor1.setSpeed(0);
  Motor1.run(RELEASE);
  Motor2.setSpeed(0);
  Motor2.run(RELEASE);
  Motor3.setSpeed(200);
  Motor3.run(FORWARD);
  Motor4.setSpeed(200);
  Motor4.run(FORWARD);
  
// DETECT AND AVOID COLLISION
}else if((Right_val==1)&&(Left_val==1)) { 
  Motor1.setSpeed(0);
  Motor1.run(RELEASE);
  Motor2.setSpeed(0);
  Motor2.run(RELEASE);
  Motor3.setSpeed(0);
  Motor3.run(RELEASE);
  Motor4.setSpeed(0);
  Motor4.run(RELEASE);
}else if(distance > 1 && distance < 7) {
  Motor1.setSpeed(0);
  Motor1.run(RELEASE);
  Motor2.setSpeed(0);
  Motor2.run(RELEASE);
  Motor3.setSpeed(0);
  Motor3.run(RELEASE);
  Motor4.setSpeed(0);
  Motor4.run(RELEASE);
  }
 }
