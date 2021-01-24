#include <iostream>
#include <vector>

using namespace std;
int  getAllProducts(vector <int> v) {
  int product = 1;
  for (auto i : v) {
    product *= i;
  }
  return product;
}
int smallestMultiple ( int n ) {
  vector <int> v = {1} ;
  for( int i = 2 ; i <= n ; ++i ) {
    int temp = i;
    for(auto j : v) {
      if(temp % j == 0 ) {
	temp = temp / j;
      }
    }
    if(temp != 1) {
      v.push_back(temp);
    }
  }
  return getAllProducts(v);
}

int main () {
  int userInput;
  cout << "Find the smallest multiple that can be divided by each numbers from 1 to n. Enter n : " ;
  cin >> userInput;
  //cout << endl;
  cout << smallestMultiple(userInput) <<endl;
  
  return 0;
}
