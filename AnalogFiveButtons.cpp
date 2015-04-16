/*
 AnalogFiveButtons class for the analog 5 keys panels
 Version 1.0

 Copyright (c) 2015 - Kiss Gábor (kiss-gabor@outlook.hu)

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
*/


#include <inttypes.h>
#include <Arduino.h>
#include "AnalogFiveButtons.h"


#define DEFAULT_FAILURE_RATE		10



// analogPin : where is the keypad OUT pin connected (A0, A1..)
// typeOfModule: 0-red Keyes_AD_Key module, 1-LCD Keypad module
AnalogFiveButtons::AnalogFiveButtons(uint8_t analogPin, uint8_t typeOfModule)
{
	if(typeOfModule == KEYES_AD_KEY) {
		
		// Default values for the Keyes_AD_Key module
		// Parameters: analog pin, failure rate,                          left, up,  down, right, fire
		init(                 analogPin, DEFAULT_FAILURE_RATE, 0,   140, 320,   500,  740);
		
	}  else if(typeOfModule == LCD_KEYPAD) {
		
		// Default values for the LCD Keypad module
		// Parameters: analog pin, failure rate, 		                left,  up,   down, right, fire
		init(				  analogPin, DEFAULT_FAILURE_RATE, 480, 130, 305,   0,      720);	
	}
}



// Custom defined module
// Parameters: analogue pin, failure rate, left, up, down, right, fire values
AnalogFiveButtons::AnalogFiveButtons(uint8_t analogPin, uint8_t failureRate, int sw1Value, int sw2Value, int sw3Value, int sw4Value, int sw5Value)
{
	init(analogPin, failureRate, sw1Value, sw2Value, sw3Value, sw4Value, sw5Value);
}



void AnalogFiveButtons::init(uint8_t analogPin, uint8_t failureRate, int sw1Value, int sw2Value, int sw3Value, int sw4Value, int sw5Value)
{
	analogReference(DEFAULT);
	
	_analogPin = analogPin;
	_failureRate = failureRate;
	_sw1Value = sw1Value; 
	_sw2Value = sw2Value; 
	_sw3Value = sw3Value; 
	_sw4Value = sw4Value; 
	_sw5Value = sw5Value; 
    sensorValue = 0;
    oldKey = 1;
    newKey = 0;
}


void AnalogFiveButtons::evalButton()
{
  // Key reset
  newKey = SW_NO_PUSH;
  
  sensorValue = analogRead(_analogPin);
  
  if( (sensorValue > (_sw5Value - _failureRate)) && (sensorValue < (_sw5Value + _failureRate)) )		newKey = 5;  // Fire
  if( (sensorValue > (_sw4Value - _failureRate)) && (sensorValue < (_sw4Value + _failureRate)) )		newKey = 4;  // Right
  if( (sensorValue > (_sw3Value - _failureRate)) && (sensorValue < (_sw3Value + _failureRate)) )		newKey = 3;  // Down
  if( (sensorValue > (_sw2Value - _failureRate)) && (sensorValue < (_sw2Value + _failureRate)) )		newKey = 2;  // Up
  if( (sensorValue > (_sw1Value - _failureRate)) && (sensorValue < (_sw1Value + _failureRate)) )		newKey = 1;  // Left
}


uint8_t AnalogFiveButtons::getButton()
{
  evalButton();
  
  return newKey;
}


uint8_t AnalogFiveButtons::changedButton()
{
  evalButton();
  
  if(oldKey == newKey)
  {
    // Nothing is changed
    newKey = SW_NO_CHANGE;
  } else {
    oldKey = newKey;
  }
  
  return newKey;
}
