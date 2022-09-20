/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 9th, 2019, 10:40 AM
 * Purpose:  First Sort Program
 *           Mark Sort in 3 Functions
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
void fillAry(int [],int);
void prntAry(int [],int,int);
void swap1(int &, int &);
void swap2(int &, int &);
void smlLst(int [],int,int);
void markSrt(int [],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=160000;
    int array[SIZE];
    
    //Initialize or input i.e. set variable values
    fillAry(array,SIZE);
    
    //Print the Array
    //prntAry(array,SIZE,10);
    
    //Map inputs -> outputs
    int beg=time(0);
    markSrt(array,SIZE);
    int end=time(0);
    
    //Display the outputs
    cout<<"The total time for Mark Sort give SIZE = "<<SIZE<<" to Sort"<<endl;
    cout<<"Total Time 3 Function = "<<end-beg<<" secs"<<endl;
    //prntAry(array,SIZE,10);

    //Exit stage right or left!
    return 0;
}

void markSrt(int a[],int n){
    for(int j=0;j<n-1;j++){
        smlLst(a,n,j);
    }
}

void smlLst(int a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i])swap1(a[pos],a[i]);
    }
}

void prntAry(int array[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";//2 digit random number
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillAry(int array[],int n){
    for(int i=0;i<n;i++){
        array[i]=rand();
    }
}

void swap1(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

void swap2(int &a, int & b){
    a=a^b;
    b=a^b;
    a=a^b;
}