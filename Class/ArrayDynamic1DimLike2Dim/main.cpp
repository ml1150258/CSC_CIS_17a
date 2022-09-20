/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 18,2020 9:07 AM
 * Purpose:  1 and 2 D Arrays
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int *filAray(int);
int *fil1t2(int,int);
int **filAray(int,int);
void prntAry(int *,int,int);
void prnt1t2(int *,int,int);
void prntAry(int **,int,int);
void destroy(int *);
void destroy(int **,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare all Variables Here
    int row,col,perLine,*a1D,**a2D,*a12D;
    
    //Input or initialize values Here
    row=10,perLine=col=20;
    a1D=filAray(row*col);
    a12D=fil1t2(row,col);
    a2D=filAray(row,col);
    
    //Process/Calculations Here
    
    //Output Located Here
    prntAry(a1D,row*col,perLine);
    prnt1t2(a12D,row,col);
    prntAry(a2D,row,col);
    
    //Clean up
    destroy(a1D);
    destroy(a12D);
    destroy(a2D,row);

    //Exit
    return 0;
}

void destroy(int **array,int row){
    for(int r=0;r<row;r++){
        delete []array[r];
    }
    delete []array;
}

void destroy(int *a){
    delete []a;
}

void prntAry(int **a,int row,int col){
    cout<<endl;
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            cout<<a[r][c]<<" ";//2 digit numbers
        }
        cout<<endl;
    }
    cout<<endl;
}

void prnt1t2(int *a,int row,int col){
    cout<<endl;
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            cout<<a[r*col+c]<<" ";//2 digit numbers
        }
        cout<<endl;
    }
    cout<<endl;
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int **filAray(int row,int col){
    row=row<2?2:
      row>1000?1000:row;
    col=col<2?2:
      col>1000?1000:col;
    int **array=new int*[row];
    for(int r=0;r<row;r++){
        array[r]=new int[col];
        for(int c=0;c<col;c++){
            array[r][c]=rand()%90+10;//2 digit numbers
        }
    }
    return array;
}

int *fil1t2(int row,int col){
    int n=row*col;
    n=n<2?2:
      n>1000?1000:n;
    int *array=new int[n];
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            array[r*col+c]=rand()%90+10;//2 digit numbers
        }   
    }
    return array;
}

int *filAray(int n){
    n=n<2?2:
      n>1000?1000:n;
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand()%90+10;//2 digit numbers
    }
    return array;
}