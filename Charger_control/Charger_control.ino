int datafromUser=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT );
  Serial.begin(9600);
  digitalWrite( 8, HIGH );
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    datafromUser=Serial.read();
    Serial.print(datafromUser);
  }

  if(datafromUser == '1')
  {
    digitalWrite( 8, HIGH );
  }
  else if(datafromUser == '0')
  {
    digitalWrite( 8, LOW);
  }
  
}
