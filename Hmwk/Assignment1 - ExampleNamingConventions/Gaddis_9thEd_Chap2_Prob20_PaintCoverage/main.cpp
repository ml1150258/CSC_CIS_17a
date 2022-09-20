/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 9, 2020, 12:35 PM
 * Purpose:  Painters Profit
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    float fLen,fHght;//Fence Height and Width in ft
    float srfArea,pntArea;//Surface Area and Painted Area ft^2
    float pCvrage;//Paint Can Coverage in ft^2
    int nCans;//Number of cans of paint required.
    
    //Initialize Variables
    fLen=100.0f;//100 feet in Length
    fHght=6.0f;//6 feet in Height
    pCvrage=340;//340 square feet
    
    //Paint the fence front and back twice
    srfArea=fLen*fHght;//Surface area of fence 1 side
    pntArea=4*srfArea;//Painted area like 4 sides of 1 fence 1 side
    nCans=pntArea/pCvrage+1;//No partial cans of paint
    
    //Display Outputs
    cout<<"Fence Height = "<<fHght<<" ft"<<endl;
    cout<<"Fence Length = "<<fLen<<" ft"<<endl;
    cout<<"Number of cans of Paint = "<<nCans<<endl;

    //Exit stage right!
    return 0;
}