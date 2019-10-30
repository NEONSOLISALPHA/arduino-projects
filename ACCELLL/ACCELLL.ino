void setup() {
 pinMode(11,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(5,OUTPUT);
 
}

void loop() {
  digitalWrite(11,HIGH); //BACK
  digitalWrite(10,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
   delay(2000);
 digitalWrite(11,LOW); //FORW
  digitalWrite(10,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
delay(2000);
 digitalWrite(11,LOW); //RIGHT
  digitalWrite(10,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
   delay(2000);
 digitalWrite(11,HIGH);//LEFT
  digitalWrite(10,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
delay(2000);
 }
