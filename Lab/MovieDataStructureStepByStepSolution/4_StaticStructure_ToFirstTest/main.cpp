/* 
 * Author: Dr. Mark E. Lehr
 * Created on April 3rd, 2021, 11:40 AM
 * Purpose: Movie Data Structure
 *      Step by step Solution
 *      0 - Copy the Template
 *      1 - Read in 1 Set of Data and Verify
 *      2 - Read in N Sets of Data and Verify
 *      3 - Format the Results
 *      4 - Static Structure Array
 * Why? We need a dynamic structure.  Variable number of movies.  But let's
 * say I don't have that concept fully down yet.  Create a static structure
 * larger than we need and see if we can get that to work.
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, Setting seed, etc....
#include <iomanip>    //Formatting Library
using namespace std;  //Libraries compiled under std

//User Level Libraries/Includes here.  On Code-E we have to put
//structures and classes here before main but you would never do this
//for normal projects.  We would just include many .h files

//Note:  The ADT should start with a capital letter and be as close to
//7 characters in length as possible.  We went to the moon on <= 7 char
//length variable names.  Put the description, units, range, etc.... in
//comments not by representing things with long names.
const int SIZE=81;//Only way to size a static character array in a structure.
struct MovieInfo{
    string movName;        //Strings are good
    char dirName[SIZE];    //You need to know how to deal with character arrays
    unsigned short yrRlsd; //Don't need a larger data size and always > 0
    unsigned short runTime;//Don't need a larger data size and always > 0
};

//Global Constants Only - Science/Math Related, Conversions, Array and Higher
//Dimensions.  Put Global Variables anywhere in your program i.e. variables
//not contained in functions and I will give you an F!  Local variables
//only allowed.

//Function Prototypes here, Function implementations after main!

//Execution Begins Here!
int main(int argc, char** argv) {
    //Variable Declarations
    const int TOOBIG=10;//Anything to test
    MovieInfo mveInfo[TOOBIG];//Static Array of Structures
    int nMovies;//How many movies?
    
    //I copied the output from Code-E so I wouldn't make any typing mistakes
    //Then I just formatted.
    cout<<"This program reviews structures"<<endl;
    cout<<"Input how many movies, the Title of the Movie, Director, Year "<<
          "Released, and the Running Time in (minutes)."<<endl;
    cin>>nMovies;                //Integer Read
    
    //Now you can loop on the data as many times as it takes!
    for(int mvees=0;mvees<nMovies;mvees++){//Gotta frickin indent!!!!!
        cin.ignore();              //Oh Yea, Gotta do this for the buffer
        getline(cin,mveInfo[mvees].movName);//Movie Name In an Array Structure
        cin.getline(mveInfo[mvees].dirName,SIZE-1);//Array Structure element
        cin>>mveInfo[mvees].yrRlsd;//Look ma, no ignore after gets!!!!
        cin>>mveInfo[mvees].runTime;//Look again,no ignore after gets,only before

        //Mapping Process Inputs to Outputs

        //I copied the output from Code-E then applied formatting
        cout<<left<<endl;
        cout<<setw(11)<<"Title:"<<mveInfo[mvees].movName<<endl;
        cout<<setw(11)<<"Director:"<<mveInfo[mvees].dirName<<endl;
        cout<<setw(11)<<"Year:"<<mveInfo[mvees].yrRlsd<<endl;
        cout<<setw(11)<<"Length:"<<mveInfo[mvees].runTime<<endl;
    }
    
    //Clean Up

    //Exit stage right!
    return 0;
}