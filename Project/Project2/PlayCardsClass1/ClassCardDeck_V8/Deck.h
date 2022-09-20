/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 7th, 2019, 12:36 PM
 * Purpose:  Deck Class Specification
 */

#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck{
    private:
        unsigned char nCards;
        unsigned char nShufle;
        unsigned char nDelt;
        unsigned char *index;
        Card **card;
    public:
        Deck(unsigned char);
        ~Deck();
        void shuffle();
        unsigned char*deal(unsigned char);
        void display();
};


#endif /* DECK_H */

