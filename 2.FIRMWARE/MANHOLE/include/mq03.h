/*
1. begin
2. int getMq3Value()
*/

#ifndef _MQ3_H
#define _MQ3_H
#include "Arduino.h"

const byte MQ3Pin = A1;

class MQ3
{
    public:
    int getMq3Value()
    {
        return(analogRead(MQ3Pin));
    }
};
#endif //_MQ3_H