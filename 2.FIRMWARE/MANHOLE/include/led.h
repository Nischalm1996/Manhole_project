#ifndef _LED_H
#define _LED_H
#include "Arduino.h"

const byte red = 1;
const byte green = A7;
const byte blue = A6;
class Led
{
public:
    int _pin;

    void begin()
    {
        pinMode(red, OUTPUT);
        pinMode(green, OUTPUT);
        pinMode(blue, OUTPUT);
    }
    void redOn()
    {
        digitalWrite(red, HIGH);
    }
    void redOff()
    {
        digitalWrite(red, LOW);
    }
    void blueOn()
    {
        analogWrite(blue,255);
    }
    void blueOff()
    {
        analogWrite(blue,0);
    }
    void greenOn()
    {
        analogWrite(green,255);
    }
    void greenOff()
    {
        analogWrite(green,0);
    }
    void Green(int tym)
    {
         analogWrite(green,255);
         delay(tym);
         analogWrite(green,0);
    }
    void Red(int tym)
    {
         analogWrite(red,255);
         delay(tym);
         analogWrite(red,0);
    }
    void Blue(int tym)
    {
         analogWrite(blue,255);
         delay(tym);
         analogWrite(blue,0);
    }
};