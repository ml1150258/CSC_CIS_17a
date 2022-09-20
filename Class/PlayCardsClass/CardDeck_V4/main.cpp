/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   November 4th, 2020
 * Purpose:Chapter 13&14 Example Project
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Card.h"

//Global Constants

//Function Prototypes
void shuffle(int *,int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    Card **deck;
    int nCards=52;
    
    //Initialize the deck
    int *indx=new int[nCards];
    deck=new Card*[nCards];   //An array of 52 Card Pointers
    for(int i=0;i<nCards;i++){
        deck[i]=new Card(i);  //Creation of each individual card
        indx[i]=i;
    }
    
    //Process inputs to outputs/map
    shuffle(indx,nCards,7);
    for(int i=0;i<nCards;i++){
        cout<<indx[i]<<" "<<deck[indx[i]]->face()<<deck[indx[i]]->suit()<<" "
                <<static_cast<int>(deck[indx[i]]->value())<<endl;
    }
    
    //Display the results
    
    //Reallocate Memory
    for(int i=0;i<nCards;i++){
        delete deck[i];       //Destruction of each individual card
    }
    delete []deck;            //Destruction of the array of pointers
    delete []indx;

    //Clean up and exit stage right
    return 0;
}

void shuffle(int *indx,int n,int nShuf){
    for(int i=1;i<=nShuf;i++){
        for(int j=0;j<n;j++){
            int temp=rand()%n;
            int card=indx[j];
            indx[j]=indx[temp];
            indx[temp]=card;
        }
    }
}