/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   November 4th, 2019
 * Purpose:Deck Class Specification
 */

#include <cstdlib>
#include <ctime>

#include "Deck.h"

Deck::Deck(int n){
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Initialize all Properties of the Class
    nCards=(n>=0?n:52);
    nShufle=7;
    nDelt=0;
    index=new int[nCards];
    card=new Card*[nCards];   //An array of 52 Card Pointers
    for(int i=0;i<nCards;i++){
        card[i]=new Card(i);  //Creation of each individual card
        index[i]=i;
    }
}

Deck::~Deck(){
    for(int i=0;i<nCards;i++){
        delete card[i];
    }
    delete []card;
    delete []index;
}
        
void Deck::shuffle(){
    for(int i=1;i<=nShufle;i++){
        for(int j=0;j<nCards;j++){
            int temp=rand()%nCards;
            int card=index[j];
            index[j]=index[temp];
            index[temp]=card;
        }
    }
}
        
int *Deck::deal(int n){
    int crdNHnd=n>0?n:5;
    int *hand=new int[crdNHnd];
    if(crdNHnd>nCards-nDelt){
        shuffle();
        nDelt=0;
    }
    for(int i=0;i<crdNHnd;i++){
        hand[i]=index[nDelt++];
    }
    return hand;
}