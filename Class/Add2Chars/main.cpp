/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 26th, 2020, 6:14 PM
 * Purpose:  Show you can add 2 chars
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
    char op1, op2, result;
    
    //Initialize all known variables
    op1=30;
    op2=40;
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    result=op1+op2;
    
    //Display the Inputs/Outputs
    cout<<static_cast<int>(op1)<<"+"<<static_cast<int>(op2)
            <<"="<<static_cast<int>(result)<<endl;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations