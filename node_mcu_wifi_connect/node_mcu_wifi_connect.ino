#include <ESP8266WiFi.h>
int LED = D5;
void setup()
{
  pinMode(LED,OUTPUT);
  Serial.begin(115200);
  Serial.println();

  WiFi.begin("vipin","robotics1");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  int str = WiFi.RSSI();
  Serial.println(str);
 if (str <= -30){
  digitalWrite(LED,HIGH);}
  else
  
  {
       digitalWrite(LED,LOW);
  }
 
  }
