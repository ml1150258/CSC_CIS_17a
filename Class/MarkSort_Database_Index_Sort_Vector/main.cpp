/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Sept 20th, 2021 1:20pm
 * Purpose:  Database Sort
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <cstdlib>    //Random function location
#include <ctime>      //Time Library
#include <vector>     //Vectors
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void fillAry(vector<int> &,vector<int> &);
void prntAry(vector<int> &,int);
void prntAry(vector<int> &,vector<int> &,int);
void markSrt(vector<int> &,vector<int> &);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    const int size=40000;
    vector<int> array(size);
    vector<int>indx(size);
    
    //Initialize variables here
    fillAry(array,indx);
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    cout<<"Display the Original Random Array"<<endl;
    prntAry(array,10);
    cout<<"Index array before Sort"<<endl;
    prntAry(indx,10);
    
    //Testing the memory swap function
    markSrt(array,indx);
    
    //Display the results
    cout<<"Display arrays after sorting"<<endl;
    prntAry(array,10);
    cout<<"Index array after Sort"<<endl;
    prntAry(indx,10);
    cout<<"The Sorted Array output using the Index Array"<<endl;
    prntAry(array,indx,10);

    //Exit stage left
    return 0;
}

void markSrt(vector<int> &a,vector<int> &idx){
    for(int pos=0;pos<a.size()-1;pos++){//Works on each position in the list
        for(int i=pos+1;i<a.size();i++){//Compare and swap with lower elements in the list
            if(a[idx[pos]]>a[idx[i]]){//Swap
                idx[pos]=idx[pos]^idx[i];
                idx[i]=idx[pos]^idx[i];
                idx[pos]=idx[pos]^idx[i];
            }
        }
    }
}

void prntAry(vector<int> &a,vector<int> &idx,int perLine){
    cout<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[idx[i]]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

void prntAry(vector<int> &a,int perLine){
    cout<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

void fillAry(vector<int> &a,vector<int> &idx){
    for(int i=0;i<a.size();i++){
        a[i]=rand()%90+10;//[10,99]
        idx[i]=i;
    }
}