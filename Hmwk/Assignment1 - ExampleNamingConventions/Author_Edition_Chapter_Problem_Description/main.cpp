/* 
 * File:   main.cpp
 * Author: Dr. Joe Blow
 * Created on June 24, 2020, 10:40 AM
 * Purpose:  Template which is to be copied for all future
 *           Homework, Labs, Projects, Test, etc...
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants and Conversion
const char  PERCENT=100;//Percent Conversion
const float TRILLIN=1e12f;//Trillion
const float BILLION=1e9f;//Billion

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    float fedBdgt;//Federal Budget in $'s
    float milBdgt;//Military Budget in $'s
    float milPerc;//Military percentage of the Budget
    
    //Initialize all known variables
    fedBdgt=4.1e12f;//2018 Budget
    milBdgt=700.0e9f;//2018 Budget
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    milPerc=milBdgt/fedBdgt*PERCENT;
    
    //Display the Inputs/Outputs
    cout<<"2018 Federal Budget    = $  "<<fedBdgt/TRILLIN<<" Trillion"<<endl;
    cout<<"2018 Military Budget   = $"<<milBdgt/BILLION<<" Billion"<<endl;
    cout<<"Military Budget Percent =  "<<milPerc<<"%"<<endl;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}