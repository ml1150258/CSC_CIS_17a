/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 13, 2020, 1:05 PM
 * Purpose:  Monthly Payment
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Format Library
#include <cmath>     //Math Library
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const float CVNPEN=100.0f; //Conversion to Pennies
const float HALFPEN=0.005f;//1/2 PENNY

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    unsigned int nCmpd; //Number of Compounding Periods in Months
    double   inRate,//Interest Rate in %/month
            loan,  //Loan in $'s
            mnPmt, //Monthly Payment in $'s
            totPmt,//Total Payment in $'s
            inPaid;//Interest Paid in $'s
    
    //Initialize Variables
    nCmpd=36;
    inRate=1e-2f;//1%
    loan=1e4f;   //$10,000
    
    //Process or map Inputs to Outputs
    float temp=pow(1+inRate,nCmpd);
    mnPmt=((inRate==0)?(loan/nCmpd):(inRate*temp*loan/(temp-1)));
    totPmt=mnPmt*nCmpd; //All Monthly Payments
    inPaid=totPmt-loan; //Cost of the Loan
    
    //Display Outputs
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"InCorrect Calculations using doubles and no Penny Corrections"<<endl;
    cout<<"Total has a 11 cent error!"<<endl;
    cout<<"Loan:                $ "<<loan<<endl;
    cout<<"Number of Months       "<<setw(5)<<nCmpd<<endl;
    cout<<"Monthly Interest:       "<<setw(8)<<inRate<<endl;
    cout<<"Monthly Payment:     $ "<<setw(8)<<mnPmt<<endl;
    cout<<"Total Paid for Loan: $ "<<totPmt<<endl;
    cout<<"Total Interest Paid: $ "<<setw(8)<<inPaid<<endl;

    //Exit stage right!
    return 0;
}