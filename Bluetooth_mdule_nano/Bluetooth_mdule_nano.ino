#include <SoftwareSerial.h>

// Define the data transmit/receive pins in Arduino

#define TxD 2

#define RxD 3

char c = 0;



SoftwareSerial mySerial(RxD, TxD); // RX, TX for Bluetooth

void setup() {

mySerial.begin(9600); // For Bluetooth

Serial.begin(9600); // For the IDE monitor Tools -> Serial Monitor

// Any code that you want to run once....

}

void loop() {

// put your main code here, to run repeatedly:
//
//boolean isValidInput; do { byte c; // get the next character from the bluetooth serial port
if (mySerial.available() > 0)// LOOP...
{
c = mySerial.read(); // Execute the option based on the character recieved
Serial.print(c); // Print the character received to the IDE serial monitor



}
}
