/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Sept 20th, 2021 1:20pm
 * Purpose:  Database Sort Dynamic
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
int *fillAry(int);
int *fillIdx(int);
void prntAry(int [],int,int);
void prntAry(int [],int [],int,int);
void markSrt(int [],int [],int);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    int size=100;
    int *array,*indx;
    
    //Initialize variables here
    array=fillAry(size);
    indx=fillIdx(size);
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    cout<<"Display the Original Random Array"<<endl;
    prntAry(array,size,10);
    cout<<"Index array before Sort"<<endl;
    prntAry(indx,size,10);
    
    //Testing the memory swap function
    markSrt(array,indx,size);
    
    //Display the results
    cout<<"Display arrays after sorting"<<endl;
    prntAry(array,size,10);
    cout<<"Index array after Sort"<<endl;
    prntAry(indx,size,10);
    cout<<"The Sorted Array output using the Index Array"<<endl;
    prntAry(array,indx,size,10);
    
    //Deallocate Memory
    delete []array;
    delete []indx;

    //Exit stage left
    return 0;
}

void markSrt(int a[],int idx[],int n){
    for(int pos=0;pos<n-1;pos++){//Works on each position in the list
        for(int i=pos+1;i<n;i++){//Compare and swap with lower elements in the list
            if(a[idx[pos]]>a[idx[i]]){//Swap
                idx[pos]=idx[pos]^idx[i];
                idx[i]=idx[pos]^idx[i];
                idx[pos]=idx[pos]^idx[i];
            }
        }
    }
}

void prntAry(int a[],int idx[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[idx[i]]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n){
    n=n<2?2:n;//Min size 2
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;//[10,99]
    }
    return a;
}

int *fillIdx(int n){
    n=n<2?2:n;//Min size 2
    int *idx=new int[n];
    for(int i=0;i<n;i++){
        idx[i]=i;
    }
    return idx;
}