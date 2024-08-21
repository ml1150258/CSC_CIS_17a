/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   November 4th, 2020
 * Purpose:Chapter 13&14 Example Project
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Card.h"

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    
    //Declare Variables
    Card **deck;
    int nCards=52;
    
    //Initialize the deck
    deck=new Card*[nCards];   //An array of 52 Card Pointers
    for(int i=0;i<nCards;i++){
        deck[i]=new Card(i);  //Creation of each individual card
    }
    
    //Process inputs to outputs/map
    for(int i=0;i<52;i++){
        cout<<i<<" "<<deck[i]->face()<<deck[i]->suit()<<" "
                <<static_cast<int>(deck[i]->value())<<endl;
    }
    
    //Display the results
    
    //Reallocate Memory
    for(int i=0;i<nCards;i++){
        delete i[deck];       //Destruction of each individual card
    }
    delete []deck;            //Destruction of the array of pointers

    //Clean up and exit stage right
    return 0;
}