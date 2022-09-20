/* 
 * File:   Array1D.h
 * Author: Dr. Mark E. Lehr
 * Purpose:  A Structured 2D Array
 * Created on September 30, 2019, 1:48 PM
 */

#ifndef ARRAY2D_H
#define ARRAY2D_H

const int ROWSIZE=4;
const int COLSIZE=3;

struct Array2D{
    int row;
    int col;
    int data[ROWSIZE][COLSIZE];
};


#endif /* ARRAY2D_H */

