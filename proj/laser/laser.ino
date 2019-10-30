void setup() {
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  Serial.println(analogRead(A0));
if (analogRead(A0)<900){
digitalWrite(6,HIGH);
digitalWrite(13,HIGH);}

 else {
  digitalWrite(6,LOW);
digitalWrite(13,LOW);
digitalWrite(8,LOW);
 }
}
