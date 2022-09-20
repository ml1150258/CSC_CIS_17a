/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   November 4th, 2019
 * Purpose:Card Class Implementation
 */

#include "Card.h"

Card::Card(unsigned char n){
    crdNum=(n>0?n:0);
}

char Card::value(){
    int n=crdNum;
    n>=0?n%=13:0;
    n++;
    if(n>10)n=10;
    return n;
}

char Card::face(){
    int n=crdNum;
    n>=0?n%=52:0;
    char faces[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    return faces[n%13];
}

char Card::suit(){
    int n=crdNum;
    n>=0?n%=52:0;
    char suits[]={'S','D','C','H'};
    return suits[n/13];
}