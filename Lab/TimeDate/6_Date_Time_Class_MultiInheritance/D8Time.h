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

class D8Time:public DateWS,public TimeMEL{
    public:
        D8Time(string sMonth,string sDay,int year,int hrs,int min,int sec):
               DateWS(sMonth,sDay,year),
               TimeMEL(hrs,min,sec){};
};

#endif /* D8TIME_H */

