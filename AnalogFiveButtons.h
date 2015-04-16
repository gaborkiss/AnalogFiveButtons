/*
  AnalogFiveButtons class for the analog 5 keys panels
  Version 1.0
  2015 - DataMiner.hu, Gábor Kiss
  V 1.0
*/

#include <inttypes.h>

#define SW1 	1
#define SW2 	2
#define SW3 	3
#define SW4		4
#define SW5		5
#define SW_NO_PUSH		0
#define SW_NO_CHANGE	255

#define BTN_LEFT 			1
#define BTN_UP 				2
#define BTN_DOWN 			3
#define BTN_RIGHT			4
#define BTN_FIRE			5
#define BTN_SELECT			5
#define BTN_NO_PUSH			0
#define BTN_NO_CHANGE	    255


// Module selection
#define KEYES_AD_KEY	0
#define LCD_KEYPAD		1


class AnalogFiveButtons 
{
  public:
	// analogPin : where is the keypad analog pin is connected (A0, A1..)
	// typeOfModule: 0-red Keyes_AD_Key module, 1-LCD Keypad module
	AnalogFiveButtons(uint8_t , uint8_t );
	// Custom defined module
	// Parameters: analogue pin, failure rate, left value, up value, down value, right value, fire value
	AnalogFiveButtons(uint8_t , uint8_t , int , int , int , int , int );
    // Returns:		- actually pressed key (1-5)
	//					- 0 if no key is pressed
    uint8_t getButton();
    // Returns: 	- the changed key (1-5) 
	//					- 0 if no key is pressed
	//					- 255 if nothing is changed
    uint8_t changedButton();
	
  private:
	// Values of buttons
	int _sw1Value, _sw2Value, _sw3Value, _sw4Value, _sw5Value; 
	// The analog pin number (A0, A1...)
    uint8_t _analogPin;
	// Failure Rate,  default 10
    uint8_t _failureRate;
	// Analog port value
    int sensorValue;
    uint8_t oldKey, newKey;
    void init(uint8_t , uint8_t , int , int , int , int , int );
    void evalButton();
};
