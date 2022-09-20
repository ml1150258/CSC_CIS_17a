/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 9, 2020, 1:02 PM
 * Purpose:  Customer Survey - No partial people
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
    int custSrv;  //Number of customers surveyed
    float pEDrnks;//Percentage Energy Drinkers
    float pCitFlv;//Percentage of Drinkers that prefer citrus flavor
    int nDrnkrs;//Number of Energy Drinkers
    int nCitFlv;//Number of Citrus Flavor Drinkers
    
    //Initialize Variables
    custSrv=16500;
    pEDrnks=0.15f;
    pCitFlv=0.58f;
    
    //Paint the fence front and back twice
    nDrnkrs=custSrv*pEDrnks+0.5f;//Round correctly by adding 1/2
    nCitFlv=custSrv*pEDrnks*pCitFlv+0.5f;//Round correctly by adding 1/2
    
    //Display Outputs
    cout<<"Number that Drink Energy Drinks = "<<nDrnkrs<<endl;
    cout<<"Number that prefer a Citrus Flavor = "<<nCitFlv<<endl;

    //Exit stage right!
    return 0;
}