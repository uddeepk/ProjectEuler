#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isPrime (long long n) {
  // if (n <= 1) return false;
  for(long long d = 2 ; d <= n/2 ; ++d) {
    if(n % d  == 0) {
      return false;
    }
  }
  return true;
}
// We can check if number is divisible by the prime numbers before it

bool isPrimeRevised ( long long n , vector < long long > &v) {
  //if ( n <=1 ) return false;
  for ( auto i =v.begin() ; i != v.end() && (*i * *i) <=n  ; i++ ) {// using *i * *i ) <= n is sketch, as I am depending upon how the && operator will act.
    if ( n % *i == 0 ) {
      return false;
    }
  }
  //if it goes through all numbers then is prime
  v.push_back(n);
  return true;
}

int main () {
  ofstream myFile;
  myFile.open("list-prime");
  int n = 0;
  long long i = 2;
  vector <long long > listPrimeNumbers;
  while ( n < 10001) {
    if(isPrimeRevised(i,listPrimeNumbers)) {
      n++;
    }
    i++;
  }
  cout <<"10001st prime number is " <<  *(listPrimeNumbers.end()-1) << endl;
  for ( auto j : listPrimeNumbers ) {
    myFile << j << '\n';
  }
  myFile.close();
  return 0;
}

