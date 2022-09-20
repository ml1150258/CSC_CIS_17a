/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Nov 3rd, 2021, 2: PM
 * Purpose:  Sorting Class
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <cstdlib>    //Random function location
#include <ctime>      //Time Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Array.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    int size=100;
    Array array(size);
    Array *ptr;
    
    //Map inputs to outputs here, i.e. the process
    ptr=&array;
    
    //Display the results
    cout<<"Display the Original Random Array"<<endl;
    ptr->display(10);
    
    //Testing the memory swap function
    ptr->sort();
    
    //Display the results
    cout<<"Apply a loop on smallest in the list n times = Mark Sort"<<endl;
    ptr->display(10);

    //Exit stage left
    return 0;
}