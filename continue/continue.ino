#include <Servo.h>
Servo flash;
int pos;

void setup() {
 flash.attach(3);
flash.write(0);
}

void loop() {
  for(int pos=0;pos<180;pos++)
  {flash.write(pos);}
  if (pos=180)
  {for(pos=180;pos<0;pos--)
  {flash.write(pos);}}
}
