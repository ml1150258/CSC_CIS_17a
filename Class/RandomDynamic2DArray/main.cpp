/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 23rd, 2020, 1:50 PM
 * Purpose:  Example of Dynamic 2 D Array
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time to set the random number seed
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
int **filAray(int,int);
void prntAry(int **,int,int);
void destroy(int **,int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all variables for this function
    int rows=15;
    int cols=10;
    int **array;
    
    //Allocate the 2D array
    array=filAray(rows,cols);
    
    //Display the array
    prntAry(array,rows,cols);

    //Clean up the code, close files, deallocate memory, etc....
    destroy(array,rows);
    
    //Exit stage right
    return 0;
}

void destroy(int **array,int rows){
    //Deallocate each row
    for(int row=0;row<rows;row++){
        delete []array[row];
    }
    //Deallocate the row pointers
    delete []array;
}

void prntAry(int **array,int rows,int cols){
    cout<<endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            cout<<array[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int **filAray(int rows,int cols){
    //Declare and allocate the array
    rows=rows<2?2:rows;
    cols=cols<2?2:cols;
    //Allocate row pointers
    int **array=new int*[rows];
    //Allocate each row with the same size columns
    for(int row=0;row<rows;row++){
        array[row]=new int[cols];
    }
    //Fill the array with random 2 Digit numbers
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            array[row][col]=rand()%90+10;
        }
    }
    //Return the 2-D Array
    return array;
}