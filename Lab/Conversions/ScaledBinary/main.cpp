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
    unsigned char  l1Byte,h1Byte;//1 Byte representation
    unsigned short l2Byte,h2Byte;//2 Byte representation
    unsigned int   l3Byte,h3Byte;//3 Byte representation
    
    //Initialize or input i.e. set variable values
    value=254;      //Any value fitting in 1 Byte
    fracshn=5.0f/9; // 5/9=0.5555555.....
    l1Byte=0x8E;    //Low  1 Byte Rep of 9/5 x 2^8
    l1Byte=0b10001110;    //Low  1 Byte Rep of 9/5 x 2^8
    l1Byte=0216;    //Low  1 Byte Rep of 9/5 x 2^8
    h1Byte=0x8F;    //High 1 Byte Rep of 9/5 x 2^8
    l2Byte=0x8E38;  //Low  2 Byte Rep of 9/5 x 2^16
    h2Byte=0x8E39;  //High 2 Byte Rep of 9/5 x 2^16
    l3Byte=0x8E38E3;//Low  3 Byte Rep of 9/5 x 2^24
    h3Byte=0x8E38E4;//High 3 Byte Rep of 9/5 x 2^24
    
    //Heading
    cout<<"                 Result     Integer vs. Fraction"<<endl;
    
    //Answer using a float
    product=value*fracshn;
    cout<<"Using floats     "<<value*fracshn<<"  = "<<static_cast<int>(value)<<" * "<<fracshn<<endl;
    cout<<"Using integers   "<<product<<"      = "<<static_cast<int>(value)<<" * "<<fracshn<<endl;

    //Answer using 1 Byte Integer - Low
    product=value*l1Byte;//2^8 too much
    product>>=8;         //Shift it right 8 bits;
    cout<<"Using 1Byte Low  "<<product<<"      = "<<static_cast<int>(value)<<" * "
            <<(int)(l1Byte)<<"      shift >>  8 bits"<<endl;

    //Answer using 1 Byte Integer - High
    product=value*h1Byte;//2^8 too much
    product>>=8;         //Shift it right 8 bits;
    cout<<"Using 1Byte High "<<product<<"      = "<<static_cast<int>(value)<<" * "
            <<(int)(h1Byte)<<"      shift >>  8 bits"<<endl;

    //Answer using 2 Byte Integer - Low
    product=value*l2Byte;//2^16 too much
    product>>=16;        //Shift it right 16 bits;
    cout<<"Using 2Byte Low  "<<product<<"      = "<<static_cast<int>(value)<<" * "
            <<l2Byte<<"    shift >> 16 bits"<<endl;
    //Answer using 2 Byte Integer - High
    product=value*h2Byte;//2^16 too much
    product>>=16;        //Shift it right 16 bits;
    cout<<"Using 2Byte High "<<product<<"      = "<<static_cast<int>(value)<<" * "
            <<h2Byte<<"    shift >> 16 bits"<<endl;

    //Answer using 3 Byte Integer - Low
    product=value*l3Byte;//2^24 too much
    product>>=24;        //Shift it right 24 bits;
    cout<<"Using 3Byte Low  "<<product<<"      = "<<static_cast<int>(value)<<" * "
            <<l3Byte<<"  shift >> 24 bits"<<endl;

    //Answer using 3 Byte Integer - High
    product=value*h3Byte;//2^24 too much
    product>>=24;        //Shift it right 24 bits;
    cout<<"Using 3Byte High "<<product<<"      = "<<static_cast<int>(value)<<" * "
            <<h3Byte<<"  shift >> 24 bits"<<endl;

    //Exit stage right or left!
    return 0;
}