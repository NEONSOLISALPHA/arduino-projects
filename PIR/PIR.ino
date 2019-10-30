int led = 3;
int sensor = 4 ;

int val = 0 ;



void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {-
  val = digitalRead(sensor);
  if (val == HIGH)
  { digitalWrite(led, HIGH);

  } delay(100);
  if (val == LOW)
  { Serial.println("Motion Detected");

  }
  else {
    digitalWrite(led, LOW);
    Serial.println("no motion detected");
  }

}
