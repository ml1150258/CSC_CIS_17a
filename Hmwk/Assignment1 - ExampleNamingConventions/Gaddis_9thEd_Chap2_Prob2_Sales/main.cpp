/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 9, 2020, 1:25 PM
 * Purpose:  Sales Percentage
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
    float totSls;//Total Company Sales in Dollars
    float pEstCst;//Percentage East Coast Sales
    int   eCstSls;//East Coast Sales in Dollars
    int   pCstSls;//East Coast Sales to nearest penny
    int   nDollars;//Number of Dollars
    int   nDimes;  //Number of Dimes
    int   nPennies;//Number of Pennies
    
    
    //Initialize Variables
    totSls=8.6e6f;//8.6 million dollars
    pEstCst=0.58f;//58 per cent
    
    //Paint the fence front and back twice
    eCstSls=totSls*pEstCst+0.5;//Rounding to nearest dollar
    pCstSls=(totSls*pEstCst+0.005)*100;//Rounded to the nearest penny
    nDollars=pCstSls/100;
    nDimes=(pCstSls-nDollars*100)/10;
    nPennies=pCstSls-nDollars*100-nDimes*10;
    
    //Display Outputs
    cout<<"East Coast Sales in Dollars = $"<<eCstSls<<endl;
    cout<<"East Coast Sales with Pennies = $"<<nDollars<<
            "."<<nDimes<<nPennies<<endl;

    //Exit stage right!
    return 0;
}