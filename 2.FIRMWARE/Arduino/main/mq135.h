/*
1. begin
2. int getMq135Value()
*/

#ifndef _MQ135_H
#define _MQ135_H
#include "Arduino.h"

const byte MQ135Pin = A0;

class MQ135
{
    public:
    int getMq135Value()
    {
        return(analogRead(MQ135Pin));
    }
};
#endif //_MQ135_H