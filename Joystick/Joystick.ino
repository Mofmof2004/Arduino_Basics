const int SW_pin = 2;
const int X_pin = 0;
const int Y_pin = 1;

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(115200);

}

void loop() {
  Serial.print("Switch: ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axes: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axes: ");
  Serial.print(analogRead(Y_pin));
  Serial.print("\n");
  delay(50);



}
