/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Arabic Number to Roman Numerals
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    unsigned short n2Cnvrt;
    
    //Initialize Variables
    cout<<"This program converts Arabic to Roman Numerals"<<endl;
    cout<<"Input a number between 1 - 3000"<<endl;
    cin>>n2Cnvrt;
    //Check for a valid input
    if(n2Cnvrt>=1 && n2Cnvrt<=3000){
    //Process or map Inputs to Outputs
        //Determine 1000's, 100's, 10's, 1's
        unsigned char n1000s,n100s,n10s,n1s;
        n1000s=n2Cnvrt/1000;   //Shift 3 places to the left
        n100s=n2Cnvrt%1000/100;//Remainder of division of 1000 then shift 2 left
        n10s=n2Cnvrt%100/10;   //Remainder of division of 100 then shift 1 left
        n1s=n2Cnvrt%10;        //Remainder of division by 10
        
        //Output the number of 1000's in Roman Numerals
        //Using the Switch Statement
        switch(n1000s){
            case 3:cout<<'M';
            case 2:cout<<'M';
            case 1:cout<<'M';
        }
        
        //Output the number of 100's
        //Using the Ternary Operator
        cout<<(n100s==9?"CM":
               n100s==8?"DCCC":
               n100s==7?"DCC":
               n100s==6?"DC":
               n100s==5?"D":
               n100s==4?"CD":
               n100s==3?"CCC":
               n100s==2?"CC":
               n100s==1?"C":"");
        
        //Output the number of 10's
        //Using Independent If Statements
        if(n10s==9)cout<<"XC";
        if(n10s==8)cout<<"LXXX";
        if(n10s==7)cout<<"LXX";
        if(n10s==6)cout<<"LX";
        if(n10s==5)cout<<"L";
        if(n10s==4)cout<<"XL";
        if(n10s==3)cout<<"XXX";
        if(n10s==2)cout<<"XX";
        if(n10s==1)cout<<"X";
        
        //Output the number of 1's
        //Using Dependent If Statements
        if(n1s==9)cout<<"IX";
        else if(n1s==8)cout<<"VIII";
        else if(n1s==7)cout<<"VII";
        else if(n1s==6)cout<<"VI";
        else if(n1s==5)cout<<"V";
        else if(n1s==4)cout<<"IV";
        else if(n1s==3)cout<<"III";
        else if(n1s==2)cout<<"II";
        else if(n1s==1)cout<<"I";
        
        //Reiterate the input value
        cout<<" = "<<n2Cnvrt<<endl;
                
    //The Path to Exit
    }else{
        cout<<"You have problems following Directions"<<endl;
        cout<<"Come back when you decide to comply"<<endl;
    }

    //Exit stage right!
    return 0;
}