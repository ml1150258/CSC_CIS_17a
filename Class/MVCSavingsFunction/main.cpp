/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   February 24th, 2020
 * Purpose:No MVC with Savings Function
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void  savings(float [],float,int);
void  display(float [],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    
    //Declare Variables
    const int n=13;
    float pv[n],i;
    
    //Initialize Variables
    pv[0]=100.0f;
    i=0.06f;
    
    //Process inputs to outputs/map
    savings(pv,i,n);
    
    //Display the results
    display(pv,n);

    //Clean up and exit stage right
    return 0;
}

void  display(float pv[],int n){
    cout<<fixed<<setprecision(3)<<showpoint;
    cout<<"Year Savings"<<endl;
    for(int year=0;year<n;year++){
        cout<<setw(4)<<year
                <<setw(8)<<pv[year]<<endl;
    }
}

void savings(float pv[],float j,int n){
    for(int i=1;i<n;i++){
        pv[i]=pv[i-1]*(1+j);
    }
}