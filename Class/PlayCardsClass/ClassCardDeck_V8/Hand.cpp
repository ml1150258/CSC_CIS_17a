/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 7th, 2020, 12:36 PM
 * Purpose:  Hand Class Implementation
 */

#include "Hand.h"
#include "Card.h"
#include <iostream>
using namespace std;

Hand::Hand(unsigned char *crd,unsigned char n){
    cards=crd;
    nCards=n;
}
        
Hand::~Hand(){
    delete []cards;
}
        
void Hand::display(){
    for(char crd=0;crd<nCards;crd++){
        Card card(cards[crd]);
        cout<<static_cast<int>(cards[crd])<<" "<<card.face()
                <<card.suit()<<" "
                <<static_cast<int>(card.value())<<endl;
    }
}
