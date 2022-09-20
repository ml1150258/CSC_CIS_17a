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
    unsigned char  op1=240;   // 8 WD  0 BP
    //unsigned short op2=0x199A;//16 WD 16 BP
    unsigned short op2=0xCCCD;//16 WD 19 BP -> 0.1 base 10
    unsigned int   prod;      //32 WD  0 BP
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    prod = op1 * op2;//24 WD 19 BP
    
    //Display the Inputs/Outputs
    cout<<"Scaled Results"<<endl;
    cout<<"op1 = "<<static_cast<unsigned int>(op1)<<endl;
    cout<<"op2 = "<<static_cast<unsigned int>(op2)<<endl;
    cout<<"prod = "<<prod<<" or x2^19 too much"<<endl;
    prod>>=19;//Shifting to the right 19 bits
    cout<<"prod = "<<prod<<endl;
    cout<<" 240 x 0.1 = "<<240*0.1<<endl;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations