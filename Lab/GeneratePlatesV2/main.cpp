/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 24th, 2019, 12:36 PM
 * Purpose:  Calculate shift from first plate
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time Library
#include <iomanip>   //Format Library
#include <fstream>   //Write the data to files
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void prntAry(char **,int,bool);
void realokt(char **,int);
void fileTag(char *);
void wrtAry(char *,char **,int,int,int);
char **readAry(char *fName,int &size);
void snr(char **,int,int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    char **plate,**shft;  //Original Star field without shift or noise
    int size,nstars,snoise,smag,bnoise,shiftx,shifty,nfiles;
    
    //Initialize or input i.e. set variable values
    size=20;    //Rows and Columns of original plate
    nstars=10;  //Number of Stars in field
    snoise=25;  //Variables in star magnitude
    smag=50;    //Star magnitude
    bnoise=2;   //Background noise
    nfiles=10;  //Number of files to create
    
    
    //Map inputs -> outputs
    char fName[]="0000Plate.dat";
    plate=readAry(fName,size);
    prntAry(plate,size,true);
    prntAry(plate,size,false);
    
    /*//Create the files
    char fName[]="0000Plate.dat";
    wrtAry(fName,plate,size);
    for(int files=-nfiles/2;files<nfiles/2;files++){
        fileTag(fName);
        shft=shift(plate,size,files,files);
        noise(shft,size,bnoise);
        wrtAry(fName,shft,size);
        realokt(shft,size);
    }*/

    //Recover Memory
    realokt(plate,size);

    //Exit stage right or left!
    return 0;
}

char **readAry(char *fName,int &size){
    //Read and size array from file
    ifstream in;
    in.open(fName);
    in>>size;
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
    //Read and fill from file
    for(int row=0;row<size;row++){
            in>>plate[row];
    }
    return plate;
}

void wrtAry(char *fName,char **plate,int size,int offRow,int offCol){
    ofstream out;
    out.open(fName);
    out<<size<<offRow<<offCol<<endl;
    for(int row=0;row<size;row++){
        for(int col=0;col<size;col++){
            out<<plate[row][col];
        }
        out<<endl;
    }
    out.close();
}

void fileTag(char *a){
    int aa=(a[0]-48)*1000+(a[1]-48)*100+(a[2]-48)*10+(a[3]-48);
    aa++;
    a[0]=aa/1000+48;
    aa%=1000;
    a[1]=aa/100+48;
    aa%=100;
    a[2]=aa/10+48;
    aa%=10;
    a[3]=aa+48;
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