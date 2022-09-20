/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 6, 2020, 11:35 PM
 * Purpose:  Homework Savitch Big C
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    char c;
    
    //Initialize Variables
    cout<<"The Big C program"<<endl;
    cout<<"What letter do you choose to "<<endl;
    cout<<"compose the Big C"<<endl;
    cin>>c;
    
    //Process or map Inputs to Outputs
    
    //Display Outputs
    cout<<" "<<c<<c<<c<<endl;
    cout<<c<<"   "<<c<<endl;
    cout<<c<<endl;
    cout<<c<<endl;
    cout<<c<<"   "<<c<<endl;
    cout<<" "<<c<<c<<c<<endl;

    //Exit stage right!
    return 0;
}