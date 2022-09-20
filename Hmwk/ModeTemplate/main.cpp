/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Sept 18,2020 9:07 AM
 * Purpose:  Mode Template
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int *filAray(int,int);
void prntAry(int *,int,int);
void prtMode(int *);
void destroy(int *);
void markSrt(int *,int);
int *mode(int *,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare all Variables Here
    int size,modVal,perLine,*a1D,*modAray;
    
    //Input or initialize values Here
    size=12;
    modVal=5;
    a1D=filAray(size,modVal);
    
    //Display the unsorted array
    prntAry(a1D,size,modVal);
    
    
    //Process/Calculations Here
    markSrt(a1D,size);
    modAray=mode(a1D,size);
    
    //Output Located Here
    prntAry(a1D,size,modVal);
    prtMode(a1D);
    
    //Clean up
    destroy(a1D);
    destroy(modAray);

    //Exit
    return 0;
}

void prtMode(int *a){
    
}

int *mode(int *a,int n){
    //You write the function
    int *modAray=new int[2];
    modAray[0]=0;//Number of modes go here
    modAray[1]=0;//Frequence goes here
    //mode[2 to mode[0]];
    return modAray;
}

void markSrt(int *a,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void destroy(int *a){
    delete []a;
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *filAray(int n,int m){
    n=n<2?2:
      n>1000?1000:n;
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=i%m;//2 digit numbers
    }
    return array;
}