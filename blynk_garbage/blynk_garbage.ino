
#define BLYNK_PRINT Serial
float cmmm;
float cmm;
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = " HQLcDVREu5YgHrd_JM6GzRDYX46T-EMj";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Adhu 1+7";
char pass[] = "";

void setup()
{
  pinMode(D5, OUTPUT);
  pinMode(D6, INPUT);

  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  long duration;
  digitalWrite(D5, HIGH);
  delayMicroseconds(5);
  digitalWrite(D5, LOW);
  delayMicroseconds(2);
  duration = pulseIn(D6, HIGH);
  float cm = duration / 29 / 2; // put your main code here, to run repeatedly:

  cm = constrain(cm, 1, 300);
  cmm = map(cm, 1, 300, 50, 0);
  cmmm = map(cmm, 45, 50, 0, 100);
  
  if (cmmm < 0.00 ) {
    cmmm = 100;
  }
  else {
    cmmm = cmmm;
  }
Serial.println(cmmm);
  blynk(); 
  
}  void blynk() {
    Blynk.virtualWrite(V1, cmmm);
    Blynk.virtualWrite(V2, cmmm);
  }
