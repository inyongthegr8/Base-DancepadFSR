// Sketch for In The Groove play on FSR pad
// You will need an Arduino with access to the keyboard library

// This code was written with example code from the Adafruit FSR tutorial
// https://learn.adafruit.com/force-sensitive-resistor-fsr/using-an-fsr

// Libraries
#include <Joystick.h>

Joystick_ Joystick;

// FSR connection variables
// These numbers correlate to the analog inputs on the arduino
int fsrPinDownArrow = 2;   
int fsrPinUpArrow = 0;
int fsrPinLeftArrow = 4;
int fsrPinRightArrow = 1;

// The reading variables for each arrow
int fsrReadingDownArrow;  
int fsrReadingUpArrow;   
int fsrReadingLeftArrow;  
int fsrReadingRightArrow;  

// The sensitivity at wich arrows activate, change to a lower number for a higher sensitivity
int fsrActivateDownArrow = 955;
int fsrActivateRightArrow = 995;
int fsrActivateLeftArrow = 973;
int fsrActivateUpArrow = 920;

// Setup
void setup(void) 
{   
  Joystick.begin();
}

// Runtime loop
void loop(void) 
{
 //instances of fsrReading
 fsrReadingDownArrow = analogRead(fsrPinDownArrow);
 fsrReadingUpArrow = analogRead(fsrPinUpArrow);
 fsrReadingLeftArrow = analogRead(fsrPinLeftArrow);
 fsrReadingRightArrow = analogRead(fsrPinRightArrow);
 
 // if statement that sends the keystroke for the UP arrow
 if (fsrReadingUpArrow > fsrActivateUpArrow) 
 {
    Joystick.pressButton(2);
 }
 // Releases the UP arrow if the sensitivity is smaller than (activation point - 10)
 else if (fsrReadingUpArrow < fsrActivateUpArrow - 10)
 {
    Joystick.releaseButton(2);
 }

 // if statement that sends the keystroke for the LEFT arrow
 if (fsrReadingLeftArrow > fsrActivateLeftArrow) 
 {
    Joystick.pressButton(0);
 }
 // Releases the LEFT arrow if the sensitivity is smaller than (activation point - 10)
 else if (fsrReadingLeftArrow < fsrActivateLeftArrow - 10)
 {
    Joystick.releaseButton(0);
 }

 // if statement that sends the keystroke for the RIGHT arrow
 if (fsrReadingRightArrow > fsrActivateRightArrow) 
 {
    Joystick.pressButton(3);
 }
 // Releases the RIGHT arrow if the sensitivity is smaller than (activation point - 10)
 else if (fsrReadingRightArrow < fsrActivateRightArrow - 10)
 {
    Joystick.releaseButton(3);
 }

 // if statement that sends the keystroke for the DOWN arrow
 if (fsrReadingDownArrow > fsrActivateDownArrow) 
 {
    Joystick.pressButton(1);
 }
 // Releases the DOWN arrow if the sensitivity is smaller than (activation point - 10)
 else if (fsrReadingDownArrow < fsrActivateDownArrow - 10)
 {
    Joystick.releaseButton(1);
 }
}
