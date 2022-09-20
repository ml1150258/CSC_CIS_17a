/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 21, 2020, 1:07 PM
 * Purpose:   Date Class
 */

//System Libraries Here
#include <iostream>
#include <string>
using namespace std;

//User Libraries Here
#include "DateWS.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare the input Variables
    string sMonth,sDay;
    int year;
    
    //Input or initialize values Here
    cout << "Program computes day of week from Date" <<endl;
    cout << "Input the Date, Month day, Year" << endl;
    cout << "Example July 4, 2008" << endl;
    cin >> sMonth >> sDay >> year;
    
    //Instantiate the Date Class
    DateWS now(sMonth,sDay,year);
    
    //Output the Day of the Week
    cout << now.getSMon() << " " << now.getDay() <<", "<< now.getYear() 
            << " is " << now.cnvrtDy() << endl;
    cout<<now.getYear()
            <<(now.isLpYr(now.getYear())?" is":" is not")
            <<" a leap year"<<endl;
            

    //Exit
    return 0;
}