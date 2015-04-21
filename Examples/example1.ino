#include <AnalogFiveButtons.h>

// A0 pin
AnalogFiveButtons a5b(A0, LCD_KEYPAD);

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  byte key = a5b.changedButton();
//  byte key = a5k.getButton();
  if(key < SW_NO_CHANGE) 
    Serial.println(key);
  
  delay(100);        // delay in between reads for stability
}



