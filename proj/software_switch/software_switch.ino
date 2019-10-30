void setup() {
  
  pinMode(3,INPUT);
  pinMode(2, INPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  Serial.print(digitalRead(2));
  Serial.print("  ");
  Serial.println(digitalRead(3));  

  if (digitalRead(2) == HIGH )
  { digitalWrite(7, HIGH);
  } else 
  {digitalWrite(7,LOW);}
  if (digitalRead(3) == HIGH) {
    digitalWrite(6,HIGH);
  } else
  { digitalWrite(6,LOW);
  
  }
}
