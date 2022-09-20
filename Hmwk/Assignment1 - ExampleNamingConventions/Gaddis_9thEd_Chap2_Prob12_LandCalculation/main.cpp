/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 8, 2020, 11:05 AM
 * Purpose:  Calculate Areas
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const float CNVACRE=43560;//43560 square feet in an acre
const float CNVMILE=5280;//Mile = 5280 feet
const float CNVHETR=0.404686;//Hectares per acre
//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    float feet2=0,acres=0,qnty;
    char option;
    
    //Initialize Variables
    cout<<"Land Conversion"<<endl;
    cout<<"Type 1 for acres to feet"<<endl;
    cout<<"Type 2 for feet to acres"<<endl;
    cin>>option;
    cout<<"Input Quantity to Convert"<<endl;
    cin>>qnty;
    
    //Process or map Inputs to Outputs
    feet2=(option=='2'?qnty:0);
    acres=(option=='1'?qnty:0);
    
    acres=(acres==0?feet2/CNVACRE:acres);
    feet2=(feet2==0?acres*CNVACRE:feet2);
    
    //Display Results
    cout<<feet2<<" ft^2"<<endl;
    cout<<acres<<" acres"<<endl;
    cout<<feet2/CNVMILE/CNVMILE<<" miles^2"<<endl;
    cout<<acres*CNVHETR<<" hectares"<<endl;
    
    //Exit stage right!
    return 0;
}