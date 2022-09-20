/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 11th, 2019, 12:36 PM
 * Purpose:  LCD Display
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Formatting Library
#include <fstream>  //File Stream Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
char ***LCDfill(fstream &,int,int,int);//Fill the LCD Array
void prntOne(char ***,int,int,int,int);//Print one digit
void prntAll(char ***,int,int,int);    //Print all digits
void destroy(char ***,int,int);        //Destroy the LCD Array

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char cols, rows, digits, ***LCD;
    fstream in;
    
    //Initialize or input i.e. set variable values
    digits=10,rows=3,cols=4;
    char fn[]="digits.dat";
    in.open(fn);
    LCD=LCDfill(in,digits,rows,cols);
    
    //Display the outputs
    cout<<"Print in a Column!"<<endl;
    for(int num=0;num<10;num++){
        prntOne(LCD,digits,rows,cols,num);
    }
    cout<<"Print all in a row!"<<endl;
    prntAll(LCD,digits,rows,cols);

    //Exit stage right or left!
    destroy(LCD,digits,rows);
    in.close();
    return 0;
}

void destroy(char ***nums,int digits,int rows){
    //First the columns
    for(int digit=0;digit<digits;digit++){
        for(int row=0;row<rows;row++){
            delete []nums[digit][row];
        }
    }
    //Then the Rows
    for(int digit=0;digit<digits;digit++){
        delete []nums[digit];
    }
    //Now the Digit Array
    delete []nums;
}

void prntAll(char ***nums,int digits,int rows,int cols){
    //Create the Display array
    //All you need is a 2-D array for this one.
    char **disp=new char *[rows];
    int colDsp=digits*(cols-1)+1;
    for(int row=0;row<rows;row++){
        disp[row]=new char[colDsp];
    }
    
    //Copy the numbers you want into the display
    for(int digit=0;digit<digits;digit++){
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols-1;col++){
                disp[row][digit*(cols-1)+col]=nums[digit][row][col];
            }
        }
    }
    
    //Remember, you just need to cout by row;
    for(int row=0;row<rows;row++){
        cout<<disp[row]<<endl;
    }
    
    //When done displaying, clean up the array you copied to
    for(int row=0;row<rows;row++){
        delete []disp[row];
    }
    delete []disp;
}

void prntOne(char ***nums,int digits,int rows,int cols,int number){
    //Print the number you want to display
    for(int row=0;row<rows;row++){
        cout<<nums[number][row]<<endl;
    }
}

char ***LCDfill(fstream &in,int digits,int rows,int cols){
    //Allocate the 3 dimensional array
    char ***nums=new char **[digits];
    for(int digit=0;digit<digits;digit++){
        nums[digit]=new char *[rows];
        for(int row=0;row<rows;row++){
            nums[digit][row]=new char[cols];
        }
    }
    
    //Fill the array from a file.
    for(int digit=0;digit<digits;digit++){
        for(int row=0;row<rows;row++){
            in.getline(nums[digit][row],cols+1);
        }
    }
    
    //Return the array
    return nums;
}