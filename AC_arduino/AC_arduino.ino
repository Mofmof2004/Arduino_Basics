#include <Servo.h>
#include <SoftwareSerial.h>
Servo servoblue;
#define TxD 2
#define RxD 3
SoftwareSerial BTserial(RxD, TxD); // RX, TX for Bluetooth

char data_recieved = 0;
int temp = 5;
int trigger = 4;
int echo = 7;
int servo = 8;
int increase_btn = 4;
int decrease_btn = 5;
int servopos = 0;
void setup() {
  Serial.begin(9600) ;
  BTserial.begin(38400); // For Bluetooth
  pinMode(trigger, OUTPUT); 
  pinMode(increase_btn, INPUT);
  pinMode(decrease_btn, INPUT);
  pinMode(echo, INPUT);
  servoblue.attach(servo);
  servoblue.write(20);

}

void loop() {

if (digitalRead(increase_btn) == HIGH){
  temp = temp + 1;
  Serial.print(temp);
  servoblue.write(30);
    delay(100);
    servoblue.write(20);
    delay(2000);
     servoblue.write(30);
    delay(100);
    servoblue.write(20);
    BTserial.print(temp);
  }
  
if (digitalRead(decrease_btn) == HIGH){
  temp = temp - 1;
    Serial.println(temp);
    servoblue.write(10);
    delay(100);
    servoblue.write(20);
    delay(2000);
     servoblue.write(10);
    delay(100);
    servoblue.write(20);
     BTserial.print(String(temp));
}

     
//  IF incoming bluetooth data
  if (BTserial.available() > 0)// LOOP...
  {
//  Read data  
  data_recieved = BTserial.read();
//  AC Check
  if (data_recieved == '1')
  {
    Serial.print(data_recieved);
    delay(500);
//    Send stored temp data
    BTserial.print(String(temp));
    
  }
//  Increase AC
  if (data_recieved == '2')
  {
    Serial.print(data_recieved);
    temp = temp + 1;
    Serial.println(temp);
    servoblue.write(30);
    delay(100);
    servoblue.write(20);
    delay(2000);
     servoblue.write(30);
    delay(10);
    servoblue.write(20);
    BTserial.print(String(temp));
 
    
    
  }
//Decrease data
  if (data_recieved == '3')
  {
    Serial.print(data_recieved);
    temp = temp - 1;
    Serial.println(temp);
    servoblue.write(10);
    delay(100);
    servoblue.write(20);
    delay(2000);
     servoblue.write(10);
    delay(100);
    servoblue.write(20);
     BTserial.print(temp);
    
    
    
  }
  data_recieved = 0;
  

}




}
