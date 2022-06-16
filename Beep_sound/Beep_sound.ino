int beep = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(beep, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(beep, HIGH);
  delay(010);
  digitalWrite(beep, LOW);
  delay(010);
  

}
