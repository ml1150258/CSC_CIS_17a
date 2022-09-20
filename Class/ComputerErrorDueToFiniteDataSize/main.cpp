/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 24, 2021, 3:53 PM
 * Purpose:  Error due to Base Misalignment
 *           Finite fraction Base 10 -> Infinite Base 2,8,16
 */

//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Declare variables here
    float sum,frac;
    float percErr;
    int nLoop;
    
    //Initialize variables here
    sum=0;
    frac=0.1;
    nLoop=10000000;
    
    //Map inputs to outputs here, i.e. the process
    for(int i=1;i<=nLoop;i++){
        sum+=frac;
    }
    percErr=(sum-nLoop*frac)/sum*100;
    
    //Display the results
    cout<<"Exact Result = "<<nLoop<<"*"<<frac<<" = "<<nLoop*frac<<endl;
    cout<<"Sum   Result = "<<sum<<endl;
    cout<<"Percentage Error = "<<percErr<<"%"<<endl;
    

    return 0;
}