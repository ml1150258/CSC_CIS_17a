/* 
 * File:   TimeMEL.h
 * Author: Dr. Mark E. Lehr
 * Created on July 21, 2020, 12:54 PM
 * Purpose:  Time Class Specification
 */

#ifndef TIMEMEL_H
#define TIMEMEL_H

#include <string>
using namespace std;

class TimeMEL{
    private:
        string sTime;
        int hours,minutes,seconds;
        int nowSecs;
        int setHrs,setMin,setSecs;
        void update();
    public:
        TimeMEL(int,int,int);
        const int  MINUTE=60;     //How many seconds in a minute
        const int  HOUR=60*MINUTE;//How many seconds in a hour
        const int  DAY=24*HOUR;   //How many seconds in a day
        const int  WEEK=7*DAY;    //How many seconds in a week
        const int  YEAR=52*WEEK;  //How many seconds in a year
        string getTime(){update();return sTime;}
        int getHrs(){update();return hours;}
        int getMin(){update();return minutes;}
        int getSecs(){update();return seconds;}
};

#endif /* TIMEMEL_H */

