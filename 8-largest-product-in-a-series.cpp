//Problem 8 Project Euler
//Largest product in a series

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;

long product( deque <int> d) {
  long p = 1;

  for(auto it = d.begin() ; it != d.end() ; ++it) {
    p*= *it;
  }
  return p;
}

int main () {
  //Take input
  ifstream myFile;
  myFile.open ("8.txt");
  
  char digit;
  int adjacentDigits = 13;
  deque <int> d ;
  long prod = 1;
  //long numOfDigits = 0;
  
  for ( int i = 0 ; i < adjacentDigits ; ++i ) {
    myFile >> digit;
    int newDigit = digit - '0';
    d.push_back(newDigit);
    prod *= d[i];
  }
  long max =0;
  while ( myFile >> digit) {
    if(!isdigit(digit)) {
      continue;
    }
    
    if(*d.begin() == 0 ) {
      d.pop_front();
      d.push_back(digit - '0');
      prod = product( d );
    }
    else {
      prod /= d[0];
      d.pop_front();
      int newDigit = digit - '0';
      prod *= newDigit;
      d.push_back(newDigit);
    }
    if(prod > max) {
      max = prod;
    }
  }
  cout << max << endl;
  myFile.close();
  return 0;
}
