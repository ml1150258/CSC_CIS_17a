/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Sept 20th, 2021 1pm
 * Purpose:  Dynamic Memory
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <cstdlib>    //Random function location
#include <ctime>      //Time Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
int * fillAry(int);
void prntAry(int [],int,int);
void markSrt(int [],int);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    int size=2000000000;
    int *array;
    
    //Initialize variables here
    array=fillAry(size);
    if(size>100000){
        cout<<"SIZE = "<<size<<endl;
        cout<<"Size > 100000 takes too long to run"<<endl;
        return 0;
    }
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    cout<<"Display the Original Random Array"<<endl;
    prntAry(array,size,10);
    
    //Testing the memory swap function
    markSrt(array,size);
    
    //Display the results
    cout<<"Apply a loop on smallest in the list n times = Mark Sort"<<endl;
    prntAry(array,size,10);
    
    //Deallocate Memory
    delete []array;

    //Exit stage left
    return 0;
}

void markSrt(int a[],int n){
    for(int pos=0;pos<n-1;pos++){//Works on each position in the list
        for(int i=pos+1;i<n;i++){//Compare and swap with lower elements in the list
            if(a[pos]>a[i]){//Swap
                a[pos]=a[pos]^a[i];
                a[i]=a[pos]^a[i];
                a[pos]=a[pos]^a[i];
            }
        }
    }
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

int * fillAry(int n){
    n=n<2?2:n;//2 or greater
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;//[10,99]
    }
    return a;
}