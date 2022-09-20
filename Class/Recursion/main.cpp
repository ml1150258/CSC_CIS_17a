/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Oct 20th, 2021, 1:00 PM
 * Purpose:  Recursions
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <cmath>      //Math Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions
const float CNVPERC=100.0f;

//Function Prototypes
float powRec(float,int);
float fvRec(float,float,int);
float fv(float,float,int);
int   fibRec(int);
int   fib(int);
float logFact(int);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    int n,nYears;
    float x,pv,i;
    
    //Initialize variables here
    n=5;
    x=2.0f;
    nYears=12;
    i=72/nYears;
    pv=100;
    i/=CNVPERC;
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    cout<<x<<"^"<<n<<" = "<<powRec(x,n)<<endl;
    cout<<"Recursive       FutureValue("<<pv<<","<<i<<","<<nYears<<") = $"
            <<fvRec(pv,i,nYears)<<endl;
    cout<<"For-Loop        FutureValue("<<pv<<","<<i<<","<<nYears<<") = $"
            <<fv(pv,i,nYears)<<endl;
    cout<<"Recursive Power FutureValue("<<pv<<","<<i<<","<<nYears<<") = $"
            <<pv*powRec(1+i,nYears)<<endl;
    cout<<"Recursive Fibonacci("<<nYears<<") = "<<fibRec(nYears)<<endl;
    for(int j=0;j<=nYears;j++){
        cout<<fibRec(j);
        if(j!=nYears)cout<<",";
    }
    cout<<endl;
    cout<<"Non-Recursive Fibonacci("<<nYears<<") = "<<fib(nYears)<<endl;
    for(int j=0;j<=nYears;j++){
        cout<<fib(j);
        if(j!=nYears)cout<<",";
    }
    cout<<endl<<"Golden Ratio ~= "<<1.0f*fib(41)/fib(40)<<endl;
    cout<<nYears<<"! = "<<exp(logFact(nYears))<<endl;
    
    return 0;
}

float logFact(int n){
    //Base Condition
    if(n<=1)return 0;
    //Recursion
    return logFact(n-1)+log(n);
}

int fib(int n){
    //Base Cases
    if(n<=0)return 0;
    if(n==1)return 1;
    int cnt=1,fim2=0,fim1=1,fi;
    do{
        fi=fim1+fim2;
        fim2=fim1;
        fim1=fi;
    }while(++cnt<n);
    return fi;
}

int   fibRec(int n){
    //Base Cases
    if(n<=0)return 0;
    if(n==1)return 1;
    //Recursion
    return fibRec(n-1)+fibRec(n-2);
}

float fv(float pv,float i,int n){
    float fv=pv;
    for(int nYears=1;nYears<=n;nYears++){
        fv*=(1+i);
    }
    return fv;
}

float fvRec(float pv,float i,int n){
    //Base Condition
    if(n<=0)return pv;
    //Recursion
    return fvRec(pv,i,n-1)*(1+i);
}

float powRec(float x,int n){
    //Base Condition
    if(n<=0)return 1;
    //Recursion
    return powRec(x,n-1)*x;
}