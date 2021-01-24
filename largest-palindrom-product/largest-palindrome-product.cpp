# include <iostream>
#include <set>

using namespace std;

bool isPalindrome ( int num ) {
  int rev = 0;
  int n = num;
  while ( n > 0) {
    rev =rev * 10 + n % 10;
    n = n /10;
  }
  return rev == num;
}
int getMaxLimit ( int n ) {
  int lim = 1;
  for ( int i = 0; i < n ; ++i) {
    lim *= 10;
  }
  return lim;
}
set <int> getProducts ( int numberOfDigits) {
  set <int> products ;
  if ( numberOfDigits < 0 ) {
    cerr << "Invalid number of Digits" <<endl;
  }
  else {
    int lim = getMaxLimit(numberOfDigits) ;

    for (int i = 1 ; i < lim ; ++i) {
      for (int j = i ; j < lim ; ++j) {
	products.insert(i*j);
      }
    }
    
  }
  return products;
}
int main () {
  //cout << isPalindrome (131) << endl;
  int d = 3 ; // for test digits 2 is 9009 (b/c = 91*99)
  int test = 0;
  set <int> products = getProducts (d);
  for (auto it = products.rbegin() ; it != products.rend(); ++it) {
    //test ++;
    //cout << *it << endl;
    if ( isPalindrome(*it)) {
      cout << "Largest Palindrome is " << *it << endl;
      break;
    }
  }
  //cout << test << endl;
  return 0;
}
