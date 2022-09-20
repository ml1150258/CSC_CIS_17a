/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 5th, 2019, 12:36 PM
 * Purpose:  Card Class and Deck
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries
#include "Card.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int nCards=52;
    Card **deck;//Create an array of pointers to represent each Card
 
    //Allocates the Deck
    deck=new Card*[nCards];
    for(char card=0;card<nCards;card++){
        deck[card]=new Card(card);
    }

    //Display the outputs
    for(char card=0;card<nCards;card++){
        cout<<static_cast<int>(card)<<" "<<deck[card]->face()
                <<deck[card]->suit()<<" "
                <<static_cast<int>(deck[card]->value())<<endl;
    }
    
    //Reallocate Memory
    for(char card=0;card<nCards;card++){
        delete deck[card];
    }
    delete []deck;

    //Exit stage right or left!
    return 0;
}