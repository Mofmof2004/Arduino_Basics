#include <Servo.h>

Servo servoblue;

void setup() {
  servoblue.attach(8);
}

void loop() {
  servoblue.write(0);
  delay(2000);
  servoblue.write(180);
  delay(2000);
  
  
  
  
  
  
  
  
  
}
