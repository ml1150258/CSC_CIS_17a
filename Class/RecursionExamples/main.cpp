/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 22, 2020, 6:14 PM
 * Purpose:  Template which is to be copied for all future
 *           Homework, Labs, Projects, Test, etc...
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cmath>     //Math Libary
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
float pow(float,int);//z=x^y
int   fibRec(int);   //fi=fim1+fim2
int   fact(int);     //n!=1*2*3....*n
float power(float,float);//How computer calculate x^y

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare and initialize values
    float x=3;
    int   y=4;
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    cout<<x<<"^"<<y<<" = "<<pow(x,y)<<endl;
    //Compare with how implemented in the computer
    cout<<x<<"^"<<y<<" = "<<power(x,y)<<" e^(y*log(x))"<<endl;
    
    //Display the Inputs/Outputs
    int seqLen=41;
    cout<<"The first "<<seqLen<<" elements in the Fibonacci Sequence"<<endl;
    for(int i=0;i<seqLen;i++){
        cout<<fibRec(i)<<" ";
    }
    cout<<endl;
    
    //Display n! in recursive form
    cout<<"The Recursive Factorial Function"<<endl;
    for(int i=0;i<=10;i++){
        cout<<i<<"!="<<fact(i)<<endl;
    }

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

float power(float x,float y){
    return exp(y*log(x));
}

int   fact(int n){
    //Base Condition
    if(n<=0)return 1;
    //Recursive Definition
    return fact(n-1)*n;
}

int   fibRec(int n){
    //Base Condition, start of the sequence
    if(n<=0)return 0;
    if(n==1)return 1;
    //Sequence Definition
    return fibRec(n-1)+fibRec(n-2);
}

float pow(float x,int y){
    //Base Condition -> When to end the function calls
    if(y<=0)return 1;
    //Recursive definition of the function
    return pow(x,y-1)*x;
}