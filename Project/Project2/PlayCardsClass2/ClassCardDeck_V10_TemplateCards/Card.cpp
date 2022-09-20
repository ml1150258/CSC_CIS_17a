/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 5th, 2019, 12:36 PM
 * Purpose:  Card Class Implementation
 */


#include "Card.h"
        
Card::Card(unsigned char n){
    crdNum=n%52;
}
        
unsigned char Card::suit(){
    char s[]={'S','D','C','H'};
    unsigned char n=crdNum/13;
    return s[n];
}
        
unsigned char Card::face(){
    char f[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    unsigned char n=crdNum%13;
    return f[n];
}
        
unsigned char Card::value(){
    unsigned char n=crdNum%13;
    n++;
    return n>10?10:n;
}