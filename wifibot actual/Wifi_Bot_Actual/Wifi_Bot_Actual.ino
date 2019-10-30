/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <Servo.h>
#include <BlynkSimpleEsp8266.h>
   #define LM1  D7
   #define LM2  D4
   #define RM1  D6
   #define RM2  D5
   #define Overridepin D3
   #define Sliderpin V2
                                 // You should get Auth Token in the Blynk App.
                                 // Go to the Project Settings (nut icon).
                                 char auth[] = "BNjsNLtTnau4HFEh0lPC3tHyZyJ2Iz53";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Adhu 1+7";
char pass[] = "ADHU1212";
Servo arm;

void setup()
{
  // Debug consol
  arm.attach(D2);
  pinMode(D0, INPUT);
  pinMode(D2, OUTPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(Overridepin,INPUT);
  Serial.begin(9600);
   


  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}
void loop()
{
  Blynk.run();
}
BLYNK_WRITE(V1) {
  int x = param[0].asFloat();
  x = map(x, -10, 10, 0, 255);
  Serial.print(" x = ");
  Serial.print(x);
  int y = param[1].asFloat();
  y = map(y, -10, 10, 0, 255);
  Serial.print(" y = ");
  Serial.print(y);
  int z = param[2].asFloat();
  z = map(z, -10, 10, 0, 255);
  Serial.print(" z = ");
  Serial.print(z);
  bool But_State = digitalRead(D0);
  int Servoval= analogRead(V1);
  if (But_State== HIGH){
    arm.write(150);
  }
  else {
    arm.write(50);
  }


  
  Serial.print(" Button = ");
  Serial.print(But_State);
  bool Override = digitalRead(D3);
  Serial.print(" OVERRIDE = ");
  Serial.print(Override);
  
  if (x<90){
  digitalWrite(D7,HIGH);
  digitalWrite(D4,LOW);
  digitalWrite(D6,LOW);
  digitalWrite(D5,HIGH);
    Serial.println(" back");
  }
  else if (x>180)
  {
   digitalWrite(D7,LOW);
   Serial.print("D7 =");
   Serial.print(digitalRead(D7));
  digitalWrite(D4,HIGH);
  Serial.print("D4 =");
   Serial.print(digitalRead(D4));
  digitalWrite(D6,LOW);
  Serial.print("D6 =");
   Serial.print(digitalRead(D6));
  digitalWrite(D5,HIGH);
  Serial.print("D5 =");
   Serial.println(digitalRead(D5));
    Serial.println(" forward");
  }
  else if (y<90){
    digitalWrite(D7,HIGH);
     Serial.print("D7 =");
   Serial.print(digitalRead(D7));
  digitalWrite(D4,LOW);
  Serial.print("D4 =");
   Serial.print(digitalRead(D4));
  digitalWrite(D6,LOW);
  Serial.print("D6 =");
   Serial.print(digitalRead(D6));
  digitalWrite(D5,HIGH);
  Serial.print("D5 =");
   Serial.println(digitalRead(D5));
    Serial.println(" left");
  }
  else if (y>180){
   digitalWrite(D7,LOW);//LM1
   Serial.print("D7 =");
   Serial.print(digitalRead(D7));
   digitalWrite(D4,HIGH);//LM2
   Serial.print("D4 =");
   Serial.print(digitalRead(D4));
   digitalWrite(D6,HIGH);//RM1
   Serial.print("D6 =");
   Serial.print(digitalRead(D6));
   digitalWrite(D5,LOW);//RM2
   Serial.print("D5 =");
   Serial.println(digitalRead(D5));
   Serial.println(" right");
  }
  else {
  digitalWrite(D7,LOW);
  Serial.print("D7 =");
   Serial.print(digitalRead(D7));
  digitalWrite(D4,LOW);
  Serial.print("D4 =");
   Serial.print(digitalRead(D4));
  digitalWrite(D6,LOW);
  Serial.print("D6 =");
   Serial.print(digitalRead(D6));
  digitalWrite(D5,LOW);
  Serial.println(digitalRead(D5));
  Serial.println(" stopped");
  }
  }

    
  
