/* 
 * File:   TimeMEL.h
 * Author: Dr. Mark E. Lehr
 * Created on July 21, 2020, 12:54 PM
 * Purpose:  Time Class Implementation
 */

#include "TimeMEL.h"
#include <ctime>
using namespace std;

TimeMEL::TimeMEL(int hrs,int min,int sec){
    nowSecs=(static_cast<unsigned int>(time(0)));
    setHrs=hrs;
    setMin=min;
    setSecs=sec;
}

void TimeMEL::update(){
    //The difference in Time
    int diff=static_cast<unsigned int>(time(0))-nowSecs;
    
    //Declare variables
    int nSecs=diff+setHrs*HOUR+setMin*MINUTE+setSecs;
    int nYrs,nMnths,nWks,nDys,nHrs,nMin;
    
    //Map inputs to outputs or process the data
    nYrs=nSecs/YEAR;          //Number of Years
    nSecs-=nYrs*YEAR;         //Subtract the yearly seconds from remaining
    
    nWks=nSecs/WEEK;          //Number of weeks
    nMnths=nWks*3/13;         //Convert number of weeks to months
    nSecs-=nWks*WEEK;         //Subtract the weekly seconds from remaining
    
    nDys=nSecs/DAY;           //Number of days
    nSecs-=nDys*DAY;          //Subtract the daily seconds from remaining
    
    nHrs=nSecs/HOUR;          //Number of hours
    nSecs-=nHrs*HOUR;         //Subtract the hourly seconds from remaining
    
    nMin=nSecs/MINUTE;        //Number of minutes
    
    nSecs-=nMin*MINUTE;       //Remaining number of seconds
    
    //Update the quantities
    hours=nHrs;
    minutes=nMin;
    seconds=nSecs;
    
    //Create Time String
    sTime="";
    sTime+=((nHrs/10<0)?'0':static_cast<char>(nHrs/10+'0'));
    sTime+=static_cast<char>(nHrs%10+'0');
    sTime+=':';
    sTime+=((nMin/10<0)?'0':static_cast<char>(nMin/10+'0'));
    sTime+=static_cast<char>(nMin%10+'0');
    sTime+=':';
    sTime+=((nSecs/10<0)?'0':static_cast<char>(nSecs/10+'0'));
    sTime+=static_cast<char>(nSecs%10+'0');
}