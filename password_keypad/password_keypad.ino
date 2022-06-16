#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
 {'1','2','3','A'},
 {'4','5','6','B'},
 {'7','8','9','C'},
 {'*','0','#','D'}
};
byte rowPins[ROWS] = {10, 9, 8, 7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 5, 4, 3}; //connect to the column pinouts of the keypad
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
// 0 == 48, 1 == 49, 2 == 50, 3 == 51, 4 == 52, 5 == 53,  6 == 54, 7 == 55, 8 == 56, 9 == 57
// A == 65, B == 66, C == 67, D == 68, # == 35, * == 42
int password[] = {50, 48, 48, 52,49, 57, 56, 48} ;
int trypass[8];
int count = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  char customKey = customKeypad.getKey();

 if (customKey){
   Serial.println(customKey);
   if (count < 7){
    trypass[count] = (customKey);
    Serial.println(trypass[count]);
    count += 1;
    }
   else{
    int pass = 0;
    for (int i = 0; i <= 7; i++){
      if (password[i] == trypass[i]){
        pass ++;}}
   if (pass == 7){
    Serial.println("Welcome");
    count += 1;}
   else {
    Serial.println("Wrong");
    count = 0;}
    }
 
 }

}
