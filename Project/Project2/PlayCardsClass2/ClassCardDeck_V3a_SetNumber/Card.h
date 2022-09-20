/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 5th, 2019, 12:36 PM
 * Purpose:  Card Class Specification
 */


#ifndef CARD_H
#define CARD_H

class Card{
    private:
        unsigned char crdNum;
    public:
        Card(){setCrdNum(0);}
        Card(unsigned char n){setCrdNum(n);}
        unsigned char suit();
        unsigned char face();
        unsigned char value();
        void setCrdNum(unsigned char n){
            crdNum=n%52;
        }
};


#endif /* CARD_H */

