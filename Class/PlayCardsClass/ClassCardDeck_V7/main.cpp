/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 5th, 2020, 12:36 PM
 * Purpose:  Card Class and Deck using an index to the cards
 *           add the Hand
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "Deck.h"
#include "Hand.h"

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
        Hand hand(deck.deal(nDeal),nDeal);
        hand.display();
    }
    
    //Reallocate Memory

    //Exit stage right or left!
    return 0;
}
