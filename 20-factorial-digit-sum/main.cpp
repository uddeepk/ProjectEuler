#include <iostream>
#include <vector>
using std::vector;

int m = 100000;
void multiply( vector <int> &v, int i) ;
int getSumOfDigits ( int);
int getSumOfDigits ( const vector <int> &v) ;
int main() {

    vector <int> v(1000);
    v[0] = 1;

    for ( int i = 100 ; i > 0 ; --i) {
        multiply(v, i);
    }
//    std::cout << getSumOfDigits(11141);
    std::cout << getSumOfDigits(v);
    return 0;
}
void multiply( vector <int> &v, int i){
    for ( auto &x : v) {
        x *= i;
    }
    int carryover = 0;
    for ( auto & x : v) {
        x += carryover;
        carryover = 0;
        if ( x >= m) {
            carryover = x / m;
            x %= m;
        }
    }
}
int getSumOfDigits ( int n ) {
    int sumOfDigits = 0;
    while ( n > 0) {
        sumOfDigits += n%10;
        n /= 10;
    }
    return sumOfDigits;
}

int getSumOfDigits ( const vector  <int> &v) {
    long sumOfDigits = 0;
    for ( auto x : v) {

        sumOfDigits += getSumOfDigits(x);
    }
    return sumOfDigits;
}