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
int *fill1D(int);
void prnStrc(DynAry1 *,int);
void destroy(DynAry1 *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables and Initialize
    int size=100;
    int *dynAry=fill1D(size);
    DynAry1 *array1D=new DynAry1;
    array1D->setSize(size);
    array1D->setArray(dynAry);
    
    //Initialize Variables
    prnStrc(array1D,10);
    
    //Deallocate memory
    destroy(array1D);
    
    //Exit stage right!
    return 0;
}

int *fill1D(int n){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;//Random 2 Digit numbers
    }
    return a;
}

void prnStrc(DynAry1 *d1,int perLine){
    cout<<endl;
    for(int i=0;i<d1->getSize();i++){
        cout<<d1->getData(i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void destroy(DynAry1 *d1){
    delete d1;
}