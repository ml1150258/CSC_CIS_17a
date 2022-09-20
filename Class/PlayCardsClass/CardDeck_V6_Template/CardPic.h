/* 
 * File:   CardPic.h
 * Author: mlehr
 * Purpose:  To show behavior associated with a template!
 * Created on June 1, 2021, 2:29 PM
 */
#include <string>
using namespace std;

#include "Card.h"

#ifndef CARDPIC_H
#define CARDPIC_H

class CardPic:public Card{
    private:
        string nameit;
    public:
        CardPic(unsigned char c,string nme=".jpg"):Card(c){
            nameit=nme;
        };
        string getName(){return nameit;}
};

#endif /* CARDPIC_H */

