
#include<Wire.h>                         
int x = 0;
void setup() {
  // Define the LED pin as Output
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  Serial.begin(9600) ;
}
void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}
void loop() {
  Serial.println(x);
//  Serial.println(x);
  //If value received is 0 blink LED for 200 ms

}
