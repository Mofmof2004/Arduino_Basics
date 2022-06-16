int input = A0;
int LED = 10;
int sensorvalue = 0;

void setup() {
//  Used to read the value of photo resistor
  Serial.begin(9600);
  pinMode(LED, OUTPUT);

}

void loop() {
  //Read out the voltage of the photo resistor and save it under “sensorvalue”
  sensorvalue = analogRead(input);

  Serial.print("Sensor value = ");
  Serial.print(sensorvalue);
  //Send the value of the photo resistor as a number
//between 0 and 1023 to the serial monitor 

  if(sensorvalue < 512){
    digitalWrite(LED, HIGH);
    }
  else{
    digitalWrite(LED, LOW);
    }
  delay(50);
  

}
