void setup() {
pinMode(D7,OUTPUT);// put your setup code here, to run once:
pinMode(D4,OUTPUT);
pinMode(D6,OUTPUT);
pinMode(D5,OUTPUT);
}

void loop() {
  digitalWrite(D7,HIGH);
  delay(1000);
  digitalWrite(D7,LOW);
  digitalWrite(D4,HIGH);
  delay(1000);
  digitalWrite(D4,LOW);
  digitalWrite(D6,HIGH);
  delay(1000);
  digitalWrite(D6,LOW);
  digitalWrite(D5,HIGH);// put your main code here, to run repeatedly:
 delay(1000);
 digitalWrite(D5,LOW);
}
