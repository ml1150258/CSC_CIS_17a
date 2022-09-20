/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 21st, 2020, 2:00 PM
 * Purpose:  Time calculator/converter
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <ctime>     //Time Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

#include "TimeMEL.h"

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    int nSecs;//Number of seconds to convert
    int nHrs,nMin;//Number of hours and minutes
    char dummy;
    
    //Initialize variables
    cout<<"This program converts seconds to Years/Months/Weeks/Days/Hours"<<endl;
    cout<<"Input the number of hrs, min, secs"<<endl;
    cin>>nHrs>>nMin>>nSecs;
    
    //Map inputs to outputs or process the data
    TimeMEL timeIt(nHrs,nMin,nSecs);
    cout<<"The time now is = "<<timeIt.getTime()<<endl;
    
    //Now wait a few minutes and output the time
    cout<<"Wait a few seconds type in a char and output the time again"<<endl;
    cin>>dummy;
    cout<<"The time now is = "<<timeIt.getTime()<<endl;
    cout<<"There are "<<timeIt.YEAR<<" seconds in a year"<<endl;

    //Exit stage right!
    return 0;
}