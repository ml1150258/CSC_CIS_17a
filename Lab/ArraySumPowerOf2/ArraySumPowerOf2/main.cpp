/* 
 * File:     main.cpp
 * Author:   Dr. Mark E. Lehr
 * Date:     Created on September 18, 2023, 7:01 PM
 * Purpose:  Shows 1 and 2 Dimensional Dynamic Arrays
 *           Solves how many Powers of 2 in a random array using all
 *           Combinations of Sums
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

unsigned int *fillAry(int);
unsigned int **split(unsigned int *,int,int&,int&);
void prntAry(unsigned int *,int,int);
void destroy(unsigned int *,unsigned int **);
bool pwrOf2(unsigned int,unsigned int);
unsigned int cntAll(unsigned int *,int);

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    
    int cEven,cOdd,size=10,perLine=5,count=0;
    unsigned int *array=fillAry(size);
    
    cout<<"The Original Array"<<endl;
    prntAry(array,size,perLine);
    
    unsigned int **spltAry=split(array,size,cEven,cOdd);
    
    cout<<"Split the above array into Even and Odd"<<endl;
    cout<<"Even Count = "<<cEven<<endl;
    cout<<"Odd Count  = "<<cOdd<<endl;
    
    cout<<endl<<"The Even Array";
    prntAry(spltAry[0],cEven,perLine);
    cout<<endl<<"The Odd Array";
    prntAry(spltAry[1],cOdd,perLine);
    
    count  = cntAll(spltAry[0],cEven);
    count += cntAll(spltAry[1],cOdd);
    
    cout<<endl<<"The total count = "<<count<<endl;
    
    destroy(array,spltAry);
    
    return 0;
}

unsigned int cntAll(unsigned int *a,int n){
    int count=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            count+=pwrOf2(a[i],a[j]);
        }
    }
    return count;
}

bool pwrOf2(unsigned int n1,unsigned int n2){
    unsigned int count = 0, n = n1 + n2;
    while (n) {
        count += n & 1;
        if(count>1) return false;
        n >>= 1;
    }
    return count;
}

void prntAry(unsigned int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void destroy(unsigned int *a,unsigned int **b){
    delete []a;
    delete []b[0];
    delete []b[1];
    delete []b;
}

unsigned int **split(unsigned int *a,int n,int &ce,int &co){
    unsigned int **b=new unsigned int*[2];
    b[0]=new unsigned int[n];
    b[1]=new unsigned int[n];
    ce=co=0;
    for(int i=0;i<n;i++){
        a[i]&1?b[1][co++]=a[i]:b[0][ce++]=a[i];
    }
    return b;
}

unsigned int *fillAry(int n){
    unsigned int *a=new unsigned int[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%3+7;
    }
    return a;
}