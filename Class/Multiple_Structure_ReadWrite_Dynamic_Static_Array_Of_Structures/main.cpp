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
Array fillAry(int,int);
void prntAry(Array *,int);
void wrtTxt(fstream &,Array,int);
void wrtBin(fstream &,Array);
Array *readBin(fstream &,int);
void markSrt(Array);
void destroy(Array);
void destroy(Array *);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Open the Text and binary files
    fstream txtFile,binFile;
    txtFile.open("data.txt",ios::in|ios::out);
    binFile.open("data.bin",ios::in|ios::out|ios::binary|ios::trunc);
    
    //Declare all Variables Here and Loop
    int nRecords=100;//Number of records 
    int perLine=10;  //Number to print per Line
    Array array[nRecords];
    
    //Fill a binary and text file with a bunch of irregular size structures
    for(int record=0;record<nRecords;record++){
        int size=rand()%90+10;//[10-99]
        array[record]=fillAry(size,record);
        //Sort every other array
        if(record%2)markSrt(array[record]);
        //Printout the sorted array
        wrtTxt(txtFile,array[record],perLine);
        wrtBin(binFile,array[record]);
        destroy(array[record]);
    }
    
    //Read back in the array, then print out
    int randRec=rand()%nRecords;
    cout<<"Random record to find = "<<randRec<<endl;
    Array *brray=readBin(binFile,randRec);
    prntAry(brray,perLine);
    
    //Delete the array
    destroy(brray);
    
    //Close the files
    txtFile.close();
    binFile.close();
    
    //Exit
    return 0;
}

Array *readBin(fstream &in,int record){
    //Declare and initialize variables
    int count=0;       //Size of array and records
    long cursor=0L;    //Where to place the cursor
    Array *a=new Array;//Declare the array to return
    
    //Find the record
    while(++count<=record){
        in.seekg(cursor,ios::beg);
        in.read(reinterpret_cast<char *>(&a->size),sizeof(int));
        cursor+=(sizeof(int)+
                        a->size*sizeof(int)+a->size*sizeof(int));
    }
    
    //Fill the structure
    in.seekg(cursor,ios::beg);
    in.read(reinterpret_cast<char *>(&a->size),sizeof(int));
    a->data=new int[a->size];
    in.read(reinterpret_cast<char *>( a->data),a->size*sizeof(int));
    a->index=new int[a->size];
    in.read(reinterpret_cast<char *>(a->index),a->size*sizeof(int));
    return a;
}

void wrtBin(fstream &out,Array a){
    out.write(reinterpret_cast<char *>(&a.size),sizeof(int));
    out.write(reinterpret_cast<char *>(a.data),a.size*sizeof(int));
    out.write(reinterpret_cast<char *>(a.index),a.size*sizeof(int));
}

void wrtTxt(fstream &out,Array a,int perLine){
    out<<endl;
    out<<"Array Size = "<<a.size<<endl;
    for(int i=0;i<a.size;i++){
        out<<setw(6)<<a.data[a.index[i]];
        if(i%perLine==(perLine-1))out<<endl;
    }
    out<<endl;
}

void destroy(Array a){
    delete []a.data;
    delete []a.index;
}

void destroy(Array *a){
    delete []a->data;
    delete []a->index;
    delete a;
}

void markSrt(Array a){
    for(int i=0;i<a.size-1;i++){
        for(int j=i+1;j<a.size;j++){
            if(a.data[a.index[i]]>a.data[a.index[j]]){
                int temp=a.index[i];
                a.index[i]=a.index[j];
                a.index[j]=temp;
            }
        }
    }
}

void prntAry(Array *a,int perLine){
    cout<<endl;
    cout<<"Array Size = "<<a->size<<endl;
    for(int i=0;i<a->size;i++){
        cout<<setw(6)<<a->data[a->index[i]];
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array fillAry(int n,int mod){
    //Declare the array and its components
    Array a;
    a.size=n>1?n:2;
    a.data=new int[a.size];
    a.index=new int[a.size];
    //Fill the components with data
    for(int i=0;i<a.size;i++){
        a.data[i]=mod*1000+rand()%100;
        a.index[i]=i;
    }
    //Return the Array
    return a;
}