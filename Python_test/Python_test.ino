//Arduino code for sending DHT11 data to python
//That's Engineeing




//Variables to store temp and hum data
int x;



void setup()
{
  pinMode(4, INPUT);
  Serial.begin(9600);  
}

void loop()
{
  x = digitalRead(4);
  Serial.println(x);
  delay(100);
 
}

  
