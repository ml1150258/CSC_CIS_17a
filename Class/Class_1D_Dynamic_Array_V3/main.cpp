/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on October 19th, 2022, 1:20 PM
 * Purpose:  1D Array Class 
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Class1DArray.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables and Initialize
    int size=100;
    DynAry1 *array1D=new DynAry1;
    array1D->setSize(size);
    
    //Initialize Variables
    array1D->prnStrc(10);
    array1D->setArray(500,50);
    array1D->prnStrc(10);
    
    //De-allocate memory
    delete array1D;
    
    //Exit stage right!
    return 0;
}