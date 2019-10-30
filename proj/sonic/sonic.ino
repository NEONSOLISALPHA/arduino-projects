const int trpin = 2;
const int echpin = 3;
const int ledpin = 4; 
const int switchpin = 5;

long dura ;
int dist;

void setup() {
  pinMode (trpin, OUTPUT);
  pinMode (echpin, INPUT);
  Serial.begin(9600);
}

void loop() {
  bool statesw = digitalRead(switchpin);
  Serial.print (statesw);
  Serial.println  ("  ");
if (statesw  == HIGH){
  
  
  
  digitalWrite(trpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trpin, LOW);
  dura = pulseIn(echpin, HIGH);
  dist = dura * 0.034 / 2;
  Serial.print(  "distance =  "  );
  Serial.print (dist);
  Serial.print (" ");
  Serial.println("cm");
 if ( dist < 10) {
  digitalWrite(ledpin,HIGH);
 }
 else {
  digitalWrite(ledpin,LOW );
  
  
 }}
 
 }
