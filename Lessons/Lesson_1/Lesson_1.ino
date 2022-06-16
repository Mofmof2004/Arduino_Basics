//cont = a vriable that will not change
//integer
// LED pin on the arduino
// Pin i want to reference is 13
//Tis is a global varaible == varaible accessible in all code
const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  // Able to talk to the serial monitor
  // Open up a port and set 9600 characters per second  
  Serial.begin(9600);

  //Use an LED
  // Reference pin and use it for output 
  // Call LED variable
  pinMode(ledPin, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
  //  Create local varialbes
  //only able to use in loop
  //How much time to turn off and on LED
  //Static == set a valuye one time at the first loop  
  static int delayPeriod = 100;
  //  crate an integer
  static int countDir = 1;
  //Turn on LED
  digitalWrite(ledPin, HIGH);
  //Stay on for a certain amount of time
  delay(delayPeriod);
  //Turn LED off
  digitalWrite(ledPin, LOW);  
  //Stay off for a certain amount of time
  delay(delayPeriod);

  //call function
  countDir  = checkDirChange(delayPeriod, countDir);

  //Change selayperiod
  delayPeriod += 100 * countDir;
  //Print display
  Serial.print("New Wait Time: ");
  // Print integer at same line than above 
  Serial.println(delayPeriod);

}
//Create function
int checkDirChange(int delayPeriod, int countDir){
  //If statments
  //Or == ||  
  if ((delayPeriod == 1000)|| (delayPeriod == 0)){
  // Variable == direction to change
    countDir *= -1;
    if(countDir < 0){
    // Display print
      Serial.println("Going down");
    } else {
      Serial.println("Going up");
    }
  }
  return countDir;
}
