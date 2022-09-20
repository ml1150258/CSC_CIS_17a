/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 7, 2020, 11:10 PM
 * Purpose:  Savitch Homework 1 Chapter 1 Problem 3
 * Add up the change, display the total
 * Number of Coins represented as Characters
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
    const unsigned char QTRVAL=25; //Value of a Quarter = 25 cents
    const unsigned char DIMEVAL=10;//Value of a Dime = 10 cents
    const unsigned char NKLVAL=5;  //Value of a Nickel = 5 cents
    const unsigned char PNYVAL=1;  //Value of a Penny = 1 cent
    const unsigned char CNVDOL=100;//Conversion of cents to dollars
    unsigned char nQtr,nDimes,nNickls,nPenys;//Number for each coin
    unsigned short totChng;//Total amount of change in cents
    
    //Initialize Variables, input number of coins
    cout<<"This program calculates the change in your pocket!"<<endl;
    cout<<"Input the number of Quarters, Dimes, Nickels and Pennies"<<endl;
    cout<<"Each in the range of 0 to 9"<<endl;
    cin>>nQtr>>nDimes>>nNickls>>nPenys;
    
    //Process or map Inputs to Outputs
    totChng = (nQtr-48)*QTRVAL + (nDimes-'0')*DIMEVAL + 
              (nNickls-48)*NKLVAL + (nPenys-'0')*PNYVAL;
    
    //Display Outputs
    cout<<"The total change = "<<totChng<<" cents"<<endl;
    cout<<"The total change = $"<<1.0f*totChng/CNVDOL<<endl;

    //Exit stage right!
    return 0;
}