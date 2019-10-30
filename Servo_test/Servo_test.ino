#include<Servo.h>
Servo arm;


void setup() {
 arm.attach(3); // put your setup code here, to run once:

}

void loop() {
  arm.write(150);
  delay(1000);
  arm.write(50);
  delay(1000);
  // put your main code here, to run repeatedly:

} 
