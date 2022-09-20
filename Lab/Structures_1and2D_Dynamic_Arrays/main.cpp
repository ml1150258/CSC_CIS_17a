/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 29th, 2021, 12:55 PM
 * Purpose:  Structures with 1 and 2D Dynamic Arrays
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
void prntAry(const Array1D *,int);
void prntAry(Array2D *);
Array1D  *fillAry(int,int,int);
Array2D *fillAry(int,int);
void fillAry(Array2D *,Array1D *,int);
void destroy(Array1D *);
void destroy(Array2D *);
void swap(int &,int &);
void smlLst(int [],int,int);
void mrkSort(Array1D *);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int rowsize=4;//Row size for both 1 and 2 D arrays
    int colsize=3;//The column size for a 2 dimensional Array
    Array1D *array;
    Array1D *brray;
    Array1D *crray;
    Array2D *table;
    int lowRng=100,highRng=999;
    int perLine=4;
        
    //Fill each parallel array
    array=fillAry(rowsize,highRng,lowRng);
    brray=fillAry(rowsize,highRng/10,lowRng/10);
    crray=fillAry(rowsize,highRng/100,lowRng/100);
    
    //Sort the array the for all positions
    mrkSort(array);
    mrkSort(brray);
    mrkSort(crray);
    
    //Fill the 2-D array
    table=fillAry(rowsize,colsize);//Initialize Table to 0
    fillAry(table,array,0);//Fills table columns with data arrays
    fillAry(table,brray,1);//Fills table columns with data arrays
    fillAry(table,crray,2);//Fills table columns with data arrays
    
    //Print the values in the array
    prntAry(array,perLine);
    prntAry(brray,perLine);
    prntAry(crray,perLine);
    prntAry(table);
    
    //Cleanup
    destroy(array);
    destroy(brray);
    destroy(crray);
    destroy(table);

    //Exit
    return 0;
}

void destroy(Array1D *a){
    delete []a->data;//Reallocate the data in the structure
    delete a;        //Reallocate the structure
}

void destroy(Array2D *a){
    for(int row=0;row<a->rows;row++){
        delete []a->data[row];//Deletes the Data row by row
    }
    delete []a->data;//Deletes the array of pointers to the rows
    delete a;//Deletes the structure
}

void fillAry(Array2D *a,Array1D *c,int wchCol){
    if(a->rows!=c->size){
        cout<<"Not compatible Dimensions"<<endl;
        exit(1);
    }
    for(int row=0;row<a->rows;row++){
        a->data[row][wchCol]=c->data[row];
    }
}

Array1D *fillAry(int n,int hr,int lr){
    n=n<2?2:n; //Make sure the size of the array is 2 or greater
    Array1D *a=new Array1D;//Dynamically allocate the structure
    (*a).size=n;       //Pointer with * notation dereferencing
    a->data=new int[n];//Pointer with -> notation dereferencing
    //Filling the data in the array structure
    for(int indx=0;indx<n;indx++){
        a->data[indx]=rand()%(hr-lr+1)+lr;
    }
    return a;
}

Array2D *fillAry(int rows,int cols){
    //Allocate Memory for 2-D Array
    Array2D *a=new Array2D;//Allocate the structure
    a->rows=rows<2?2:rows; //Set the rows
    a->cols=cols<2?2:cols; //Set the cols
    a->data=new int*[a->rows];//Allocating an array of pointers to hold each
    //data array.
    for(int row=0;row<a->rows;row++){
        a->data[row]=new int[a->cols];//Allocate each row with size of cols
    }
    //Fill it with 0's
    for(int row=0;row<a->rows;row++){
        for(int col=0;col<a->cols;col++){
            a->data[row][col]=0;
        }
    }
    return a;
}

void prntAry(Array2D *a){
     cout<<endl<<"The Array Values"<<endl;
    for(int row=0;row<a->rows;row++){
        for(int col=0;col<a->cols;col++){
            cout<<setw(4)<<a->data[row][col];
        }
        cout<<endl;
    }
}

void prntAry(const Array1D *a,int perLine){
    //Print the values in the array
    cout<<endl<<"The Array Values"<<endl;
    for(int indx=0;indx<a->size;indx++){
        cout<<a->data[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void mrkSort(Array1D *a){
    for(int pos=0;pos<a->size-1;pos++){
        smlLst(a->data,a->size,pos);
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