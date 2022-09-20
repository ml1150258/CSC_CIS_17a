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
const int COL=505;

//Function Prototypes Here
void filAray(int [],int);
void fil1t2(int [],int,int);
void filAray(int [][COL],int,int);
void prntAry(int [],int,int);
void prnt1t2(int [],int,int);
void prntAry(int [][COL],int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare all Variables Here
    const int ROW=COL;
    int a1S[ROW],a2S[ROW][COL],a12S[ROW*COL];
    int row,col,perLine;
    
    //Input or initialize values Here
    row=10,perLine=col=20;
    filAray(a1S,row*col);
    fil1t2(a12S,row,col);
    filAray(a2S,row,col);
    
    //Process/Calculations Here
    
    //Output Located Here
    prntAry(a1S,row*col,perLine);
    prnt1t2(a12S,row,col);
    prntAry(a2S,row,col);

    //Exit
    return 0;
}

void prntAry(int a[][COL],int row,int col){
    cout<<endl;
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            cout<<a[r][c]<<" ";//2 digit numbers
        }
        cout<<endl;
    }
    cout<<endl;
}

void prnt1t2(int a[],int row,int col){
    cout<<endl;
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            cout<<a[r*col+c]<<" ";//2 digit numbers
        }
        cout<<endl;
    }
    cout<<endl;
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void filAray(int array[][COL],int row,int col){
    row=row<2?2:
      row>COL?COL:row;
    col=col<2?2:
      col>COL?COL:col;
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            array[r][c]=rand()%90+10;//2 digit numbers
        }
    }
}

void fil1t2(int array[],int row,int col){
    int n=row*col;
    n=n<2?2:
      n>COL?COL:n;
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            array[r*col+c]=rand()%90+10;//2 digit numbers
        }   
    }
}

void filAray(int array[],int n){
    n=n<2?2:
      n>COL?COL:n;
    for(int i=0;i<n;i++){
        array[i]=rand()%90+10;//2 digit numbers
    }
}