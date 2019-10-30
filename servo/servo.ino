char (c);
#include<Servo.h>
Servo mybro;

void setup() {
  mybro.attach(3);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available())
{ c= Serial.read();}
if ( c= "password" )

   { mybro.write(180);}
  
 

}
