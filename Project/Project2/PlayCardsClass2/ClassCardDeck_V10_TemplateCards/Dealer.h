/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 28th, 2019, 10:30 AM
 * Purpose:  Dealer Class Specification
 */

#ifndef DEALER_H
#define DEALER_H

#include "Player.h"
#include "Deck.h"

template <class T>
class Dealer:public Player{
    protected:
        Deck<T> *deck;
        unsigned char nDeal;
    public:
        Dealer(string a,unsigned char nCard,
                unsigned char nDl):Player(a){
            deck=new Deck<T>(nCard);
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