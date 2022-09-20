/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 12th, 2020, 10:30 AM
 * Purpose:  Dealer Class inherited from the Player
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
        Dealer(string name, unsigned nCards,
                unsigned nDeal):Player(name){
            deck=new Deck(nCards);
            this->nDeal=nDeal;
        }
        ~Dealer(){delete deck;}
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
};

#endif /* DEALER_H */