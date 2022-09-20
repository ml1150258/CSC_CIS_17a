/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 15th, 2020, 10:05 AM
 * Purpose:  Compare 1 and 2 Dimensional Static Arrays
 *           using structures
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//User Libraries Here
#include "Array1D.h"
#include "Array2D.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions and Array Dimension

//Function Prototypes Here
void prntAry(const Array1D &,int);
void prntAry(const Array2D &);
void fillAry(Array1D &,int,int);
void fillAry(Array2D &,int [],int);
void swap(int &,int &);
void smlLst(Array1D &,int);
void mrkSort(Array1D &);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    Array1D sArray,sBrray,sCrray;
    int array[ROWSIZE];
    int brray[ROWSIZE];
    int crray[ROWSIZE];
    sArray.size=sBrray.size=sCrray.size=ROWSIZE;
    sArray.data=array;
    sBrray.data=brray;
    sCrray.data=crray;
    Array2D table;
    int lowRng=100,highRng=999;
    int perLine=4;
        
    //Fill each parallel array
    fillAry(sArray,highRng,lowRng);
    fillAry(sBrray,highRng/10,lowRng/10);
    fillAry(sCrray,highRng/100,lowRng/100);
    
    //Sort the array the for all positions
    mrkSort(sArray);
    mrkSort(sBrray);
    mrkSort(sCrray);
    
    //Fill the 2-D array
    fillAry(table,array,0);
    fillAry(table,brray,1);
    fillAry(table,crray,2);
    
    //Print the values in the array
    prntAry(sArray,perLine);
    prntAry(sBrray,perLine);
    prntAry(sCrray,perLine);
    prntAry(table);

    //Exit
    return 0;
}

void fillAry(Array2D &a,int c[],int wchCol){
    for(int row=0;row<a.row;row++){
        a.data[row][wchCol]=c[row];
    }
}

void fillAry(Array1D &a,int hr,int lr){
    for(int indx=0;indx<a.size;indx++){
        a.data[indx]=rand()%(hr-lr+1)+lr;
    }
}

void prntAry(const Array2D &a){
     cout<<endl<<"The Array Values"<<endl;
    for(int row=0;row<a.row;row++){
        for(int col=0;col<a.col;col++){
            cout<<setw(4)<<a.data[row][col];
        }
        cout<<endl;
    }
}

void prntAry(const Array1D &a,int perLine){
    //Print the values in the array
    cout<<endl<<"The Array Values"<<endl;
    for(int indx=0;indx<a.size;indx++){
        cout<<a.data[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void mrkSort(Array1D &a){
    for(int pos=0;pos<a.size-1;pos++){
        smlLst(a,pos);
    }
}

void smlLst(Array1D &a,int pos){
    for(int i=pos+1;i<a.size;i++){
        if(a.data[pos]>a.data[i]){
            swap(a.data[pos],a.data[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}