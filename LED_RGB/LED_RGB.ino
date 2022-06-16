int LEDblue = 3;
int LEDred = 5;
int LEDgreen = 6;
int LEDblue1 = 9;
int LEDred1 = 10;
int LEDgreen1 = 11;
int b = 1000;

int brightnessblue = 255;
int brightnessred = 255;
int brightnessgreen = 255;
int dark = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDblue, OUTPUT);
  pinMode(LEDred, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
}

void loop() {

    analogWrite(LEDgreen, brightnessgreen);
    analogWrite(LEDred, brightnessred);
    analogWrite(LEDblue, brightnessblue);
    

 
  

}
