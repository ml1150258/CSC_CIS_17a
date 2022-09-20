/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MovieInfo.h
 * Author: mlehr
 *
 * Created on August 29, 2022, 12:15 PM
 */

#ifndef MOVIEINFO_H
#define MOVIEINFO_H

struct MovieInfo{
    string movName;//Strings are good
    char *dirName;//You should know how to deal with dynamic character arrays
    unsigned short yrRlsd; //Don't need a larger data size and always > 0
    unsigned short runTime;//Don't need a larger data size and always > 0
};

#endif /* MOVIEINFO_H */

