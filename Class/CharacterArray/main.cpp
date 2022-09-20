/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 21, 2021, 11:19 AM
 * Purpose:  Develop a Template to be copied
 *           for all future programs in CSC/CIS 5
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <string.h>   //String compare
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions
const int SIZE=80;

//Function Prototypes
int sizeStr(char []);
void example(char []);
void order(char [][SIZE],int);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Declare variables here
    const int ROWS=2;
    char name[SIZE]="Mark Lehr";
    char words[ROWS][SIZE];
    
    //Initialize variables here
    
    //Map inputs to outputs here, i.e. the process
    order(words,ROWS);
    //example(name);
    
    //Display the results
    cout<<sizeStr(name)<<endl;

    return 0;
}

void order(char words[][SIZE],int rows){
    int count=0;
    while(cin>>words[count] && count++<2){;
    }
    if(strcmp(words[0],words[1])<0){
        cout<<words[0]<<","<<words[1]<<endl;
    }else if(strcmp(words[0],words[1])>0){
        cout<<words[1]<<","<<words[0]<<endl;
    }else{
        cout<<"The 2 inputs are equal"<<endl;
    }
}

void example(char a[]){
    int count=0;
    while(cin>>a&&count++<5){
        cout<<a<<endl;
    }
}

int sizeStr(char a[]){
    unsigned char count=0;
    while(a[count++]!='\0'){};
    return count-1;
}