/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 15th, 2020, 10:05 AM
 * Purpose:  Compare 1 and 2 Dimensional Static Arrays
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions and Array Dimension
const int COLSIZE=3;//The column size for a 2 dimensional Array

//Function Prototypes Here
void prntAry(const int [],int,int);
void prntAry(const int [][COLSIZE],int);
void fillAry(int [],int,int,int);
void fillAry(int [][COLSIZE],int [],int,int);
void swap(int &,int &);
void smlLst(int [],int,int);
void mrkSort(int [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int ROWSIZE=4;
    int array[ROWSIZE];
    int brray[ROWSIZE];
    int crray[ROWSIZE];
    int table[ROWSIZE][COLSIZE];
    int lowRng=100,highRng=999;
    int perLine=4;
        
    //Fill each parallel array
    fillAry(array,ROWSIZE,highRng,lowRng);
    fillAry(brray,ROWSIZE,highRng/10,lowRng/10);
    fillAry(crray,ROWSIZE,highRng/100,lowRng/100);
    
    //Sort the array the for all positions
    mrkSort(array,ROWSIZE);
    mrkSort(brray,ROWSIZE);
    mrkSort(crray,ROWSIZE);
    
    //Fill the 2-D array
    fillAry(table,array,ROWSIZE,0);
    fillAry(table,brray,ROWSIZE,1);
    fillAry(table,crray,ROWSIZE,2);
    
    //Print the values in the array
    prntAry(array,ROWSIZE,perLine);
    prntAry(brray,ROWSIZE,perLine);
    prntAry(crray,ROWSIZE,perLine);
    prntAry(table,ROWSIZE);

    //Exit
    return 0;
}

void fillAry(int a[][COLSIZE],int c[],int rowSize,int wchCol){
    for(int row=0;row<rowSize;row++){
        a[row][wchCol]=c[row];
    }
}

void fillAry(int a[],int n,int hr,int lr){
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}

void prntAry(const int a[][COLSIZE],int rowSize){
     cout<<endl<<"The Array Values"<<endl;
    for(int row=0;row<rowSize;row++){
        for(int col=0;col<COLSIZE;col++){
            cout<<setw(4)<<a[row][col];
        }
        cout<<endl;
    }
}

void prntAry(const int a[],int n,int perLine){
    //Print the values in the array
    cout<<endl<<"The Array Values"<<endl;
    for(int indx=0;indx<n;indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void mrkSort(int a[],int n){
    for(int pos=0;pos<n-1;pos++){
        smlLst(a,n,pos);
    }
}

void smlLst(int a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}