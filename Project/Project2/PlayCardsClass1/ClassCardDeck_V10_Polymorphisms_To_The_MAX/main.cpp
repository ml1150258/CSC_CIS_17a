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
    unsigned char nPlayers=4;
    Player **player=new Player*[nPlayers];
    player[0]=new Player("Mark");
    player[1]=new Player("Ted");
    player[2]=new Player("Gini");
    player[3]=&mary;//This is polymorphic behavior in action
    for(unsigned char numHand=1;numHand<=nHands;numHand++){
        cout<<endl<<"The Hand Delt Number = "<<static_cast<int>(numHand)<<endl;
        for(unsigned char cPlayer=0;cPlayer<nPlayers;cPlayer++){
            player[cPlayer]->setHand(mary.deal());
            //hand.display();
            cout<< player[cPlayer]->getName()<<"'s Hand"<<endl;
            player[cPlayer]->prntHnd();
        }
    }
    
    //Recover memory
    for(unsigned char cPlayer=0;cPlayer<nPlayers-1;cPlayer++){
        delete player[cPlayer];
    }
    delete []player;

    //Exit stage right or left!
    return 0;
}