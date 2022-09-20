/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 24th, 2019, 12:36 PM
 * Purpose:  Star Field with noise and position shift added
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
char **fillAry(int,int,int,int);//Stars with number and variations
char **shift(char **,int,int,int);
void noise(char **,int,int);
void prntAry(char **,int,bool);
void realokt(char **,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    char **plate,**shft;  //Original Star field without shift or noise
    int size,nstars,snoise,smag,bnoise,shiftx,shifty;
    
    //Initialize or input i.e. set variable values
    size=20;    //Rows and Columns of original plate
    nstars=10;  //Number of Stars in field
    snoise=25;  //Variables in star magnitude
    smag=50;    //Star magnitude
    bnoise=2;   //Background noise
    shiftx=2;   //Shift in x
    shifty=2;   //Shift in y
    
    
    //Map inputs -> outputs
    plate=fillAry(size,nstars,snoise,smag);
    shft=shift(plate,size,shiftx,shifty);
    
    //Display the outputs
    prntAry(plate,size,true);
    prntAry(shft,size,true);
    prntAry(plate,size,false);
    prntAry(shft,size,false);
    
    //Map inputs -> outputs
    noise(shft,size,bnoise);
    
    //Display the outputs
    prntAry(shft,size,true);
    prntAry(shft,size,false);
    
    //Recover Memory
    realokt(plate,size);
    realokt(shft,size);

    //Exit stage right or left!
    return 0;
}

char **shift(char **tmplet,int size,int xpos,int ypos){
    //Create the Plate to shift
    char **plate=new char*[size];
    for(int row=0;row<size;row++){
        plate[row]=new char[size];
    }
    //Initialize
    for(int row=0;row<size;row++){
        for(int col=0;col<size;col++){
            plate[row][col]='0';
        }
    }
    //Shift the stars
    for(int row=0;row<size;row++){
        for(int col=0;col<size;col++){
            int shifty=row+ypos;
            int shiftx=col+xpos;
            if(shiftx>=0&&shiftx<size&&shifty>=0&&shifty<size)
                plate[shifty][shiftx]=tmplet[row][col];
        }
    }
    return plate;
}

void realokt(char **plate,int size){
    for(int row=0;row<size;row++){
        delete []plate[row];
    }
    delete []plate;
}

void noise(char **plate,int size,int bnoise){
    //Fill with noise
    for(int row=0;row<size;row++){
        for(int col=0;col<size;col++){
            plate[row][col]+=(rand()%bnoise+1);
        }
    }
}

void prntAry(char **plate,int size,bool wide){
    char width=wide?4:1;
    cout<<endl;
    for(int row=0;row<size;row++){
        for(int col=0;col<size;col++){
            if(wide){
                cout<<setw(width)
                    <<(static_cast<int>(plate[row][col]));
            }else{
                cout<<setw(width)<<plate[row][col];
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

char **fillAry(int size,int nstars,int snoise,int smag){
    //Create the Plate
    char **plate=new char*[size];
    for(int row=0;row<size;row++){
        plate[row]=new char[size];
    }
    //Initialize
    for(int row=0;row<size;row++){
        for(int col=0;col<size;col++){
            plate[row][col]='0';
        }
    }
    //Fill with stars
    for(int star=1;star<nstars;star++){
        int xpos=rand()%size;
        int ypos=rand()%size;
        if(plate[ypos][xpos]==48)
            plate[ypos][xpos]+=(smag+rand()%(2*snoise+1)-snoise);
    }
    return plate;
}