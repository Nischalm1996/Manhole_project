/*
1. begin
2. int getMq7Value()
*/

#ifndef _MQ7_H
#define _MQ7_H
#include "Arduino.h"

const byte MQ7Pin = A3;

class MQ7
{
    public:
    int getMq7Value()
    {
        return(analogRead(MQ7Pin));
    }
};
#endif //_MQ7_H