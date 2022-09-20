/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 22, 2020, 10:07 AM
 * Purpose:   get day of week V6
 */

//System Libraries Here
#include <iostream>
#include <string>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool isLpYr(int);
int gtCntry(int);
int gtYrVal(int);
int gtMnVal(int, int);
int dayOfWk(int, int, int);
int cnvrtMn(string);
int cnvrtDy(string);
string cnvrtDy(int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    string sMonth, sDay;
    int month, day, year;
    
    //Input or initialize values Here
    cout << "Program computes day of week from Date" <<endl;
    cout << "Input the Date, Month day, Year" << endl;
    cout << "Example July 4, 2008" << endl;
    cin >> sMonth >> sDay >> year;
    
    //Process/Calculations Here
    month = cnvrtMn(sMonth);
    day = cnvrtDy(sDay);
    cout << sMonth << " " << day << ", " << year << " is "
            << cnvrtDy(dayOfWk(month, day, year)) << endl;
    //Output Located Here

    //Exit
    return 0;
}

string cnvrtDy(int day){
    switch(day){
        case 0:
            return "Sunday";
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";    
    }
    return "Should never get to here!";
}

int cnvrtDy(string sDay){
    if(sDay.length() == 2){
        return sDay[0] - 48; 
    } else {
        return (sDay[0] - 48) * 10 + (sDay[1] - '0');
    }
}

int cnvrtMn(string sMonth){
    if(sMonth == "January") return 1;
    if(sMonth == "February") return 2;
    if(sMonth == "March") return 3;
    if(sMonth == "April") return 4;
    if(sMonth == "May") return 5;
    if(sMonth == "June") return 6;
    if(sMonth == "July") return 7;
    if(sMonth == "August") return 8;
    if(sMonth == "September") return 9;
    if(sMonth == "October") return 10;
    if(sMonth == "November") return 11;
    if(sMonth == "December") return 12;
    return 13;
}

int dayOfWk(int month, int day, int year){
    return (day + gtMnVal(month, year) + gtYrVal(year) + gtCntry(year)) % 7;
}

int gtMnVal(int month, int year){
    switch(month){
        case 1:
            return (isLpYr(year)? 6 : 0);
        case 2:
            return (isLpYr(year)? 2 : 3);
        case 3:
        case 11:
            return 3;
        case 4:
        case 7:
            return 6;
        case 5:
            return 1;
        case 6:
            return 4;
        case 8:
            return 2;
        case 9:
        case 12:
            return 5;
        default:
            return 0;
    }
}

int gtYrVal(int year){
    return (year % 100) + (year % 100)/4;
}

int gtCntry(int year){
    return 2 * (3 - ((year / 100) % 4));
}

bool isLpYr(int year){
    return (!(year % 400) || (!(year % 4) && (year % 100)));
}