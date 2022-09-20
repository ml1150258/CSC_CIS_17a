/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 1st, 2020, 11:40 AM
 * Purpose:  Common Computer Delusions
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants
const unsigned char PERCENT=100;

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    float sum,frac,exactSum,error;
    int nLoops=10000000;
    
    //Initialize all known variables
    sum=0;
    frac=0.1;
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    for(int i=1;i<=nLoops;i++){
        sum+=frac;
    }
    exactSum=frac*nLoops;
    error=(exactSum-sum)/exactSum*PERCENT;
    
    //Display the Inputs/Outputs
    cout<<"The Sum       = "<<sum<<endl;
    cout<<"The exact Sum = "<<exactSum<<endl;
    cout<<"The error     = "<<error<<"%"<<endl;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}