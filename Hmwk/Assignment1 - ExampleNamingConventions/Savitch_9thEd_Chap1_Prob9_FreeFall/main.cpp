/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 9, 2020, 11:45 AM
 * Purpose:  Free Fall Homework Problem
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const float GRAVITY=32.174f;//English units for acceleration of gravity ft/sec^2

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    float time,freFall;
    
    //Initialize Variables
    cout<<"This program calculates free fall given time"<<endl;
    cout<<"Input free fall time in seconds"<<endl;
    cin>>time;
    
    //Process or map Inputs to Outputs
    freFall=0.5f*GRAVITY*time*time;
    
    //Display Outputs
    cout<<"With free fall time = "<<time<<" seconds "<<
            "the object dropped "<<freFall<<" ft"<<endl;

    //Exit stage right!
    return 0;
}