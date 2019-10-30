#define BLYNK_PRINT Serial



#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "qjkss3RldoTefqV8uZcO1aK8j3TGtUaZ";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Adhu 1+7";
char pass[] = "ADHU!2!2";
#define LM1 D4
#define LM2 D5
#define RM1 D6
#define RM2 D7
#define potpin V2
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

void loop()
{
  Blynk.run();
}
BLYNK_WRITE(V1)
{
  int x = param[0].asInt();
  Serial.print(" x = ");
  Serial.print(x);
  int y = param[1].asInt();
  Serial.print(" y = ");
  Serial.print(y);
  int val = analogRead(potpin);
  Serial.print(" speedval= ");
  Serial.print(val);
  if (y > 850)
  {
    if (x < 230) {
      analogWrite(LM1, LOW);//FORWARD
      analogWrite(LM2, LOW);
      analogWrite(RM1, val);
      analogWrite(RM2, LOW);
      Serial.println(" forward left");
    }
    else if (x > 850)
    {
      analogWrite(LM1, val);//FORWARD
      analogWrite(LM2, LOW);
      analogWrite(RM1, LOW);
      analogWrite(RM2, LOW);
      Serial.println(" forward right");
    }
    else
    {
      analogWrite(LM1, val);//FORWARD
      analogWrite(LM2, LOW);
      analogWrite(RM1, val);
      analogWrite(RM2, LOW);
      Serial.println(" forward");
    }
  }
  else if (y < 200)
  {
    if (x < 230) {
      analogWrite(LM1, LOW);//FORWARD
      analogWrite(LM2, LOW);
      analogWrite(RM1, LOW);
      analogWrite(RM2, val);
      Serial.println(" backward left");
    }
    else if (x > 850)
    {
      analogWrite(LM1, LOW);//FORWARD
      analogWrite(LM2, val);
      analogWrite(RM1, LOW);
      analogWrite(RM2, LOW);
      Serial.println(" backward right");
    }
    else
    {
      analogWrite(LM1, LOW);//BACK
      analogWrite(LM2, val);
      analogWrite(RM1, LOW);
      analogWrite(RM2, val);
      Serial.println(" back");
    }
  }
  else if (x > 950)
  {
    analogWrite(LM1, val);//RIGHT
    analogWrite(LM2, LOW);
    analogWrite(RM1, LOW);
    analogWrite(RM2, val);
    Serial.println(" right");
  }
  else if (x < 150)
  {
    analogWrite(LM1, LOW);//LEFT
    analogWrite(LM2, val);
    analogWrite(RM1, val);
    analogWrite(RM2, LOW);
    Serial.println(" left");
  }
  else
  {
    analogWrite(LM1, LOW);//STOPPED
    analogWrite(LM2, LOW);
    analogWrite(RM1, LOW);
    analogWrite(RM2, LOW);
    Serial.println(" stopped");
  }
}
