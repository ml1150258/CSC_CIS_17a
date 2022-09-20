/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 6th, 2021, 1:30 PM
 * Purpose:  Create a database of array data
 * using binary files and irregular sized structures
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

//User Libraries Here
#include "Array.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
Array *fillAry(int,int);
void prntAry(Array *,int);
void wrtTxt(fstream &,Array *,int);
void wrtBin(fstream &,Array *);
Array *readBin(fstream &,int,int);
void destroy(Array *);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Open the Text and binary files
    fstream txtFile,binFile;
    txtFile.open("data.txt",ios::in|ios::out);
    binFile.open("data.bin",ios::in|ios::out|ios::binary);
    
    //Declare all Variables Here and Loop
    int nRecords=100;//Number of records 
    int perLine=10;  //Number to print per Line
    int size=50;     //Fixed size
    
    //Fill a binary and text file with a bunch of irregular size structures
    for(int record=0;record<nRecords;record++){
        Array *array=fillAry(size,record);
        //Printout the sorted array
        wrtTxt(txtFile,array,perLine);
        wrtBin(binFile,array);
        destroy(array);
    }
    
    //Read back in the array, then print out
    int randRec=rand()%nRecords;
    cout<<"Random record to find = "<<randRec<<endl;
    Array *brray=readBin(binFile,size,randRec);
    prntAry(brray,perLine);
    
    //Delete the array
    destroy(brray);
    
    //Close the files
    txtFile.close();
    binFile.close();
    
    //Exit
    return 0;
}

Array *readBin(fstream &in,int size,int record){
    //Declare and initialize variables
    int count=0;       //Size of array and records
    long cursor;    //Where to place the cursor
    Array *a=new Array;//Declare the array to return
    
    //Find the record
    cursor=record*((size+1)*sizeof(int));
    
    //Fill the structure
    in.seekg(cursor,ios::beg);
    in.read(reinterpret_cast<char *>(&a->size),sizeof(int));
    a->data=new int[a->size];
    in.read(reinterpret_cast<char *>( a->data),a->size*sizeof(int));
    return a;
}

void wrtBin(fstream &out,Array *a){
    out.write(reinterpret_cast<char *>(&a->size),sizeof(int));
    out.write(reinterpret_cast<char *>(a->data),a->size*sizeof(int));
}

void wrtTxt(fstream &out,Array *a,int perLine){
    out<<endl;
    out<<"Array Size = "<<a->size<<endl;
    for(int i=0;i<a->size;i++){
        out<<setw(6)<<a->data[i];
        if(i%perLine==(perLine-1))out<<endl;
    }
    out<<endl;
}

void destroy(Array *a){
    delete []a->data;
    delete a;
}

void prntAry(Array *a,int perLine){
    cout<<endl;
    cout<<"Array Size = "<<a->size<<endl;
    for(int i=0;i<a->size;i++){
        cout<<setw(6)<<a->data[i];
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n,int mod){
    //Declare the array and its components
    Array *a=new Array;
    a->size=n>1?n:2;
    a->data=new int[a->size];
    //Fill the components with data
    for(int i=0;i<a->size;i++){
        a->data[i]=mod*1000+rand()%100;
    }
    //Return the Array
    return a;
}