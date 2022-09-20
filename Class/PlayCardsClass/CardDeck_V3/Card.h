/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   November 4th, 2020
 * Purpose:Card Class Specification
 */

#ifndef CARD_H
#define CARD_H

class Card{
    private:
        unsigned char crdNum;
    public:
        Card(unsigned char);
        char suit();
        char face();
        char value();
        char getCrdNm(){return crdNum;}
};


#endif /* CARD_H */

