/* 
 * Author:   Dr. Mark E. Lehr
 * Date:     Created on September 18, 2023, 3:49 PM
 * Purpose:  What is the shortest Luhn Algorithm I could write
 * Validate: https://www.getcreditcardnumbers.com
 */
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
  char a[]="543561570634783 ";//Input the number with a buffer of 1 space
  //Start of my solution requires 3 Logical lines of code
  int one[]={0,1,2,3,4,5,6,7,8,9}, two[]={0,2,4,6,8,1,3,5,7,9},
      nine[]={'0','9','8','7','6','5','4','3','2','1'}, 
      sum=0, digit=sizeof(a)-3,even=true;//Initialization
  for(int i=digit; i>=0; even=!even, i--)
         sum += even ? two[a[i]-48] : one[a[i]-'0'];//Loop thru the digits
  a[++digit] = nine[sum%10];//Same thing as (9*sum)%10
  //End of my solution
  cout<<a<<endl;
  return 0;
}