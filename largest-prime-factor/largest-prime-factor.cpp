#include <iostream>

using namespace std;

bool isPrime (long long n) {
  for(long long d = 2 ; d <= n/2 ; ++d) {
    if(n % d  == 0) {
      return false;
    }
  }
  return true;
}

long long largestPrimeFactor ( long long n) {
  for ( long long d = 2 ; d <= n/2 ; ++d ) {
    if(n % d ==0 ) {
      long long q = n / d;
      if( isPrime(q)) {
	return q;
      }
    }
  }
  return -1;
}

int main () {
  long long number;
  //number= 13195;// test, prime factors 5, 7, 13, and 29. answer should be 29.
  number = 600851475143;
  //cin >> number;
  cout <<"The largest prime factor is of " << number << " is "  <<  largestPrimeFactor(number) <<endl;
  // cout << isPrime (2639) <<endl; //to debug. I had accidentally used the expression d % n instead of n % d. b/c maths lol

  return 0;
}
