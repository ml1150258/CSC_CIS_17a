/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 14th, 2020, 11:32 AM
 * Purpose:  Time calculator/converter
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cstdlib>   //Random Number
#include <ctime>     //Time Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const int  MINUTE=60;     //How many seconds in a minute
const int  HOUR=60*MINUTE;//How many seconds in a hour
const int  DAY=24*HOUR;   //How many seconds in a day
const int  WEEK=7*DAY;    //How many seconds in a week
const int  YEAR=52*WEEK;  //How many seconds in a year

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    int nSecs;//Number of seconds to convert
    int nYrs,nMnths,nWks,nDys,nHrs,nMin;
    
    //Initialize variables
    cout<<"This program converts seconds to Years/Months/Weeks/Days/Hours"<<endl;
    cout<<"Input the number of seconds for the conversion/equivalence"<<endl;
    nSecs=rand()*rand();
    cout<<nSecs<<" seconds"<<endl;
    
    //Map inputs to outputs or process the data
    nYrs=nSecs/YEAR;          //Number of Years
    cout<<nYrs<<" Years (";
    nSecs-=nYrs*YEAR;         //Subtract the yearly seconds from remaining
    
    nWks=nSecs/WEEK;          //Number of weeks
    cout<<nWks<<" Weeks or ";
    nMnths=nWks*3/13;         //Convert number of weeks to months
    cout<<nMnths<<" Months ) ";
    nSecs-=nWks*WEEK;         //Subtract the weekly seconds from remaining
    
    nDys=nSecs/DAY;           //Number of days
    cout<<nDys<<" Days ";
    nSecs-=nDys*DAY;          //Subtract the daily seconds from remaining
    
    nHrs=nSecs/HOUR;          //Number of hours
    cout<<nHrs<<" Hours ";
    nSecs-=nHrs*HOUR;         //Subtract the hourly seconds from remaining
    
    nMin=nSecs/MINUTE;        //Number of minutes
    cout<<nMin<<" Minutes ";
    
    nSecs-=nMin*MINUTE;       //Remaining number of seconds
    cout<<nSecs<<" Seconds";
    
    //Exit stage right!
    return 0;
}