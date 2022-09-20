/* 
 * Author: Dr. Mark E. Lehr
 * Created on April 3rd, 2021, 11:40 AM
 * Purpose: Movie Data Structure
 *      Step by step Solution
 *      0 - Copy the Template
 *      1 - Read in 1 Set of Data
 * Why? Many of you go off half-cocked in solving the problem instead of
 * making sure you can read the data and verify that it got read-in 
 * correctly.  If you can't get the data in correctly when you are
 * applying the new concept, you have no idea what is working and what isn't.
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, Setting seed, etc....
#include <iomanip>    //Formatting Library
using namespace std;  //Libraries compiled under std

//User Level Libraries/Includes here.  On Code-E we have to put
//structures and classes here before main but you would never do this
//for normal projects.  We would just include many .h files

//Global Constants Only - Science/Math Related, Conversions, Higher
//Dimensions.  Put Global Variables anywhere in your program i.e. variables
//not contained in functions and I will give you an F!  Local variables
//only allowed.

//Function Prototypes here, Function implementations after main!

//Execution Begins Here!
int main(int argc, char** argv) {
    //Variable Declarations
    int nMovies;       //Number of Movie structures I have to create!
    string movName;    //Movie Name
    const char SIZE=81;//Director Name Dimension Max
    char dirName[SIZE];//Director Name.  Why use a character array?
                       //Why not!  I should be able to use both, string/char[]
    int runTime,       //Runtime in minutes
            yrRlsd;    //Year Released AD
    
    //Variable Initialization
    cin>>nMovies;                //Integer Read
    cin.ignore();                //Oh Yea, Gotta do this for the buffer
    getline(cin,movName);        //Then I can read in strings with spaces
    cin.getline(dirName,SIZE-1); //Then I can read in chars with spaces
    cin>>runTime;                //Look ma, no ignore after gets!!!!
    cin>>yrRlsd;                 //Look again,no ignore after gets, only before

    //Mapping Process Inputs to Outputs

    //Display Outputs
    cout<<"Number of Movies:"<<nMovies<<endl;
    cout<<"Movie Name      :"<<movName<<endl;
    cout<<"Director Name   :"<<dirName<<endl;
    cout<<"Run Time        :"<<runTime<<endl;
    cout<<"Year Released   :"<<yrRlsd<<endl;
    
    //Clean Up

    //Exit stage right!
    return 0;
}