float var;

void setup() {
  // put your setup code here, to run once:
  pinMode(A3, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  var = analogRead(A3);
  if (var <= 1000){
    digitalWrite(13, HIGH);
    }
  else
    digitalWrite(13, LOW);
  Serial.println(var);
  delay(500);

}
