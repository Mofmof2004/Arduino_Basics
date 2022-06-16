int LEDblue = 6;
int button = 7;
int buttonstatus = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDblue, OUTPUT);
  pinMode(button, INPUT);

}

void loop()
{
  // put your main code here, to run repeatedly:
  buttonstatus = digitalRead(button);}
    
    }
  else
  {
    digitalWrite(LEDblue, LOW);
    }

}
