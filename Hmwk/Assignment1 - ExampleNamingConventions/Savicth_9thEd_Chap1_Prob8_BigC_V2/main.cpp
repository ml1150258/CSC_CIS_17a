/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 6, 2020, 11:35 PM
 * Purpose:  Homework Savitch Big C
 * Input a integer value
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
    short sc;
    
    //Initialize Variables
    cout<<"The Big C program"<<endl;
    cout<<"What letter do you choose to "<<endl;
    cout<<"compose the Big C"<<endl;
    cout<<"Input the integer value for the ascii code"<<endl;
    cin>>sc;
    
    //Process or map Inputs to Outputs
    
    //Display Outputs
    char c=sc; 
    cout<<" "<<c<<c<<c<<endl;
    cout<<c<<"   "<<c<<endl;
    cout<<c<<endl;
    cout<<c<<endl;
    cout<<c<<"   "<<c<<endl;
    cout<<" "<<c<<c<<c<<endl;

    //Exit stage right!
    return 0;
}