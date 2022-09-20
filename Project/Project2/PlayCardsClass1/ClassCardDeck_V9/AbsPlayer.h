/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 12th, 2019, 10:30 AM
 * Purpose:  Abstract Player Class Specification
 */


#ifndef ABSPLAYER_H
#define ABSPLAYER_H

#include <string>
using namespace std;

#include "Hand.h"

class AbsPlayer{
    public:
        virtual void setHand(Hand *) = 0;
        virtual string getName() = 0;
        virtual void prntHnd() = 0;
};


#endif /* ABSPLAYER_H */