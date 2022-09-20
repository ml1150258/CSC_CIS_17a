/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 17, 2021 1:50 PM
 * Purpose:  Scaled Binary for exp(1)
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cmath>     //Math Library for exp(1)
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    unsigned char  op1=240;              //  8 WD   0 BP
    unsigned short  exp2Byte=0xADF8;     // 16 WD  14 BP
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    unsigned int prod = op1 * exp2Byte;//24 WD 14 BP
    
    //Display the Inputs/Outputs
    cout<<"Scaled Results"<<endl;
    cout<<"op1      = "<<static_cast<unsigned int>(op1)<<endl;
    cout<<"exp2Byte = "<<static_cast<unsigned int>(exp2Byte)<<endl;
    cout<<"prod     = "<<prod<<" or x 2^14 too much"<<endl;
    prod>>=14;//Shifting to the right 14 bits
    cout<<"prod     = "<<prod<<endl;
    cout<<" 240 x exp(1) = "<<op1*exp(1)<<endl;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations