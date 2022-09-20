/* 
 * File:   DBOrder.h
 * Author: mlehr
 * Created on October 11, 2021, 1:19 PM
 * Purpose:  Data Base Ordering Structure
 */

#ifndef DBORDER_H
#define DBORDER_H
#include "Array.h"

struct DBOrder{
    Array *data;
    Array *index;
};

#endif /* DBORDER_H */

