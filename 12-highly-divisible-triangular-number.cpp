#include <iostream>
#include <vector>

using namespace std;

int dd = 2;
int numOfDivisors (const int &n, int d = 2, int divisors = 2);

int numOfDivisors ( const int &n, int d , int divisors ) {
  if( n==1) {
    return 1;
  }
  //vector <int> divisors = {1};
  if (d < n/d) {
    if( n % d == 0 ) {
      divisors += 2; //both d and n/d are divisors
    }
    return numOfDivisors( n , ++d , divisors);
  }

  if ( d == n/d ) {
    if( n % d == 0 ) {
      divisors++;
    }
  }
  
  
  return divisors;
   
}

int main() {
  //cout << numOfDivisors(10) << endl;
  int ds = 0;
  int n = 0;
  for( int i = 1 ; ds <= 500 ; ++i ) {
    n = n + i;
    ds = numOfDivisors(n);
  }
  cout << n << endl;
  return 0;
}
