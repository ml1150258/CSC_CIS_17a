/* 
 * Author: Dr. Mark E. Lehr
 * Created on April 23rd, 2018, 11:42 AM
 * Purpose:  Project 2 - Simulate a Craps Game.
 *           Implement Arrays
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <ctime>     //Time for rand
#include <cstdlib>   //Srand to set the seed
#include <fstream>   //File I/O
#include <iomanip>   //Format the output
#include <string>    //Strings
#include <cmath>     //Math functions
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const float PERCENT=100.0f;//Conversion to Percent

//Function Prototypes
char rollDie(int);                                      //Roll the Dice
void fileDsp(ofstream &,int [],int [],int,int,int,int); //File Display
void scrnDsp(int [],int [],int,int,int,int);            //Screen Display
void crpGame(int [],int [],int,int &,int &,int &);      //Play Craps

//Execution begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare file and game variables
    ifstream in;               //Input File
    ofstream out;              //Output File
    int nGames;                //Number of games, wins/losses
    int mxThrw=0,numThrw=0,lmGames=100000000;//Game limiter and Throw statistics
    const int SIZE=13;         //Size of our Arrays
    int wins[SIZE]={};         //Initializing the win array
    int losses[SIZE]={};       //Initializing the loss array
    
    //Initialize variables
    string inName="GameInfo.dat";   //String Name
    char outName[]="GameStats.dat"; //Character Array Name
    in.open(inName.c_str());        //Open the Input file
    out.open(outName);              //Open the Output file
    while(in>>nGames);//Last value in file becomes the number of games
    nGames=nGames>lmGames?lmGames:nGames;//Limit games if to high
    
    //Play the game the prescribed number of times.
    int beg=time(0);//Time the game play
    crpGame(wins,losses,SIZE,nGames,numThrw,mxThrw);
    int end=time(0);//End time of Game play
    
    //Output the game statistics to the screen
    out<<"Total time to play these Games in integer seconds = "<<end-beg<<endl;
    scrnDsp(wins,losses,SIZE,nGames,numThrw,mxThrw);
    
    
    //Output the game statistics to the screen
    cout<<"Total time to play these Games in integer seconds = "<<end-beg<<endl;
    fileDsp(out,wins,losses,SIZE,nGames,numThrw,mxThrw);
    
    //Close files
    in.close();
    out.close();
    
    //Exit stage right
    return 0;
}

void crpGame(int wins[],int losses[],int SIZE,int &nGames,
                                           int &numThrw,int &mxThrw){
    for(int game=1;game<=nGames;game++){
        //Throw dice and sum, keep track of number of throws in a game
        int gmThrw=1;
        char sum1=rollDie(6);
        //Determine wins and losses
        switch(sum1){
            case  7:
            case 11:wins[sum1]++;break;
            case  2:
            case  3:
            case 12:losses[sum1]++;break;
            default:{
                //Loop until a 7 or previous sum is thrown
                bool thrwAgn=true;
                do{
                    //Throw the dice again
                    char sum2=rollDie(6);
                    gmThrw++;//Increment the number of throws
                    if(sum2==7){
                        losses[sum1]++;
                        thrwAgn=false;
                    }else if(sum1==sum2){
                        wins[sum1]++;
                        thrwAgn=false;
                    }//end of dependent if-else
                }while(thrwAgn);//end of do-while
            }
        }//end of switch
        //Keep track of total throws and max throws
        numThrw+=gmThrw;
        if(mxThrw<gmThrw)mxThrw=gmThrw;//Independent if
    }//end of for-loop
}

void fileDsp(ofstream &out,int wins[],int losses[],int SIZE,int nGames,int numThrw,int mxThrw){
    out<<fixed<<setprecision(2)<<showpoint;
    out<<"Total number of Games = "<<nGames<<endl;
    out<<"Roll     Wins     Losses"<<endl;
    int sWins=0,sLosses=0;
    for(int sum=2;sum<SIZE;sum++){
        sWins+=wins[sum];
        sLosses+=losses[sum];
        out<<setw(4)<<sum<<setw(10)<<wins[sum]<<setw(10)<<losses[sum]<<endl;
    }
    out<<"Total wins and losses = "<<sWins+sLosses<<endl;
    out<<"Percentage wins       = "
            <<static_cast<float>(sWins)/nGames*PERCENT<<"%"<<endl;
    out<<"Percentage losses     = "
            <<static_cast<float>(sLosses)/nGames*PERCENT<<"%"<<endl;
    out<<"Maximum number of throws in a game = "<<mxThrw<<endl;
    out<<"Average throw per game="<<static_cast<float>(numThrw)/nGames<<endl;
    out<<"Ratio of Longest to shortest game = 10^"<<log10(mxThrw)<<endl;

}

void scrnDsp(int wins[],int losses[],int SIZE,int nGames,int numThrw,int mxThrw){
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Total number of Games = "<<nGames<<endl;
    cout<<"Roll     Wins     Losses"<<endl;
    int sWins=0,sLosses=0;
    for(int sum=2;sum<SIZE;sum++){
        sWins+=wins[sum];
        sLosses+=losses[sum];
        cout<<setw(4)<<sum<<setw(10)<<wins[sum]<<setw(10)<<losses[sum]<<endl;
    }
    cout<<"Total wins and losses = "<<sWins+sLosses<<endl;
    cout<<"Percentage wins       = "
            <<static_cast<float>(sWins)/nGames*PERCENT<<"%"<<endl;
    cout<<"Percentage losses     = "
            <<static_cast<float>(sLosses)/nGames*PERCENT<<"%"<<endl;
    cout<<"Maximum number of throws in a game = "<<mxThrw<<endl;
    cout<<"Average throw per game="<<static_cast<float>(numThrw)/nGames<<endl;
    cout<<"Ratio of Longest to shortest game = 10^"<<log10(mxThrw)<<endl;

}

char rollDie(int sides){
    char die1=rand()%sides+1;//[1,number of sides]
    char die2=rand()%sides+1;//[1,number of sides]
    char sum1=die1+die2;
    return sum1;
}