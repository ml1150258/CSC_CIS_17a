/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   November 4th, 2019
 * Purpose:Deck Class Specification
 */


#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck{
    private:
        int nCards;
        int nShufle;
        int nDelt;
        Card **card;
        int *index;
    public:
        Deck(int n);
        ~Deck();
        void shuffle();
        int *deal(int);
};

#endif /* DECK_H */

