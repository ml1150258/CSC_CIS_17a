/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 5th, 2019, 12:36 PM
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
    Dealer mary("Mary",nCards,nDeal);

    //Display the outputs
    //deck.shuffle();
    mary.display();
    
    //Create and Print a hand
    unsigned char nHands=13;
    Player mark("Mark");
    Player ted("Ted");
    Player gini("Gini");
    for(unsigned char numHand=1;numHand<=nHands;numHand++){
        cout<<endl<<"The Hand Delt Number = "<<static_cast<int>(numHand)<<endl;
        
        mark.setHand(mary.deal());
        //hand.display();
        cout<<mark.getName()<<"'s Hand"<<endl;
        mark.prntHnd();
        
        ted.setHand(mary.deal());
        //hand.display();
        cout<<ted.getName()<<"'s Hand"<<endl;
        ted.prntHnd();
        
        gini.setHand(mary.deal());
        //hand.display();
        cout<<gini.getName()<<"'s Hand"<<endl;
        gini.prntHnd();
        
        mary.setHand(mary.deal());
        //hand.display();
        cout<<mary.getName()<<"'s Hand"<<endl;
        mary.prntHnd();
    }

    //Exit stage right or left!
    return 0;
}