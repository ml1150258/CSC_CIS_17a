/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 9th, 2019, 10:40 AM
 * Purpose:  First Sort Program
 *           Mark Sort in 1 Function
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
void markSrt(int [],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    
    //Initialize or input i.e. set variable values
    fillAry(array,SIZE);
    
    //Print the Array
    prntAry(array,SIZE,10);
    
    //Map inputs -> outputs
    int beg=time(0);
    markSrt(array,SIZE);
    int end=time(0);
    
    //Display the outputs
    cout<<"The total time for Mark Sort give SIZE = "<<SIZE<<" to Sort"<<endl;
    cout<<"Total Time 1 Function= "<<end-beg<<" secs"<<endl;
    prntAry(array,SIZE,10);

    //Exit stage right or left!
    return 0;
}

void markSrt(int a[],int n){
    for(int pos=0;pos<n-1;pos++){
        for(int i=pos+1;i<n;i++){
            if(a[pos]>a[i]){
                int temp=a[i];
                a[i]=a[pos];
                a[pos]=temp;
            }
        }
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
        array[i]=rand()%90+10;
    }
}