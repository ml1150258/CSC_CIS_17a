/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Oct 11th, 2021 1:20pm
 * Purpose:  Database Sort with Structure of Array Structures
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <cstdlib>    //Random function location
#include <ctime>      //Time Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "DBOrder.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
DBOrder *fillAry(int);
void prntAry(DBOrder *,int);
void markSrt(DBOrder *);
void destroy(DBOrder *);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    int size=100;
    DBOrder *dbOrder;
    
    //Initialize variables here
    dbOrder=fillAry(size);
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    cout<<"Display the Original Random Array"<<endl;
    prntAry(dbOrder,10);
    
    //Testing the memory swap function
    markSrt(dbOrder);
    
    //Display the results
    cout<<"Display arrays after sorting"<<endl;
    prntAry(dbOrder,10);
    
    //Deallocate Memory
    destroy(dbOrder);

    //Exit stage left
    return 0;
}

void destroy(DBOrder *dbOrder){
    delete []dbOrder->data->array;
    delete dbOrder->data;
    delete []dbOrder->index->array;
    delete dbOrder->index;
    delete dbOrder;
}

void markSrt(DBOrder *a){
    for(int pos=0;pos<a->data->size-1;pos++){//Works on each position in the list
        for(int i=pos+1;i<a->data->size;i++){//Compare and swap with lower elements in the list
            if(a->data->array[a->index->array[pos]]
                    > a->data->array[a->index->array[i]]){//Swap
                a->index->array[pos]=a->index->array[pos]^a->index->array[i];
                a->index->array[i]  =a->index->array[pos]^a->index->array[i];
                a->index->array[pos]=a->index->array[pos]^a->index->array[i];
            }
        }
    }
}

void prntAry(DBOrder *a,int perLine){
    cout<<endl;
    for(int i=0;i<a->data->size;i++){
        cout<<a->data->array[a->index->array[i]]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

DBOrder *fillAry(int n){
    n=n<2?2:n;//Arrays must be 2 or larger
    DBOrder *dbOrder=new DBOrder;//Single Structure DBOrder
    dbOrder->data=new Array;     //Single Structure Array
    dbOrder->data->size=n;       //Data array size
    dbOrder->data->array=new int[n];//Data array allocate
    dbOrder->index=new Array;    //Single Structure Index
    dbOrder->index->size=n;      //Index same size as Data
    dbOrder->index->array=new int[n];//Index array allocation
    for(int i=0;i<n;i++){//Fill the Arrays
        dbOrder->data->array[i]=rand()%90+10;//[10,99]
        dbOrder->index->array[i]=i;
    }
    return dbOrder;
}