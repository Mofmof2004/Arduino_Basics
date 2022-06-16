#include <Servo.h>

Servo servoblue;


int trigger = 12;
int echo = 13;
int servo = 8;
int servopos = 0;
int count = 0;
long time = 0;
long dist = 0;

void setup() {
  Serial.begin (9600); 
  //  disatnce setup
  pinMode(trigger, OUTPUT); 
  pinMode(echo, INPUT);
  servoblue.attach(servo);
  servoblue.write(23);

}

void loop() {
digitalWrite(trigger, LOW); //Low voltage on the trigger pin to produce a
//clear signal.
delay(5); //….for 5 milliseconds.
digitalWrite(trigger, HIGH); //Creating the soundwave.
delay(10); //..for 10 milliseconds.
digitalWrite(trigger, LOW); //Stop creating the soundwave
//Measures time taken for wave to come back
time = pulseIn(echo, HIGH);
//  Calculating distance
dist = (time/2) / 29.1;
Serial.println(dist);
if (dist < 80 && count == 0){
  count = 1;
  if (servopos == 12){
    servoblue.write(38);
    servopos = 38;}
  else{
  servoblue.write(12);
  servopos = 12;}
  delay(1000);}
else{
  count = 0;}

}
