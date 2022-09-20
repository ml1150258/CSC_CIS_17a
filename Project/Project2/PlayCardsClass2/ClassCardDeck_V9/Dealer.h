/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 18th, 2019, 10:30 AM
 * Purpose:  Dealer Class Specification
 */

#ifndef DEALER_H
#define DEALER_H

#include "Player.h"
#include "Deck.h"

class Dealer:public Player{
    protected:
        Deck *deck;
        unsigned char nDeal;
    public:
        Dealer(string a,unsigned char nCard,
                unsigned char nDl):Player(a){
            deck=new Deck(nCard);
            nDeal=nDl;
        };
        ~Dealer(){
            delete deck;
        }
        Hand *deal(){
            Hand *hand=new Hand(deck->deal(nDeal),nDeal);
            return hand;
        }
        void display(){
            deck->display();
        }
        void shuffle(){
            deck->shuffle();
        }
        unsigned char getNdl(){
            return nDeal;
        }
};

#endif /* DEALER_H */