/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on September 19th, 2018, 1:40 PM
 * Purpose:  2D Array Structure
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Struc2DArray.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
int **fill2D(int,int);
DynAry2 *filStrc(int **,int,int);
void prnStrc(DynAry2 *);
void destroy(DynAry2 *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables and Initialize
    int rows=10;
    int cols=5;
    int **dynAry=fill2D(rows,cols);
    DynAry2 *array2D=filStrc(dynAry,rows,cols);
    
    //Initialize Variables
    prnStrc(array2D);
    
    //Deallocate memory
    destroy(array2D);
    
    //Exit stage right!
    return 0;
}

int **fill2D(int row,int col){
    int **a=new int*[row];
    for(int i=0;i<row;i++){
        a[i]=new int[col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            a[i][j]=rand()%90+10;//Random 2 Digit numbers
        }  
    }
    return a;
}

DynAry2 *filStrc(int **a,int row,int col){
    DynAry2 *d2=new DynAry2;
    d2->rows=row;
    d2->cols=col;
    (*d2).array=a;
    return d2;
}

void prnStrc(DynAry2 *d2){
    cout<<endl;
    for(int i=0;i<d2->rows;i++){
        for(int j=0;j<d2->cols;j++){
            cout<<d2->array[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void destroy(DynAry2 *d2){
    for(int i=0;i<d2->rows;i++){
        delete []d2->array[i];
    }
    delete []d2->array;
    delete d2;
}