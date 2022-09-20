/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Scaled Binary - How to use integers
 *           in place of floating point numbers
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    unsigned int product;//Just a product of a multiplicative operation
    unsigned char value; //Just a value within 1 Byte
    float fracshn;//Simple Fraction
    unsigned int   l3Byte;//3 Byte representation
    
    //Initialize or input i.e. set variable values
    value=254;      //8WD 0BP
    fracshn=5.0f/9; // 5/9=0.5555555.....
    l3Byte=0x8E38E3;//24WD 24Bp
    l3Byte=0b100011100011100011100011;//24WD 24Bp
    l3Byte=043434343;//24WD 24Bp
    
    //Heading
    cout<<"                 Result     Integer vs. Fraction"<<endl;
    
    //Answer using a float
    product=value*fracshn;
    cout<<"Using floats     "<<value*fracshn<<"  = "<<static_cast<int>(value)<<" * "<<fracshn<<endl;
    cout<<"Using integers   "<<product<<"      = "<<static_cast<int>(value)<<" * "<<fracshn<<endl;

    //Answer using 3 Byte Integer - Low
    product=value*l3Byte;//32WD 24BP
    product>>=24;        // 8WD  0BP
    cout<<"Using 3Byte Low  "<<product<<"      = "<<static_cast<int>(value)<<" * "
            <<l3Byte<<"  shift >> 24 bits"<<endl;

    //Exit stage right or left!
    return 0;
}