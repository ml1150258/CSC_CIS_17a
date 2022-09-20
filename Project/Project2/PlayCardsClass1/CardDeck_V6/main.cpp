/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   November 4th, 2019
 * Purpose:Chapter 13&14 Example Project
 * Add the Deck Class
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "Deck.h"

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int nCards=52;
    Deck deck(nCards);
    
    //Process inputs to outputs/map
    deck.shuffle();
    
    //Deal the Cards
    int nDeal=5;
    int *hand;
    
    //Display the Hands
    for(int j=0;j<=13;j++){
        hand=deck.deal(nDeal);
        cout<<endl<<"Hand "<<j<<" contains the following cards"<<endl;
        for(int i=0;i<nDeal;i++){
            Card card(hand[i]);
            cout<<setw(2)<<hand[i]<<" "<<card.face()<<card.suit()<<" "
                 <<setw(2)<<static_cast<int>(card.value())<<endl;
        }
        delete []hand;
    }
    
    //Reallocate Memory

    //Clean up and exit stage right
    return 0;
}