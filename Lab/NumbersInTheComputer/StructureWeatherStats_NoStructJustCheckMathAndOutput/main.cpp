/*
 * Author:  Dr. Mark E. Lehr
 * Date:    April 4th, 2020
 * Purpose:  Just to check out the math, not to include the structure yet.
*/

//System Libraries
#include <iostream>//I/O Objects
#include <iomanip> //Format functions
using namespace std;

int main(){
    //Declare Variables
    const char NMONTHS=12;          //Number of Months
    float avgRain,avgTemp;         //Average Rain and rain for the month
    unsigned char high,low;         //High and Low Temp
    string hMonth,lMonth,month;     //Hign and Low Temp month with current Month
    unsigned short rain,lTemp,hTemp;//Monthly numbers for rain and high and low temp 
    
    //Read in the first set of Data
    cin>>hMonth>>avgRain>>lTemp>>hTemp;
    lMonth=hMonth;
    high=hTemp;
    low=lTemp;
    avgTemp=(lTemp+hTemp);
    
    //Read in the rest of the Data
    for(char mnth=2;mnth<=NMONTHS;mnth++){
        cin>>month>>rain>>lTemp>>hTemp;
        avgTemp+=(lTemp+hTemp);//Add the temp for each month
        avgRain+=rain; //Add the rain for each month
        //Find the lowest Temperature and month
        if(lTemp<low){
            low=lTemp;
            lMonth=month;
        }
        //Find the Highest Temperature and month
        if(hTemp>high){
            high=hTemp;
            hMonth=month;
        }
    }
    //Calculate the Average
    avgRain/=NMONTHS;    //12 Months
    avgTemp/=(2*NMONTHS);//24 Temps
    
    //Output the Results
    cout<<fixed<<setprecision(1);
    cout<<"Average Rainfall "<<avgRain<<" inches/month"<<endl;
    cout<<"Lowest  Temperature "<<lMonth<<"  "<<static_cast<unsigned int>(low)    <<" Degrees Fahrenheit"<<endl;
    cout<<"Highest Temperature "<<hMonth<<"  "<<static_cast<unsigned int>(high)   <<" Degrees Fahrenheit"<<endl;
    cout<<fixed<<setprecision(0);
    cout<<"Average Temperature for the year " <<avgTemp<<" Degrees Fahrenheit"<<endl;
    
    
	//your code here
	return 0;
}