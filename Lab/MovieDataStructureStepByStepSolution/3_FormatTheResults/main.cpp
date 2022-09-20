/* 
 * Author: Dr. Mark E. Lehr
 * Created on April 3rd, 2021, 11:40 AM
 * Purpose: Movie Data Structure
 *      Step by step Solution
 *      0 - Copy the Template
 *      1 - Read in 1 Set of Data and Verify
 *      2 - Read in N Sets of Data and Verify
 *      3 - Format the Results
 * Why? We can solve the problem without structures.  This is the last step
 * in removing potential errors other than the new concepts that we need to
 * learn and apply.  The less amount of confusion will occur if we can
 * concentrate on the new concepts, but you have to get to that point.
 * OK, this works perfectly on Code-E!  But, it shows nothing in terms of
 * of understanding the structure concepts.
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, Setting seed, etc....
#include <iomanip>    //Formatting Library
using namespace std;  //Libraries compiled under std

//User Level Libraries/Includes here.  On Code-E we have to put
//structures and classes here before main but you would never do this
//for normal projects.  We would just include many .h files

//Global Constants Only - Science/Math Related, Conversions, Array and Higher
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
    
    //I copied the output from Code-E so I wouldn't make any typing mistakes
    //Then I just formatted.
    cout<<"This program reviews structures"<<endl;
    cout<<"Input how many movies, the Title of the Movie, Director, Year "<<
          "Released, and the Running Time in (minutes)."<<endl;
    cin>>nMovies;                //Integer Read
    
    //Now you can loop on the data as many times as it takes!
    for(int mvees=0;mvees<nMovies;mvees++){//Gotta frickin indent!!!!!
        cin.ignore();              //Oh Yea, Gotta do this for the buffer
        getline(cin,movName);      //Then I can read in strings with spaces
        cin.getline(dirName,SIZE-1);//Then I can read in chars with spaces
        cin>>yrRlsd;              //Look ma, no ignore after gets!!!!
        cin>>runTime;             //Look again,no ignore after gets,only before

        //Mapping Process Inputs to Outputs

        //I copied the output from Code-E then applied formatting
        cout<<left<<endl;
        cout<<setw(11)<<"Title:"<<movName<<endl;
        cout<<setw(11)<<"Director:"<<dirName<<endl;
        cout<<setw(11)<<"Year:"<<yrRlsd<<endl;
        cout<<setw(11)<<"Length:"<<runTime<<endl;
    }
    
    //Clean Up

    //Exit stage right!
    return 0;
}