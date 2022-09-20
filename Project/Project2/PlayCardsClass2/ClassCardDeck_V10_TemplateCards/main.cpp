/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 28th, 2020, 12:36 PM
 * Purpose:  Card Class and Deck using an index to the cards
 *           add the Hand
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "Dealer.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int nCards=52;
    unsigned char nDeal=5;
    Dealer<CardPic> dealer("Mary",nCards,nDeal);

    //Display the outputs
    dealer.display();
    
    //Create and Print a hand
    unsigned char nHands=14;
    for(unsigned char numHand=1;numHand<=nHands;numHand++){
        cout<<endl<<"The Hand Delt Number = "<<static_cast<int>(numHand)<<endl;
        Player player("Marko");
        player.setHand(dealer.deal());
        cout<<player.getName()<<"'s Hand"<<endl;
        player.prntHnd();
    }

    //Exit stage right or left!
    return 0;
}