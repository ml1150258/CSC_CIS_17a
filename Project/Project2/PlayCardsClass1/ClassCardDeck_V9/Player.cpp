/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 12th, 2019, 10:30 AM
 * Purpose:  Player Class Implementation
 */

#include "Player.h"

Player::Player(string n){
    name=n;
}
        
void Player::setHand(Hand *h){
    hand=h;
}
        
void Player::prntHnd(){
    hand->display();
}