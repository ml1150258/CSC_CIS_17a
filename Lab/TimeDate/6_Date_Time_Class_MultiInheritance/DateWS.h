/* 
 * File:   DateWS.h
 * Author: Dr. Mark E. Lehr
 * Created on July 21, 2020, 12:54 PM
 * Purpose:  Date Class Specification
 */

#ifndef DATEWS_H
#define DATEWS_H

#include <string>
using namespace std;

class DateWS{
    private:
        string sMonth, sDay;
        int month, day, year;
        int gtCntry(int);
        int gtYrVal(int);
        int gtMnVal(int, int);
    public:
        DateWS(string,string,int);
        bool isLpYr(int);
        int dayOfWk(int, int, int);
        int cnvrtMn(string);
        int cnvrtDy(string);
        string cnvrtDy(int);
        string cnvrtDy(){return cnvrtDy(dayOfWk(month, day, year));}
        string getSMon(){return sMonth;}
        string getSDay(){return sDay;}
        int getMon(){return month;}
        int getDay(){return day;}
        int getYear(){return year;}
};


#endif /* DATEWS_H */

