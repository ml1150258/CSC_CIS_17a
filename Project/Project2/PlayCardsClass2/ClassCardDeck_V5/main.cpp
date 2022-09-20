/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 5th, 2019, 12:36 PM
 * Purpose:  Card Class and Deck using an index to the cards
 *           add the shuffle
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Card.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void shuffle(unsigned char *,unsigned char, unsigned char);
unsigned char *deal(unsigned char *,unsigned char,unsigned char);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int nCards=52;
    Card **deck;//Create an array of pointers to represent each Card
    unsigned char *index;
 
    //Allocates the Deck
    deck=new Card*[nCards];
    index=new unsigned char[nCards];
    for(char card=0;card<nCards;card++){
        deck[card]=new Card(card);
        index[card]=card;
    }

    //Display the outputs
    //shuffle(index,nCards,7);
    for(char card=0;card<nCards;card++){
        cout<<static_cast<int>(index[card])<<" "<<deck[index[card]]->face()
                <<deck[index[card]]->suit()<<" "
                <<static_cast<int>(deck[index[card]]->value())<<endl;
    }
    
    //Create and Print a hand
    unsigned char nHands=13;
    unsigned char nDeal=5;
    for(unsigned char numHand=1;numHand<=nHands;numHand++){
        cout<<endl<<"The Hand Delt Number = "<<static_cast<int>(numHand)<<endl;
        unsigned char *hand=deal(index,nCards,nDeal);
        for(char card=0;card<nDeal;card++){
            cout<<static_cast<int>(hand[card])<<" "<<deck[hand[card]]->face()
                    <<deck[index[card]]->suit()<<" "
                    <<static_cast<int>(deck[hand[card]]->value())<<endl;
        }
        delete []hand;
    }
    
    //Reallocate Memory
    for(char card=0;card<nCards;card++){
        delete deck[card];
    }
    delete []deck;
    delete []index;

    //Exit stage right or left!
    return 0;
}

unsigned char *deal(unsigned char * indx,unsigned char nSize,unsigned char nDeal){
    //Create a hand
    static unsigned char delt=0;
    if(nDeal>=nSize-delt){
        shuffle(indx,nSize,7);
        delt=0;
    }
    unsigned char *hand=new unsigned char[nDeal];
    for(unsigned char i=0;i<nDeal;i++){
        hand[i]=indx[delt++];
    }
    return hand;
}

void shuffle(unsigned char *indx,unsigned char nSize, unsigned char nShuf){
    for(int i=1;i<=nShuf;i++){
        for(int j=0;j<nSize;j++){
            unsigned char tmpRnd=rand()%nSize;
            unsigned char temp=indx[j];
            indx[j]=indx[tmpRnd];
            indx[tmpRnd]=temp;
        }
    }
}