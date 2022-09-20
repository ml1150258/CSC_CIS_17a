/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 30, 2022, 11:30 AM
 * Purpose:  C++ Template
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions const to follow

//Function Prototypes

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
  
    
    //Initialize Variables
   
    
    //Map inputs to outputs -> i.e. process the inputs
    
    //Display the outputs
    for(int i=0;i<26;i++){
        char letter='a'+i;
        cout<<"lower case "<<static_cast<char>(letter)<<" vs. upper case "
                <<static_cast<char>(letter-32)<<endl;
    }
    for(int i=0;i<=127;i++){
        cout<<static_cast<char>(i);
        if(i%32==31)cout<<endl;
    }
        
    //Clean up - File closing, memory deallocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations