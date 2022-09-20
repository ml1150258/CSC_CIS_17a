/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 7th, 2019, 12:36 PM
 * Purpose:  Hand Class Specification
 */

#ifndef HAND_H
#define HAND_H

class Hand{
    private:
        unsigned char nCards;
        unsigned char *cards;
    public:
        Hand(unsigned char *,unsigned char);
        ~Hand();
        void display();
};

#endif /* HAND_H */