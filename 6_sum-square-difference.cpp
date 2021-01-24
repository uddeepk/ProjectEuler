#include <iostream>
using namespace std;

int sumSquareDifference (int n) {
  int sum = 0 ,  sumOfSquares = 0;
  
  for ( int i = 1 ; i <= n ; i++ ) {
    sum += i;
    sumOfSquares += i*i;
  }

  int sumSquared = sum * sum;
  return (sumSquared - sumOfSquares) ;
}
int sumSquareDifference2 (int n) {
  int s = (n*(n+1)*(n-1)*(3*n+2))/12;
  return s;
}
int main () {
  int n;
  cin >> n ;
  cout << sumSquareDifference ( n ) << endl;
  cout << sumSquareDifference2 (n) <<endl;
  return 0;
}
