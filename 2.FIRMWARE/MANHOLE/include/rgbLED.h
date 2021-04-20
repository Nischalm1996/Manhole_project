/************************************************
* rgbLED.h : header file to interface rgbLED class
* 
*
*
*/

#include "Arduino.h"

#define redPIN    A5  // 19
#define greenPIN  A6 // 20
#define bluePIN   A7 // 21  

class rgbLED
{

  public:  int blinkSpeed = 500; // Helps to control the speed of color transition, default speed hlaf second
  
  /* Initialized by passing pin numbers of RGB LED */
  rgbLED();
  ~rgbLED();

  void init();  // RGB Led Pin initialization
  void redBlink();  // Blink red color alone
  void greenBlink(); // Blink green color alone
  void blueBlink(); // Blink blue color alone
  /* use below funtion if you want to blink any specific color */
  void rgbBLink(int r, int g, int b);  // Blink rgb color once
  void setBlinkSpeed(int delay_val);  // sets the LED blink speed
  
  void startLedAnnimations(int FADESPEED); //color transistion annimation
  void rgbLEDBlink();
  /* delay function using millis() */
  void delay_ms(int period);
};
