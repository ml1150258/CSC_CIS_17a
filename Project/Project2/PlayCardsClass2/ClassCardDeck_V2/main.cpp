/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 5th, 2019, 12:36 PM
 * Purpose:  Card Class
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
 
    //Initialize or input i.e. set variable values

    //Display the outputs
    for(char card=0;card<nCards;card++){
        Card tstCard(card);
        cout<<static_cast<int>(card)<<" "<<tstCard.face()<<tstCard.suit()<<" "
                <<static_cast<int>(tstCard.value())<<endl;
    }

    //Exit stage right or left!
    return 0;
}