/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 5th, 2019, 12:36 PM
 * Purpose:  Card Class and Deck using an index to the cards
 *           add the shuffle
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "Deck.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int nCards=52;
    Deck deck(nCards);

    //Display the outputs
    //deck.shuffle();
    deck.display();
    
    //Create and Print a hand
    unsigned char nHands=13;
    unsigned char nDeal=5;
    for(unsigned char numHand=1;numHand<=nHands;numHand++){
        cout<<endl<<"The Hand Delt Number = "<<static_cast<int>(numHand)<<endl;
        unsigned char *hand=deck.deal(nDeal);
        for(char crd=0;crd<nDeal;crd++){
            Card card(hand[crd]);
            cout<<static_cast<int>(hand[crd])<<" "<<card.face()
                    <<card.suit()<<" "
                    <<static_cast<int>(card.value())<<endl;
        }
        delete []hand;
    }
    
    //Reallocate Memory

    //Exit stage right or left!
    return 0;
}
