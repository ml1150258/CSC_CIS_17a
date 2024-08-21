/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on October 19th, 2022, 1:20 PM
 * Purpose:  1D Array Class Specification
 */

#ifndef CLASS1DARRAY_H
#define CLASS1DARRAY_H

class DynAry1{
    private:
        int size;
        int *array;
    public:
        DynAry1(int);
        void setArray(int,int);
        int  getSize();
        int  getData(int);
        ~DynAry1(){delete []array;};
        void prnStrc(int);
};



#endif /* STRUC1DARRAY_H */

