// swapping ostringstream objects
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
using namespace std;

bool isNum(string);

int main () {

  std::stringstream ss;
  string y;
  do{
    cout<<"Type in 2 integers or floats"<<endl;
    getline(cin,y);
  }while(!isNum(y));
  ss << y;
  float foo,bar;
  ss >> foo >> bar;

  std::cout << "foo: " << foo << '\n';
  std::cout << "bar: " << bar << '\n';

  return 0;
}

bool isNum(string x){
    for(int i=0;i<x.length();i++){
        if(!(((x[i]>='0')&&(x[i]<='9'))||x[i]==' '||x[i]=='.'))return false;
    }
    return true;
}