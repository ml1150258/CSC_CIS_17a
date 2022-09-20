/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 25th, 2020, 6:15 AM
 * Purpose:  Create a file, Read the file, output the statistics
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream>   //File I/O
#include <cstdlib>   //Random number seed and generator
#include <ctime>     //Setting the random number seed with time
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants, Higher Dimensioned
//Arrays, and Conversions
const unsigned char DAYS=30; //Number of Days in the Summer Months
const unsigned char MONTHS=3;//Number of Months for the Summer

//Function Prototypes
void wrtFile(fstream &,char[]);                 //Write Weather Data
void rdFile(fstream &,string,char [][DAYS],int);//Read Weather Data
void prntDat(char [][DAYS],int);                //Print the Results
string stats(char [][DAYS],char [][MONTHS]);    //Examine and output the Stats
void prtStat(char [][MONTHS]);                  //Print the statistics

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));//Set the seed with time
    
    //Declare all variables for this function
    char data[MONTHS][DAYS];           //Data
    char stat[MONTHS][MONTHS];         //Statistics
    fstream fileIO;                    //Input/Output file
    char cnmFile[]="RainOrShine.txt";  //Char File Name
    string snmFile=cnmFile;            //String File Name
    string rnMnth;                     //Which month had the most rain?
    
    //Initialize all known variables
    wrtFile(fileIO,cnmFile);
    rdFile(fileIO,snmFile,data,MONTHS);
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    rnMnth=stats(data,stat);
    
    //Display the Inputs/Outputs
    prntDat(data,MONTHS);
    prtStat(stat);
    cout<<rnMnth<<" had the most rain!"<<endl;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

void prtStat(char stat[][MONTHS]){
    string months[MONTHS]={"JUNE  ","JULY  ","AUGUST"};
    char weather[MONTHS+1]="SCR";
    cout<<endl<<"Weather statistics Data for the Summer Months"<<endl;
    cout<<"        ";
    for(int col=0;col<MONTHS;col++){
            cout<<setw(2)<<weather[col]<<" ";
    }
    cout<<endl;
    for(int row=0;row<MONTHS;row++){
        cout<<months[row]<<"  ";
        for(int col=0;col<MONTHS;col++){
            cout<<setw(2)<<static_cast<unsigned int>(stat[row][col])<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

string stats(char data[][DAYS],char stat[][MONTHS]){
    //Initialize stat
    for(int row=0;row<MONTHS;row++){
        for(int col=0;col<MONTHS;col++){
            stat[row][col]=0;
        }
    }
    //Quantify the data
    for(int month=0;month<MONTHS;month++){
        for(int day=0;day<DAYS;day++){
            switch(data[month][day]){
                case 'S':stat[month][0]++;break;
                case 'C':stat[month][1]++;break;
                default:stat[month][2]++;
            }
        }
    }
    //Which month had the most rain
    string wchMnth="JUNE";
    if(stat[1][2]>stat[0][2]&&stat[1][2]>stat[2][2])wchMnth="JULY";
    if(stat[2][2]>stat[1][2]&&stat[2][2]>stat[0][2])wchMnth="AUGUST";
    return wchMnth;
}

void prntDat(char data[][DAYS],int MONTHS){
    string months[]={"JUNE  ","JULY  ","AUGUST"};
    cout<<"Weather Data for the Summer Months"<<endl;
    cout<<"        ";
    for(int day=0;day<DAYS;day++){
            cout<<setw(2)<<day+1<<" ";
    }
    cout<<endl;
    for(int month=0;month<MONTHS;month++){
        cout<<months[month]<<"  ";
        for(int day=0;day<DAYS;day++){
            cout<<setw(2)<<data[month][day]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void rdFile(fstream &in,string fn,char data[][DAYS],int MONTHS){
    in.open(fn,ios::in);
    for(int month=0;month<MONTHS;month++){
        for(int day=0;day<DAYS;day++){
            in>>data[month][day];
        }
    }
    in.close();
}

void wrtFile(fstream &out,char fn[]){
    const int SIZE=10;
    char weather[SIZE+1]="SSSSSSCCCR";
    out.open(fn,ios::out);
    for(int month=0;month<MONTHS;month++){
        for(int day=0;day<DAYS;day++){
            out<<weather[rand()%SIZE]<<" ";
        }
        out<<endl;
    }
    out<<endl;
    out.close();
}