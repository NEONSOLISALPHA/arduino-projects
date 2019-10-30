const int trigPin=10;
const int echoPin=7;
int LED=8;
int button=2;
long duration;
int distance;
void setup() {
  // put your setup code here, to run once:
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(LED,OUTPUT);
pinMode(button,INPUT);
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
 if (digitalRead(button)==HIGH)
{
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
duration=pulseIn(echoPin,HIGH);
distance=duration*0.034/2;
if (distance<10)
{
digitalWrite(LED,HIGH);}
else
{
digitalWrite(LED,LOW);}
Serial.print("Distance");
Serial.println(distance);
}
}
