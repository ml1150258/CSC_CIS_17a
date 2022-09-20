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
float savings(float,float,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    
    //Declare Variables
    float pv,i;
    int n;
    
    //Initialize Variables
    pv=100.0f;
    i=0.06f;
    n=12;
    
    //Process inputs to outputs/map
    cout<<fixed<<setprecision(3)<<showpoint;
    cout<<"Year Savings"<<endl;
    for(int year=0;year<=n;year++){
        cout<<setw(4)<<year
                <<setw(8)<<savings(pv,i,year)<<endl;
    }
    
    //Display the results

    //Clean up and exit stage right
    return 0;
}

float savings(float pv,float j,int n){
    for(int i=1;i<=n;i++){
        pv*=(1+j);
    }
    return pv;
}