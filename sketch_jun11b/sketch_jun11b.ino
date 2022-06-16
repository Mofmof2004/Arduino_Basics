

void setup()
{
Serial.begin(9600); //In the setup we are starting the serial connection, to 

pinMode (13, OUTPUT);
pinMode (8, INPUT);
}
void loop()
{ //The loop part is quite short because of the used library. 
  if (digitalRead(8)== HIGH)
  {
    digitalWrite(13, HIGH);
    delay(30);}
  
  if (digitalRead(8)== LOW)
  {
    digitalWrite(13, LOW);
    delay(30);}
   
  
}
