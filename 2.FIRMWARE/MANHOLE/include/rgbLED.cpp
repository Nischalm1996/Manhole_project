/************************************************
* rgbLED : class to interface RGB LED.
* 
*
*
*/
#include "rgbLED.h"

rgbLED::rgbLED()
{
  // do nothing
}
rgbLED::~rgbLED()
{
  // do nothing
}

/* Initialized by passing pin numbers of RGB LED */
void rgbLED::init()
{
  pinMode(redPIN , OUTPUT);
  pinMode(greenPIN , OUTPUT);
  pinMode(bluePIN , OUTPUT);
}

/* Blink red color LED alone */
void rgbLED::redBlink()
{
  analogWrite(redPIN , 255 );
  delay_ms(blinkSpeed);
  analogWrite(redPIN , 0);
}
/* Blink green color LED alone */
void rgbLED::greenBlink()
{
  analogWrite(greenPIN , 255 );
  delay_ms(blinkSpeed);
  analogWrite(greenPIN , 0);
}
/* Blink blue color LED alone */
void rgbLED::blueBlink()
{
  analogWrite(bluePIN , 255 );
  delay_ms(blinkSpeed);
  analogWrite(bluePIN , 0 );
}
/* Blink RGB color LED once */ /* use funtion if you want to blink any specific color */
void rgbLED::rgbBLink(int r, int g, int b)
{
  analogWrite(redPIN , r);
  analogWrite(greenPIN , g);
  analogWrite(bluePIN , b);
  delay_ms(blinkSpeed);

  analogWrite(redPIN , 0);
  analogWrite(greenPIN , 0);
  analogWrite(bluePIN , 0);
}

/* Set LED blink speed */ // delay in milliseconds
void rgbLED::setBlinkSpeed(int delay_val)
{
  blinkSpeed = delay_val;
}

void rgbLED::rgbLEDBlink()
{
  
}

/* send annimation speed as input */
void rgbLED::startLedAnnimations(int FADESPEED)
{
  int r =0, g =0, b =0;
    // fade from blue to violet
  for (r = 0; r < 256; r++) { 
    analogWrite(redPIN, r);
    delay_ms(FADESPEED);
  } 
  // fade from violet to red
  for (b = 255; b > 0; b--) { 
    analogWrite(bluePIN, b);
    delay_ms(FADESPEED);
  } 
  // fade from red to yellow
  for (g = 0; g < 256; g++) { 
    analogWrite(greenPIN, g);
    delay_ms(FADESPEED);
  } 
  // fade from yellow to green
  for (r = 255; r > 0; r--) { 
    analogWrite(redPIN, r);
    delay_ms(FADESPEED);
  } 
  // fade from green to teal
  for (b = 0; b < 256; b++) { 
    analogWrite(bluePIN, b);
    delay_ms(FADESPEED);
  } 
  // fade from teal to blue
  for (g = 255; g > 0; g--) { 
    analogWrite(greenPIN, g);
    delay_ms(FADESPEED);
  } 
  
}

/* delay_ms function using millis() *///period in milliseconds
void rgbLED::delay_ms(int period)
{
  unsigned long time_now = millis();
  while(millis() < (time_now + period)){
   //wait approx. [period] ms
    }
  
}
// end of class definition
