# AnalogFiveButtons - Kiss Gábor (kiss-gabor@outlook.hu)

Library for the Arduino analog five keys panels
-----------------------------------------------

It is compatible with modules, they have five buttons, Vcc, Gnd and analog Out pins.
Two arduino modules are tested:
1. http://www.tinydeal.com/ad-keyboard-simulate-five-key-module-red-yellow-p-128026.html (KEYES_AD_KEY)
2. http://www.tinydeal.com/lcd-1602-keypad-shield-lcd1602-expansion-board-building-blocks-p-114593.html (LCD_KEYPAD)


Usage
-----
Only install the files in your Arduino library directory. (\libraries\AnalogFiveButtons)

You can include it in your sketch:
#include <AnalogFiveButtons.h>


Class init
----------

Predefined arduino modules

Parameters:
- arduino_analog_pin: A0, A1..
- arduino_module: KEYES_AD_KEY or LCD_KEYPAD
AnalogFiveButtons a5b(arduino_analog_pin, arduino_module);


Custom arduino modul

Parameters:
- arduino_analog_pin: A0, A1..
- failureRate: in my measurement min. 2, but 10 is stable
- sw1Value..sw5Value: left, up, down, right, fire analogRead values
AnalogFiveButtons a5b(arduino_analog_pin, failureRate, sw1Value, sw2Value, sw3Value, sw4Value, sw5Value);


Functions
---------

You can use the predefined variables:
#define BTN_LEFT 				1
#define BTN_UP 					2
#define BTN_DOWN 				3
#define BTN_RIGHT				4
#define BTN_FIRE				5
#define BTN_SELECT			5
#define BTN_NO_PUSH			0
#define BTN_NO_CHANGE	255


Returns:		- actually pressed key (1-5)
					  - 0 if no key is pressed (BTN_NO_PUSH)
uint8_t getButton();


Returns: 	- the changed key (1-5) 
					- 0 if no key is pressed (BTN_NO_PUSH)
					- 255 if nothing is changed (BTN_NO_CHANGE)
uint8_t changedButton();

