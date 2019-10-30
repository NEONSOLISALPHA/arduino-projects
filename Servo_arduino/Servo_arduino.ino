#include<Servo.h>
Servo arm;

void setup() {
  arm.attach(3);// put your setup code here, to run once:
  pinMode(7,INPUT);
}

void loop() {
  int Servostate = digitalRead(7);
   if (Servostate == HIGH){
    arm.write(150);
   }   else {
    arm.write(50);// put your main code here, to run repeatedly:
   }
   }
