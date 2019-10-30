
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("");
  Serial.begin(9600);
}

void loop() {
  String text;
  
  if (Serial.available())
  {
    lcd.clear();
    text = Serial.readString();
    lcd.print(text);
    Serial.println(text);
}
  else if (text == "")
  {
  lcd.print(text);
    
  }
 
}
