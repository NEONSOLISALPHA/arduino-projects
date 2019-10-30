void setup() {
  Serial.begin(9600);
 
  pinMode(D5, OUTPUT);
  pinMode(D6, INPUT);

  

}

void loop() {
  long duration;
 digitalWrite(D5,HIGH);
 delayMicroseconds(5);
 digitalWrite(D5,LOW);
 delayMicroseconds(2);
 duration = pulseIn(D6,HIGH);
  float cm = duration/29/2;// put your main code here, to run repeatedly:
 Serial.println(cm);
}
