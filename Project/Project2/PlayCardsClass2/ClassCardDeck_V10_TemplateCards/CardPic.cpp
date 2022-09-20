/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 28th, 2020, 12:36 PM
 * Purpose:  Card Class Implementation
 */


#include "CardPic.h"
        
CardPic::CardPic(unsigned char n):Card(n){}

string CardPic::getFile(){
    string fileNam="";
    fileNam+=face();
    fileNam+=suit();
    fileNam+=".jpg";
    return fileNam;
}