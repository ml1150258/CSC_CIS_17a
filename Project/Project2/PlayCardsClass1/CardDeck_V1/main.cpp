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

//Global Constants

//Function Prototypes
char suit(int);
char face(int);
char value(int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    
    //Declare Variables
    
    //Initialize Variables
    
    //Process inputs to outputs/map
    for(int i=0;i<52;i++){
        cout<<i<<" "<<face(i)<<suit(i)<<" "<<static_cast<int>(value(i))<<endl;
    }
    
    //Display the results

    //Clean up and exit stage right
    return 0;
}

char value(int n){
    n>=0?n%=13:0;
    n++;
    if(n>10)n=10;
    return n;
}

char face(int n){
    n>=0?n%=52:0;
    char faces[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    return faces[n%13];
}

char suit(int n){
    n>=0?n%=52:0;
    char suits[]={'S','D','C','H'};
    return suits[n/13];
}