/* 
 * File:   main.cpp
 * Author: Dr. Mark Lehr
 * Created on November 9th, 2022, 1:20 PM
 * Purpose:  Constructor/Array Example
 */

//System Libraries
#include <iostream>  //Input/output Library
using namespace std;

//User Libraries
//With Constructor
class A{
    private:
        int n;
    public:
        A(int n){this->n=n;}
        int getN(){return n;}
};
//Without Constructor
class B{
    private:
        int n;
    public:
        void setB(int n){this->n=n;}
        int getN(){return n;}
};


//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes

//Program Execution Begins Here!!!
int main(int argc, char** argv) {
    //Set the Random Number Seed
    
    //Declare Variables
    int size=5;
    //A *a=new A[size];
    A **a=new A*[size];
    B *b=new B[size];
    
    //Initial Variables
    for(int i=0;i<size;i++){
        a[i]=new A(i);
        b[i].setB(i);
    }
    
    //Map the Inputs to the Outputs
    
    //Display the Inputs and Outputs
    cout<<"Contents of A"<<endl;
    for(int i=0;i<size;i++){
        cout<<a[i]->getN()<<endl;
    }
    cout<<"Contents of B"<<endl;
    for(int i=0;i<size;i++){
        cout<<b[i].getN()<<endl;
    }
    
    //Delete the allocated memory
    delete []b;
    for(int i=0;i<size;i++){
        delete a[i];
    }
    delete []a;

    //Exit the code
    return 0;
}

