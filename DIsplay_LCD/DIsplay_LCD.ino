#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("MofMof");
  lcd.setCursor(0,1);
  lcd.print("!!!");

}
