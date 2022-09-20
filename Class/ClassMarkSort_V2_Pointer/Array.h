/* 
 * File:   Array.h
 * Author: mlehr
 * Created on November 3, 2021, 1:54 PM
 * Purpose:  Class Specification
 */

#ifndef ARRAY_H
#define ARRAY_H

class Array{
    private:
        int size;
        int *data;
    public:
        Array(int);
        ~Array();
        void sort();
        void display(int);
};


#endif /* ARRAY_H */

