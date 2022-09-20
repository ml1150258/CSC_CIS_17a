/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 5th, 2019, 12:36 PM
 * Purpose:  Card Functions
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
char suit(unsigned char);
char face(unsigned char);
char value(unsigned char);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int nCards=52;
 
    //Initialize or input i.e. set variable values

    //Display the outputs
    for(char card=0;card<nCards;card++){
        cout<<static_cast<int>(card)<<" "<<face(card)<<suit(card)<<" "
                <<static_cast<int>(value(card))<<endl;
    }

    //Exit stage right or left!
    return 0;
}

char value(unsigned char n){  
    n%=13;
    n++;
    return n>10?10:n;
}

char face(unsigned char n){
    char f[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    n%=13;
    return f[n];
}

char suit(unsigned char n){
    char s[]={'S','D','C','H'};
    n%=52;
    n/=13;
    return s[n];
}