int LED = 13;
int brightness = 0;
int fading = 1;


void setup() {
  pinMode(LED , OUTPUT);
  
}

void loop() {
  analogWrite(LED, brightness);
  //The function analogWrite is used to activate
// the PWM output on the pin with the LED. The value of the PWM is saved under
//the word “brightness”. In this case it is “0”.

  brightness = brightness + fading;

  delay(25);

  if(brightness == 0 || brightness == 255)
    fading = -fading;

}
