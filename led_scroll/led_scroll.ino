#include <LiquidCrystal.h>
LiquidCrystal  lcd(8, 9, 10, 11, 12, 13);
#include <Servo.h>
Servo mybro; 
String c;
void setup() {
  mybro.attach(3);
  Serial.begin(9600);

}

 void loop() {
  if (Serial.available())
  {c = Serial.readString ();
      if (c ="password")
      {mybro.write(180);}
  }
         
  

}
