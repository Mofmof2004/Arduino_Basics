char Incoming_value = 0;
                
void setup() 
{
  Serial.begin(57600);         
  pinMode(2, OUTPUT);       
}

void loop()
{
  
    Serial.print("lol");
  if(Serial.available() > 0)  
  {
    Serial.print("lol");
    Incoming_value = Serial.read();      
    Serial.print(Incoming_value);        
    Serial.print("\n");        
    if(Incoming_value == '1')             
      digitalWrite(2, HIGH);  
      
    else if(Incoming_value == '0')       
      digitalWrite(2, LOW);   
  }                            
} 
