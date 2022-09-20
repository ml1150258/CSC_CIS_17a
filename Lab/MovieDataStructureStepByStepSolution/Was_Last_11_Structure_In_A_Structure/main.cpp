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
 *      5 - Change to a Dynamic Char Array inside Static Structure
 *      6 - Dynamic Structure
 *      7 - Fill Structure Function
 *      8 - Display Function for the Structure
 *      9 - Deallocate Memory in a Function
 *      10- Structure in a Structure. Minimize Dependencies
 * Why? Bad time to think of this, but let us combine the Size of the 
 * Structure and the Movie Info into a Structure containing the Array
 * Could have tested this out back around 6) without much potential damage
 * but we can give it a shot and if all else fails go back to 6) and
 * start this final process there.
 * 
 * Note:  This last step literally took me less than 2 minutes to modify
 * the functions.  This is what happens when you have checked out all the
 * previous steps.  Very little room left to make any errors.
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
//7 characters in length.  
//We will combine the Dynamic Structure with it's Size to minimize variables
//needed to be passed into functions, etc....
#include "Movies.h"

//Global Constants Only - Science/Math Related, Conversions, Array and Higher
//Dimensions.  Put Global Variables anywhere in your program i.e. variables
//not contained in functions and I will give you an F!  Local variables
//only allowed.

//Function Prototypes here, Function implementations after main!
Movies *fillDat();//Fill the Structure with Data
void display(Movies *);//Display the info in the Structure Array
void destroy(Movies *);//Deallocate Memory

//Execution Begins Here!
int main(int argc, char** argv) {
    //Variable Declarations
    Movies *movies;//Pointer to the dynamic Movie structure.
    
    //Initialize the Data Structure
    movies=fillDat();
    
    //Now you can loop on the data as many times as it takes!
    display(movies);
    
    //Clean Up the Dynamic Stuff
    destroy(movies);

    //Exit stage right!
    return 0;
}

void destroy(Movies *movies){
    //Clean Up the Dynamic Stuff
    for(int mvees=0;mvees<movies->nMovies;mvees++){
        delete [] movies->mveInfo[mvees].dirName;//The character arrays in the Stucture
    }
    delete [] movies->mveInfo;//Now the array of Structures
    delete movies;//Now deallocate the final Movie Structure
}

//Just copy, cut, and paste into a function.  Code already checked out in main.
void display(Movies *movies){
    //Now you can loop on the data as many times as it takes!
    for(int mvees=0;mvees<movies->nMovies;mvees++){
        //I copied the output from Code-E then applied formatting
        cout<<left<<endl;
        cout<<setw(11)<<"Title:"<<movies->mveInfo[mvees].movName<<endl;
        cout<<setw(11)<<"Director:"<<movies->mveInfo[mvees].dirName<<endl;
        cout<<setw(11)<<"Year:"<<movies->mveInfo[mvees].yrRlsd<<endl;
        cout<<setw(11)<<"Length:"<<movies->mveInfo[mvees].runTime<<endl;
    }
}

//This implementation of this function was thoroughly tested out already
//in main.
Movies *fillDat(){
    //Declare the Structure array
    Movies *movies=new Movies;
    //I copied the output from Code-E so I wouldn't make any typing mistakes
    //Then I just formatted.
    cout<<"This program reviews structures"<<endl;
    cout<<"Input how many movies, the Title of the Movie, Director, Year "<<
          "Released, and the Running Time in (minutes)."<<endl;
    cin>>movies->nMovies;                //Integer Read
    
    //Now you can allocate the array dynamically
    movies->mveInfo=new MovieInfo[movies->nMovies];

    //Now you can loop on the data as many times as it takes!
    for(int mvees=0;mvees<movies->nMovies;mvees++){//Gotta frickin indent!!!!!
        cin.ignore();              //Oh Yea, Gotta do this for the buffer
        getline(cin,movies->mveInfo[mvees].movName);//Movie Name In an Array Structure
        int size=81;//Make it Dynamic
        movies->mveInfo[mvees].dirName=new char[size];
        cin.getline(movies->mveInfo[mvees].dirName,size-1);//Array Structure element
        cin>>movies->mveInfo[mvees].yrRlsd;//Look ma, no ignore after gets!!!!
        cin>>movies->mveInfo[mvees].runTime;//Look again,no ignore after gets,only before
    }
    
    //Return what you filled
    return movies;
}