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
    int aryNum=5;
    Array **array=new Array*[aryNum];
    
    //Initialize the objects
    for(int i=0;i<aryNum;i++){
        array[i]=new Array(size-i*20);
    }
    
    //Map inputs to outputs here, i.e. the process
    for(int i=0;i<aryNum;i++){
        array[i]->sort();
        cout<<"Array Size = "<<array[i]->getSize();
        array[i]->display(10);
    }
    
    //Deallocate Memory
    for(int i=0;i<aryNum;i++){
        delete array[i];
    }
    delete []array;

    //Exit stage left
    return 0;
}