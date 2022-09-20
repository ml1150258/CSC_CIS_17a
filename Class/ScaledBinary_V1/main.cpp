/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 2nd, 2020, 1:30 PM
 * Purpose:  Scaled Binary
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
    unsigned char op1=88;  //8 WD 0 BP
    //unsigned char op2=0xD2;//8 WD 4 BP  Hex
    //unsigned char op2=0322;//8 WD 4 BP  Octal
    unsigned char op2=0b11010010;//8 WD 4 BP  Binary
    unsigned short prod;
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    prod = op1 * op2;//16 WD 4 BP
    
    //Display the Inputs/Outputs
    cout<<"Scaled Results"<<endl;
    cout<<"op1 = "<<static_cast<unsigned int>(op1)<<endl;
    cout<<"op2 = "<<static_cast<unsigned int>(op2)<<endl;
    cout<<"prod = "<<prod<<" x16^1 or x2^4 too much"<<endl;
    prod>>=4;//Shifting to the right 4 bits
    cout<<"prod = "<<prod<<endl;
    cout<<" 88 x 13.125 = "<<88*13.125<<endl;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations