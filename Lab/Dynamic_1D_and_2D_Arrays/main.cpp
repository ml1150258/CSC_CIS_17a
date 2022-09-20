/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 22nd, 2021, 1:30 PM
 * Purpose:  Compare 1 and 2 Dimensional Dynamic Arrays
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


//Function Prototypes Here
void prntAry(const int *,int,int);
void prntAry(int **,int,int);
int  *fillAry(int,int,int);
int  **fillAry(int,int);
void fillAry(int **,int *,int,int);
void destroy(int **,int);
void fillAry(int **,int *,int,int,int);
void swap(int &,int &);
void smlLst(int [],int,int);
void mrkSort(int [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int rowsize=4;//Row size for both 1 and 2 D arrays
    int colsize=3;//The column size for a 2 dimensional Array
    int *array;
    int *brray;
    int *crray;
    int **table;
    int lowRng=100,highRng=999;
    int perLine=4;
        
    //Fill each parallel array
    array=fillAry(rowsize,highRng,lowRng);
    brray=fillAry(rowsize,highRng/10,lowRng/10);
    crray=fillAry(rowsize,highRng/100,lowRng/100);
    
    //Sort the array the for all positions
    mrkSort(array,rowsize);
    mrkSort(brray,rowsize);
    mrkSort(crray,rowsize);
    
    //Fill the 2-D array
    table=fillAry(rowsize,colsize);
    fillAry(table,array,rowsize,0);
    fillAry(table,brray,rowsize,1);
    fillAry(table,crray,rowsize,2);
    
    //Print the values in the array
    prntAry(array,rowsize,perLine);
    prntAry(brray,rowsize,perLine);
    prntAry(crray,rowsize,perLine);
    prntAry(table,rowsize,colsize);
    
    //Cleanup
    delete []array;
    delete []brray;
    delete []crray;
    destroy(table,rowsize);

    //Exit
    return 0;
}

void destroy(int **a,int rows){
    for(int row=0;row<rows;row++){
        delete []a[row];
    }
    delete []a;
}

void fillAry(int **a,int *c,int rowSize,int wchCol){
    for(int row=0;row<rowSize;row++){
        a[row][wchCol]=c[row];
    }
}

int *fillAry(int n,int hr,int lr){
    n=n<2?2:n;
    int *a=new int[n];
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
    return a;
}

int **fillAry(int rows,int cols){
    //Allocate Memory for 2-D Array
    rows=rows<2?2:rows;
    cols=cols<2?2:cols;
    int **a=new int*[rows];
    for(int row=0;row<rows;row++){
        a[row]=new int[cols];
    }
    //Fill it with 0's
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            a[row][col]=0;
        }
    }
    return a;
}

void prntAry(int **a,int rowsize,int colsize){
     cout<<endl<<"The Array Values"<<endl;
    for(int row=0;row<rowsize;row++){
        for(int col=0;col<colsize;col++){
            cout<<setw(4)<<a[row][col];
        }
        cout<<endl;
    }
}

void prntAry(const int *a,int n,int perLine){
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