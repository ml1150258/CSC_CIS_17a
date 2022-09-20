/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   November 4th, 2020
 * Purpose:Deck Class Template Specification and Implementation
 */


#ifndef DECK_H
#define DECK_H

#include <cstdlib>
#include <ctime>

#include "CardPic.h"

template<class T>
class Deck{
    private:
        int nCards;
        int nShufle;
        int nDelt;
        T **card;
        int *index;
    public:
        Deck(int n);
        ~Deck();
        void shuffle();
        int *deal(int);
};

template<class T>
Deck<T>::Deck(int n){
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Initialize all Properties of the Class
    nCards=(n>=0?n:52);
    nShufle=7;
    nDelt=0;
    index=new int[nCards];
    card=new T*[nCards];   //An array of 52 Card Pointers
    for(int i=0;i<nCards;i++){
        card[i]=new T(i);  //Creation of each individual card
        index[i]=i;
    }
}

template<class T>
Deck<T>::~Deck(){
    for(int i=0;i<nCards;i++){
        delete card[i];
    }
    delete []card;
    delete []index;
}
 
template<class T>
void Deck<T>::shuffle(){
    for(int i=1;i<=nShufle;i++){
        for(int j=0;j<nCards;j++){
            int temp=rand()%nCards;
            int card=index[j];
            index[j]=index[temp];
            index[temp]=card;
        }
    }
}
      
template<class T>
int *Deck<T>::deal(int n){
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

#endif /* DECK_H */

