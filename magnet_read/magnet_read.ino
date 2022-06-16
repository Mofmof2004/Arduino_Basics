float var;

void setup() {
  pinMode(A3, INPUT);
  Serial.begin(9600);

}

void loop() {
  var = analogRead(A3);
  Serial.println(var);
  delay(100);

}
