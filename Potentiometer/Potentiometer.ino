int input = A0;
int LED = 13;
int sensorvalue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  
}

void loop() {
  sensorvalue = analogRead(input);
  digitalWrite(LED, HIGH);
  delay(sensorvalue);
  
  Serial.println(sensorvalue);
  digitalWrite(LED, LOW);
  delay(sensorvalue);
  Serial.println(sensorvalue);
  

}
