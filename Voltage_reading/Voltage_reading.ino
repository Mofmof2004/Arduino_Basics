#include <IRremote.h>

const int RECV_PIN = 3;
String RECV_DATA = "";
bool Up_lamp_1 = false;
bool Up_lamp_2 = false;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
//  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
    RECV_DATA = String(results.value,HEX);
    
    if ( RECV_DATA != "ffffffff")
    {
      Serial.println(RECV_DATA);
//        Serial.println(results.value, HEX);
        irrecv.resume();
    }
    else{
      irrecv.resume();}

    if (RECV_DATA == "f700ff")
//    Turn on 1 upper lamp
    {
      Serial.print("Upper 1 Lamp: ");
      Up_lamp_1 = !Up_lamp_1;
      Serial.println(Up_lamp_1);}
    else  if (RECV_DATA == "f7807f")
//    Turn on upper 2 lamp
    {
      Serial.print("Upper 2 Lamp: ");
      Up_lamp_2 = !Up_lamp_2;
      Serial.println(Up_lamp_2);
      }
    else  if (RECV_DATA == "f740bf")
//    Turn on upper 2 lamp
    {
      Serial.println("Main Lamp off");}
    else  if (RECV_DATA == "f7c03f")
//    Turn on upper 2 lamp
    {
      Serial.println("Main lamps ON");}
      delay(100);
    
  }
  
}
