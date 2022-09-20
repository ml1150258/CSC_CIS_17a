/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   November 4th, 2019
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
    
    //Initialize Variables
    
    //Process inputs to outputs/map
    for(int i=0;i<52;i++){
        Card card(i);
        cout<<i<<" "<<card.face()<<card.suit()<<" "
                <<static_cast<int>(card.value())<<endl;
    }
    
    //Display the results

    //Clean up and exit stage right
    return 0;
}