#define BLYNK_PRINT Serial
#define frontpin V3
#define rightpin V4
#define backpin V5
#define leftpin V6
#define potpin V2
#define LM1 D4
#define LM2 D5
#define RM1 D6
#define RM2 D7
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int val = analogRead(potpin);
bool front = digitalRead(frontpin);
bool back = digitalRead(backpin);
bool right = digitalRead(rightpin);
bool left = digitalRead(leftpin);
String Space = " ";

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Adhu 1+7";
char pass[] = "ADHU!2!2";

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(potpin, INPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}
void forward()
{
  analogWrite(LM1, val);//FORWARD
  Serial.print(Space + analogRead(LM1));
  analogWrite(LM2, LOW);
  Serial.print(Space + analogRead(LM2));
  analogWrite(RM1, val);
  Serial.print(Space + analogRead(RM1));
  analogWrite(RM2, LOW);
  Serial.print(Space + analogRead(RM2));
  Serial.println(" forward");
}
void backward()
{
  analogWrite(LM1, LOW);//BACK
  Serial.print(Space + analogRead(LM1));
  analogWrite(LM2, val);
  Serial.print(Space + analogRead(LM2));
  analogWrite(RM1, LOW);
  Serial.print(Space + analogRead(RM1));
  analogWrite(RM2, val);
  Serial.print(Space + analogRead(RM2));
  Serial.println(" backward");
}
void leftward()
{
  analogWrite(LM1, LOW);//LEFT
  Serial.print(Space + analogRead(LM1));
  analogWrite(LM2, val);
  Serial.print(Space + analogRead(LM2));
  analogWrite(RM1, val);
  Serial.print(Space + analogRead(RM1));
  analogWrite(RM2, LOW);
  Serial.print(Space + analogRead(RM2));
  Serial.println(" left");
}
void rightward()
{
  analogWrite(LM1, val);//RIGHT
  Serial.print(Space + analogRead(LM1));
  analogWrite(LM2, LOW);
  Serial.print(Space + analogRead(LM2));
  analogWrite(RM1, LOW);
  Serial.print(Space + analogRead(RM1));
  analogWrite(RM2, val);
  Serial.print(Space + analogRead(RM2));  
  Serial.println(" right");
}
void forwardleft()
{
  analogWrite(LM1, LOW);//FORWARD LEFT
  Serial.print(Space + analogRead(LM1));
  analogWrite(LM2, LOW);
  Serial.print(Space + analogRead(LM2));
  analogWrite(RM1, val);
  Serial.print(Space + analogRead(RM1));
  analogWrite(RM2, LOW);
  Serial.print(Space + analogRead(RM2));
  Serial.println(" forward left");
}
void forwardright()
{
  analogWrite(LM1, val);//FORWARD RIGHT
  Serial.print(Space + analogRead(LM1));
  analogWrite(LM2, LOW);
  Serial.print(Space + analogRead(LM2));
  analogWrite(RM1, LOW);
  Serial.print(Space + analogRead(RM1));
  analogWrite(RM2, LOW);
  Serial.print(Space + analogRead(RM2));
  Serial.println(" forward right");
}
void backwardleft()
{
  analogWrite(LM1, LOW);//BACKWARD LEFT
  Serial.print(Space + analogRead(LM1));
  analogWrite(LM2, LOW);
  Serial.print(Space + analogRead(LM2));
  analogWrite(RM1, LOW);
  Serial.print(Space + analogRead(RM1));
  analogWrite(RM2, val);
  Serial.print(Space + analogRead(RM2));
  Serial.println(" backward left");
}
void backwardright()
{
  analogWrite(LM1, LOW);//BACKWARD RIGHT
  Serial.print(Space + analogRead(LM1));
  analogWrite(LM2, val);
  Serial.print(Space + analogRead(LM2));
  analogWrite(RM1, LOW);
  Serial.print(Space + analogRead(RM1));
  analogWrite(RM2, LOW);
  Serial.print(Space + analogRead(RM2));
  Serial.println(" backward right");
}
void stopped() {
  analogWrite(LM1, LOW);//STOPPED 
  Serial.print(Space + analogRead(LM1));
  analogWrite(LM2, LOW);
  Serial.print(Space + analogRead(LM2));
  analogWrite(RM1, LOW);
  Serial.print(Space + analogRead(RM1));
  analogWrite(RM2, LOW);
  Serial.print(Space + analogRead(RM2));
  Serial.println(" stopped");
}
void loop()
{
  Blynk.run();
  Run();
}
void Run()
{
  Serial.print("potvalue = ");
  Serial.print(val);
  if (front == HIGH && back == LOW && left == LOW && right == LOW)
  {
    forward();
  }
  else if (front == LOW && back == HIGH && left == LOW && right == LOW)
  {
    backward();
  }
  else if (front == LOW && back == LOW && left == HIGH && right == LOW)
  {
    leftward();
  }
  else if (front == LOW && back == LOW && left == LOW && right == HIGH)
  {
    rightward();
  }
  else if (front == HIGH && back == LOW && left == LOW && right == HIGH)
  {
    forwardright();
  }
  else if (front == HIGH && back == LOW && left == HIGH && right == LOW)
  {
    forwardleft();
  }
  else if (front == LOW && back == HIGH && left == LOW && right == HIGH)
  {
    backwardright();
  }
  else if (front == LOW && back == HIGH && left == HIGH && right == LOW)
  {
    backwardleft();
  }
  else
  {
    stopped();
  }





}
