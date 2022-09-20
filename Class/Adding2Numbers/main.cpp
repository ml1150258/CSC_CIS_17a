/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 22, 2020, 6:14 PM
 * Purpose:  Fun Program, just adding 2 numbers
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    unsigned short op1, op2;//Integer Operand 1 and 2 Range [0,65535]
    unsigned int sum;//Integer sum of 2 unsigned shorts
    
    //Initialize all known variables
    op1=2;
    op2=3;
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    sum=op1+op2;
    
    //Display the Inputs/Outputs
    cout<<op1<<" + "<<op2<<" = "<<sum<<endl;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}