#define ypin A1
#define xpin A0
#define fpin 6
#define bpin 7
int xaxis;
int yaxis;
void setup() {
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);

  pinMode(fpin, OUTPUT);
  pinMode(bpin, OUTPUT);
  Serial.begin(9600);




  // put your setup code here, to run once:

}

void loop() {
  Serial.print("xAxis=");
  Serial.print(analogRead(xpin));
  Serial.print ("   yAxis=");
 
  Serial.print(analogRead(ypin));
  Serial.print ("   " );
 Serial.print(digitalRead(fpin));
 Serial.print ("   " );
 Serial.println(digitalRead(bpin));
  xaxis = analogRead(xpin);
  yaxis = analogRead(ypin);

  if (yaxis < 320)
  { digitalWrite(fpin, HIGH);
    digitalWrite(bpin, LOW);
  }
  else if (yaxis > 365) {
    digitalWrite(fpin, LOW);
    digitalWrite(bpin, HIGH);
  }
  else
  { digitalWrite(fpin, LOW);
    digitalWrite(bpin, LOW);
  }
}
