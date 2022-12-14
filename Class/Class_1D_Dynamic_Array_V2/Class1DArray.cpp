/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on October 19th, 2022, 1:20 PM
 * Purpose:  1D Array Class Implementation
 */
      
#include "Class1DArray.h"

void DynAry1::setSize(int n){
    size=n<2?2:
         n>1000?1000:n;
}

void DynAry1::setArray(int *ptr){
    array=ptr;
}

int  DynAry1::getSize(){
    return size;
}

int  DynAry1::getData(int indx){
    int value=-999;
    if(indx>=0&&indx<=size-1)return array[indx];
    return value;
}