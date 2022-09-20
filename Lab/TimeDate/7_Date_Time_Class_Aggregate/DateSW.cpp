/* 
 * File:   DateWS.h
 * Author: Dr. Mark E. Lehr
 * Created on July 21, 2020, 12:54 PM
 * Purpose:  Date Class Implementation
 */

#include "DateWS.h"

DateWS::DateWS(string sMonth,string sDay,int year){
    this->sMonth=sMonth;
    this->sDay=sDay;
    this->year=year;
    this->month = cnvrtMn(sMonth);
    this->day = cnvrtDy(sDay);
}

string DateWS::cnvrtDy(int day){
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

int DateWS::cnvrtDy(string sDay){
    if(sDay.length() == 2){
        return sDay[0] - 48; 
    } else {
        return (sDay[0] - 48) * 10 + (sDay[1] - '0');
    }
}

int DateWS::cnvrtMn(string sMonth){
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

int DateWS::dayOfWk(int month, int day, int year){
    return (day + gtMnVal(month, year) + gtYrVal(year) + gtCntry(year)) % 7;
}

int DateWS::gtMnVal(int month, int year){
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

int DateWS::gtYrVal(int year){
    return (year % 100) + (year % 100)/4;
}

int DateWS::gtCntry(int year){
    return 2 * (3 - ((year / 100) % 4));
}

bool DateWS::isLpYr(int year){
    return (!(year % 400) || (!(year % 4) && (year % 100)));
}