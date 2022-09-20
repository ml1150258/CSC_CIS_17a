/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 21, 2021, 11:19 AM
 * Purpose:  Develop a Template to be copied
 *           for all future programs in CSC/CIS 5
 */

//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int a,char ** b){
    //Declare all Variables Here
    bool x,y;
    char count=0;
    
    //Display the Heading
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y "<<
          " !(X||Y) !X&&!Y"<<endl;
    
    //Read all the rows
   while(cin>>x>>y && count++<4){
        cout<<(x?'T':'F')<<" "
            <<(y?'T':'F')<<"  "
            <<(!x?'T':'F')<<"  "
            <<(!y?'T':'F')<<"   "
            <<(x&&y?'T':'F')<<"    "
            <<(x||y?'T':'F')<<"   "
            <<(x^y?'T':'F')<<"    "
            <<(x^y^x?'T':'F')<<"   "
            <<endl;
   }
   cout<<endl;
    

    //Exit
    return 0;
}