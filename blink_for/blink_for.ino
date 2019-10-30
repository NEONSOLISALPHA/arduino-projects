int (i);
void setup() {
  for(i=8;i<12;i++)
  {
pinMode(i,OUTPUT);
}
}
void loop() {
  for( i=8;i<12;i++){
  delay(1000);
  digitalWrite(i,HIGH);
  delay(100);
  digitalWrite(i,LOW);}

}
