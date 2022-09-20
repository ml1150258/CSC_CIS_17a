/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 21, 2020, 1:07 PM
 * Purpose:   Date and Time Class Utilized
 */

//System Libraries Here
#include <iostream>
#include <string>
using namespace std;

//User Libraries Here
#include "D8Time.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare the input Variables
    string sMonth,sDay;//Month and Day in a string
    int nSecs,//Integer Seconds, Hours, Minutes, and Year
        nHrs,
        nMin,
        year;
    char dummy;//Simple dummy input to show difference in time
    
    //Input or initialize values Here
    cout << "Program computes day of week from Date" <<endl;
    cout << "Input the Date, Month day, Year" << endl;
    cout << "Example July 4, 2008" << endl;
    cin >> sMonth >> sDay >> year;
    cout<<"Now Input the number of hrs, min, secs"<<endl;
    cin>>nHrs>>nMin>>nSecs;
    
    //Instantiate the Date and Time Class
    D8Time now(sMonth,sDay,year,nHrs,nMin,nSecs);
    
    //Output the Day of the Week and Time
    cout << now.getSMon() << " " << now.getDay() <<", "<< now.getYear()
         << " is " << now.cnvrtDy()<<endl;
    cout <<"24 hour time =  "<<now.getTime()<<endl<<endl;
    
    //Now wait a few minutes and output the time
    cout<<"Wait a few seconds then type in a char and output the time again"<<endl;
    cin>>dummy;
    //Output the Day of the Week and Time
    cout << endl <<now.getSMon() << " " << now.getDay() <<", "<< now.getYear() 
             << " is " << now.cnvrtDy()<<" at "<<now.getTime()<<endl;
    
    //Exit
    return 0;
}