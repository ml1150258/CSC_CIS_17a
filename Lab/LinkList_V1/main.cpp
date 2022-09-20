/*
    Author: Dr. Mark E. Lehr
    Date:   November 29th, 2021  1:12pm
    Purpose:Linked from first principles
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <cstdlib>     //NULL pointer
using namespace std;   //Library Name-space

//User Libraries
struct Link{
    int data;     //Some type of data
    Link *lnkNext; //Next Link in the chain
};

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    
    //Declare variables
    Link *lnk1=new Link;
    Link *lnk2=new Link;
    Link *lnk3=new Link;
    Link *lnk4=new Link;
    Link *lnk5=new Link;
    
    //Fill the structures with data
    (*lnk1).data=1;
    lnk2->data=2;
    lnk3->data=3;
    lnk4->data=4;
    lnk5->data=5;
    
    //Point the individual pointers to the next link
    lnk1->lnkNext=lnk2;
    lnk1->lnkNext->lnkNext=lnk3;//lnk2->lnkNext
    lnk1->lnkNext->lnkNext->lnkNext=lnk4;
    lnk1->lnkNext->lnkNext->lnkNext->lnkNext=lnk5;
    lnk1->lnkNext->lnkNext->lnkNext->lnkNext->lnkNext=NULL;
    
    //Display your initial conditions as well as outputs.
    Link *next=lnk1;
    while(next!=NULL){
        cout<<next->data<<endl;
        next=next->lnkNext;
    }
    
    //Delete all the allocated memory
    delete lnk1,lnk2,lnk3,lnk4,lnk5;
    
    //Exit stage right
    return 0;
}