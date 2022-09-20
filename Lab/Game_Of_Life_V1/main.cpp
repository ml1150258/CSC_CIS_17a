/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Nov 22nd, 2017, 8:25 AM
 * Purpose:  Game of Life
 *           Fill and Display 2-D Array
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants
const int COLS=70;//Columns in the 2-D Arrays

//Function Prototypes
void filAray(char [][COLS],int);
void prntAry(char [][COLS],int);
void glider(int,int,char[][COLS]);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int ROWS=15;
    char table[ROWS][COLS]={};
    
    //Initialize Variables
    filAray(table,ROWS);
    glider(2,3,table);
    glider(6,33,table);
    
    //Display/Output all pertinent variables
    prntAry(table,ROWS);
    
    //Exit the program
    return 0;
}

void glider(int row,int col,char x[][COLS]){
    x[row+0][col+1]='x';
    x[row+1][col+2]='x';
    x[row+2][col+0]='x';
    x[row+2][col+1]='x';
    x[row+2][col+2]='x';
}

void prntAry(char x[][COLS],int rows){
    cout<<endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            cout<<x[row][col];
        }
        cout<<endl;
    }
    cout<<endl;
}

void filAray(char x[][COLS],int rows){
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            x[row][col]='-';
        }
    }
}