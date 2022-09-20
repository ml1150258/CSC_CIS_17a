/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 29th, 2020, 06:04 PM
 * Purpose: Round Up Currency to Nearest Penny
 */

//System Level Libraries
#include <iostream>   //I/O Library
using namespace std;  //Libraries compiled under std

//User Level Libraries

//Global Constants - Science/Math Related
//Conversions, Higher Dimensions
const float HLFPNY=0.005f;//Equivalent to 1/2 Penny
const float CNVDOL=100.0f;//Conversion Pennies the Dollar

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Random Number Seed Set Here
    
    //Variable Declarations
    float prcGas;//The change we are rounding up
    float toThPny;//Price of Gas to the Penny
    
    //Variable Initialization
    prcGas=2.879f;//Price of a regular gallon of gas  06/29/20
    cout<<"The price of Gas initialized                       ->$"<<prcGas<<endl;
    
    //Mapping Process Inputs to Outputs
    toThPny=prcGas+HLFPNY;   //Add the 1/2 Penny
    cout<<"Intermediate Value of To the Penny                 ->$"<<toThPny<<endl;
    int shift=toThPny*CNVDOL;//Lop off fractional pennies
    cout<<"Shift and truncate to an integer number of pennies ->"<<shift
            <<" cents"<< endl;
    toThPny=shift/CNVDOL;    //Shift Back
    cout<<"Rounded to the nearest Penny                       -> "<<toThPny<<endl;
    
    //Display Outputs
    cout<<"The Price of Gas to Fractional Pennies = $"<<prcGas<<endl;
    cout<<"The Price of Gas to the Penny          = $"<<toThPny<<endl;
 
    //Clean Up

    
    //Exit stage right!
    return 0;
}