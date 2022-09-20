/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   November 27th, 2019
 * Purpose:Various ways to time functions and 
 * compare to a recursive implementation
 */

//System Libraries
#include <iostream>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
double count=0;
int array[100];

//Function Prototypes all doing Fibonacci
int fibRec(int);        //Recursive Fibonacci
int fib3Var(int);       //3 Variable 
int fibAray(int);       //Internal Dynamic array
int fibSAry(int);       //Internal Static array
int fibSAry(int *,int); //Static array in main
int fibGAry(int);       //Global Static array

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    
    //Declare Variables
    int seqLen=45;
    int array[100];
    
    //Initialize Variables
    
    //Process inputs to outputs/map
    /*cout<<"Fibonacci Recursive Sequence"<<endl;
    for(int i=0;i<=seqLen;i++){
        cout<<fibRec(i)<<" ";
        if(i%5==4)cout<<endl;
    }*/
    cout<<"Recursive Result"<<endl;
    int beg=time(0);
    cout<<fibRec(seqLen)<<endl;
    int end=time(0);
    cout<<"Total Time = "<<end-beg<<" secs"<<endl;
    cout<<"Total Count = "<<count<<endl;
    
    
    cout<<endl<<"3 Variable Result"<<endl;
    int nLoops=200000000;
    beg=time(0);
    for(int i=1;i<=nLoops;i++){
        fib3Var(seqLen);
    }
    cout<<fib3Var(seqLen)<<endl;
    end=time(0);
    cout<<"Total Time = "<<1.0f*(end-beg)/nLoops<<" secs"<<endl;
    
    
    cout<<endl<<"Array Result"<<endl;
    beg=time(0);
    for(int i=1;i<=nLoops;i++){
        fibAray(seqLen);
    }
    cout<<fibAray(seqLen)<<endl;
    end=time(0);
    cout<<"Total Time = "<<1.0f*(end-beg)/nLoops<<" secs"<<endl;
    
    
    cout<<endl<<"Static Array Result"<<endl;
    beg=time(0);
    for(int i=1;i<=nLoops;i++){
        fibSAry(seqLen);
    }
    cout<<fibSAry(seqLen)<<endl;
    end=time(0);
    cout<<"Total Time = "<<1.0f*(end-beg)/nLoops<<" secs"<<endl;
    
    cout<<endl<<"Static Array in Main Result"<<endl;
    beg=time(0);
    for(int i=1;i<=nLoops;i++){
        fibSAry(array,seqLen);
    }
    cout<<fibSAry(array,seqLen)<<endl;
    end=time(0);
    cout<<"Total Time = "<<1.0f*(end-beg)/nLoops<<" secs"<<endl;
    
    cout<<endl<<"Static Global Array Result"<<endl;
    beg=time(0);
    for(int i=1;i<=nLoops;i++){
        fibGAry(seqLen);
    }
    cout<<fibGAry(seqLen)<<endl;
    end=time(0);
    cout<<"Total Time = "<<1.0f*(end-beg)/nLoops<<" secs"<<endl;
    
    //Display the results

    //Clean up and exit stage right
    return 0;
}

int fibGAry(int n){
    array[0]=0;
    array[1]=1;
    for(int i=2;i<=n;i++){
        array[i]=array[i-1]+array[i-2];
    }
    return array[n];
}

int fibSAry(int *array,int n){
    array[0]=0;
    array[1]=1;
    for(int i=2;i<=n;i++){
        array[i]=array[i-1]+array[i-2];
    }
    return array[n];
}

int fibSAry(int n){
    int array[100];
    array[0]=0;
    array[1]=1;
    for(int i=2;i<=n;i++){
        array[i]=array[i-1]+array[i-2];
    }
    int result=array[n];
    return result;
}

int fibAray(int n){
    int *array=new int[n+1];
    array[0]=0;
    array[1]=1;
    for(int i=2;i<=n;i++){
        array[i]=array[i-1]+array[i-2];
    }
    int result=array[n];
    delete []array;
    return result;
}

int fib3Var(int n){
    int fnm2=0;
    int fnm1=1;
    int fn,cnt=2;
    if(n<=0)return fnm2;
    if(n==1)return fnm1;
    do{
        fn=fnm1+fnm2;
        fnm2=fnm1;
        fnm1=fn;
    }while(cnt++!=n);
    return fn;
}

int fibRec(int n){
    count++;
    //Base Condition
    if(n<=0)return 0;
    if(n==1)return 1;
    //Recursion
    return fibRec(n-1)+fibRec(n-2);
}