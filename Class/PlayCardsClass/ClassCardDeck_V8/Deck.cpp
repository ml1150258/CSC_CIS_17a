/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 7th, 2020, 12:36 PM
 * Purpose:  Deck Class Implementation
 */

#include "Deck.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Deck::Deck(unsigned char n){
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Initialize the card properties
    nCards=n>0?n:52;
    nShufle=7;
    nDelt=0;
    index=new unsigned char[nCards];
    card=new Card*[nCards];
    for(unsigned char crd=0;crd<nCards;crd++){
        card[crd]=new Card(crd);
        index[crd]=crd;
    }
}
   

Deck::~Deck(){
    delete []index;
    for(unsigned char crd=0;crd<nCards;crd++){
        delete card[crd];
    }
    delete []card;
}
        
void Deck::shuffle(){
    for(int i=1;i<=nShufle;i++){
        for(int j=0;j<nShufle;j++){
            unsigned char tmpRnd=rand()%nCards;
            unsigned char temp=index[j];
            index[j]=index[tmpRnd];
            index[tmpRnd]=temp;
        }
    }
}
        
unsigned char*Deck::deal(unsigned char nDeal){
    //Create a hand
    if(nDeal>=nCards-nDelt){
        shuffle();
        nDelt=0;
    }
    unsigned char *hand=new unsigned char[nDeal];
    for(unsigned char i=0;i<nDeal;i++){
        hand[i]=index[nDelt++];
    }
    return hand;
}

void Deck::display(){
    for(unsigned char crd=0;crd<nCards;crd++){
        cout<<static_cast<int>(index[crd])<<" "<<card[index[crd]]->face()
                <<card[index[crd]]->suit()<<" "
                <<static_cast<int>(card[index[crd]]->value())<<endl;
    }
}