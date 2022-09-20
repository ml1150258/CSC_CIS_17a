/* 
 * File:   D8Time.h
 * Author: Dr. Mark E. Lehr
 * Created on July 21, 2020, 12:54 PM
 * Purpose:  Date-Time Class Specification
 */

#ifndef D8TIME_H
#define D8TIME_H

#include "DateWS.h"
#include "TimeMEL.h"

class D8Time{
    private:
        DateWS *datews;
        TimeMEL *timemel;
    public:
        D8Time(string,string,int,int,int,int);
        ~D8Time(){
            delete datews;
            delete timemel;
        }
        string getSMon(){return datews->getSMon();}
        int getDay(){return datews->getDay();}
        int getYear(){return datews->getYear();}
        string cnvrtDy(){return datews->cnvrtDy();}
        string getTime(){return timemel->getTime();}
};

D8Time::D8Time(string sMonth,string sDay,int year,int hrs,int min,int sec){
    datews=new DateWS(sMonth,sDay,year);
    timemel=new TimeMEL(hrs,min,sec);
}

#endif /* D8TIME_H */

