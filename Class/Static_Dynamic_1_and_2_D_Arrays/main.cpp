/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on March 5th, 2020, 1:20 PM
 * Purpose: Static/Dynamic Arrays
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
const int COL=10;

//Function Prototypes
void fill1D(int [],int);
void fill2D(int [][COL],int);
int * fill1D(int);
int ** fill2D(int,int);
void prnt1D(const int *,int,int);
void prnt2D(const int * const *,int,int);
void prnt2D(const int [][COL],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int ROW=5;
    int s1Dary[ROW*COL];
    int s2Dary[ROW][COL];
    int *d1Dary=fill1D(ROW*COL);
    int **d2Dary=fill2D(ROW,COL);
    
    //Initialize Variables
    fill1D(s1Dary,ROW*COL);
    fill2D(s2Dary,ROW);
    
    //Output data
    prnt1D(s1Dary,ROW*COL,COL);
    prnt1D(d1Dary,ROW*COL,COL);
    prnt2D(s2Dary,ROW);
    prnt2D(d2Dary,ROW,COL);
    
    //Deallocate memory
    delete []d1Dary;
    for(int i=0;i<ROW;i++){
        delete[] d2Dary[i];
    }
    delete []d2Dary;
    
    //Exit stage right!
    return 0;
}

void fill1D(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}

void fill2D(int a[][COL],int row){
    for(int i=0;i<row;i++){
        for(int j=0;j<COL;j++){
            a[i][j]=rand()%90+10;
        }
    }
}

int * fill1D(int n){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
    return a;
}

int ** fill2D(int row,int COL){
    int **a=new int*[row];
    for(int i=0;i<row;i++){
        a[i]=new int[COL];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<COL;j++){
            a[i][j]=rand()%90+10;
        }
    }
    return a;
}

void prnt1D(const int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

void prnt2D(const int * const *a,int row,int COL){
    cout<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<COL;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void prnt2D(const int a[][COL],int row){
    cout<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<COL;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}