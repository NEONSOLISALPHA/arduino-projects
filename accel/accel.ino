#include <Servo.h>


void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
 arm.attach(3)


}

void loop() {
  Serial.print("x= ");
  int x = analogRead(A0);
  Serial.print(x);
  int y = analogRead(A2);
  Serial.print("y= ");
  Serial.println(y);
   if (x>350){
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);}
   else if (x <300){
   digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);}
  
  else if (y<){
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW );
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);}
    else if (y >){
    digitalWrite(4,LOW );
    digitalWrite(5,HIGH);
    igitalWrite(6,LOW);
    digitalWrite(7,HIGH);}
    else {
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);}
    if (pot<){
      arm.write();}
      else {
      arm.write();}
      }

   
}

   

  

}
