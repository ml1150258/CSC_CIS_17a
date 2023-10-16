/* 
 * Author: Dr. Mark E. Lehr
 * Created on September 18, 2023, 3:49 PM
 * Purpose: What is the shortest Luhn Algorithm I could write
 */
#include <iostream>
using namespace std;

void Luhn(char [],int);

int main(int argc, char** argv) {
  char a[]="510123020613838 ",b[]="37665356833818 ";
  Luhn(a,sizeof(a)-3);Luhn(b,sizeof(b)-3);
  cout<<"Credit Card 1 a = "<<a<<endl<<"Credit Card 2 b = "<<b<<endl;
  return 0;
}

void Luhn(char a[],int digit){
int two[]={0,2,4,6,8,1,3,5,7,9},sum=0,even=true,nine[]={'0','9','8','7','6','5','4','3','2','1'};
for(int i=digit; i>=0; even=!even,i--)sum += even ? two[a[i]-48]: a[i]-'0';
a[++digit] = nine[sum%10];}
