/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 28th, 2020, 12:36 PM
 * Purpose:  Card Class Specification
 */

#ifndef CARDPIC_H
#define CARDPIC_H
#include "Card.h"
#include <string>
using namespace std;

class CardPic:public Card{
    public:
        CardPic(unsigned char);
        string getFile();
};

#endif /* CARDPIC_H */