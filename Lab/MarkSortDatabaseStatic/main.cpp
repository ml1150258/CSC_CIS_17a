/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 9th, 2019, 10:40 AM
 * Purpose:  Database Sort
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Random function
#include <ctime>     //Time Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void fillAry(int [],int [],int);
void prntAry(const int [],int,int);
void prntAry(const int [],const int [],int,int);
void markSrt(const int [],int [],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    int index[SIZE];
    
    //Initialize or input i.e. set variable values
    fillAry(array,index,SIZE);
    
    //Print the Array
    cout<<"Before Sorting"<<endl;
    prntAry(array,SIZE,10);
    prntAry(index,SIZE,10);
    
    //Map inputs -> outputs
    markSrt(array,index,SIZE);
    
    cout<<"After Sorting"<<endl;
    prntAry(array,SIZE,10);
    prntAry(index,SIZE,10);
    cout<<"The original unsorted but displayed with the sorted index"<<endl;
    prntAry(array,index,SIZE,10);

    //Exit stage right or left!
    return 0;
}

void markSrt(const int a[],int idx[],int n){
    for(int pos=0;pos<n-1;pos++){
        for(int i=pos+1;i<n;i++){
            if(a[idx[pos]]>a[idx[i]]){
                int temp=idx[i];
                idx[i]=idx[pos];
                idx[pos]=temp;
            }
        }
    }
}

void prntAry(const int array[],const int indx[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<array[indx[i]]<<" ";//2 digit random number
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void prntAry(const int array[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";//2 digit random number
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillAry(int array[],int indx[],int n){
    for(int i=0;i<n;i++){
        *(array+i)=rand()%90+10;
        indx[i]=i;
    }
}