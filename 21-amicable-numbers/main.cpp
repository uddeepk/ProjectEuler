#include <iostream>
#include <map>
#include <cmath>
using std::map;
#include <vector>
using std::vector;
#include <numeric>

int getSumOfProperDivisors ( int);
bool isAmicable(int i,  map <int, int> & m) ;
bool isEven ( int);

bool isEven(int n) {
    return (n%2) == 0;
}
int getSumOfProperDivisors(int i) {
    int sum = 1;
    for ( int divisor = 2 ; divisor <= floor((sqrt(i))) ; ++divisor) {
        if ( i % divisor == 0) {
            auto quotient = i / divisor;

                sum += quotient;

                sum += divisor;

            if ( divisor == quotient)
                sum -= divisor;
        }
    }
    return sum;
}
bool isAmicable( int i,  map<int, int> &m) {
    return m[m[i]] == i && m[i] != i;
}
using std::cout;
using std::endl;
int main() {

    map <int, int> sumOfProperDivisors ;
//    for( int i = 2 ; i < 10000 ; ++i) {
//        sumOfProperDivisors.insert( { i , getSumOfProperDivisors(i)});
//    }
//
//    vector <int> amicable;
//    for ( const auto &[i, j] : sumOfProperDivisors) {
//        if ( isAmicable(i, sumOfProperDivisors))
//            amicable.push_back(i);
//    }
//    int x = 0;
//
//    cout << std::accumulate(std::begin(amicable), std::end(amicable), x);
//
    //////////////////// Optimized way
    int sum = 0;
    for ( int i = 2 ; i < 10000 ; ++i) {
        auto j = getSumOfProperDivisors(i);
        if ( j > i ) {
            if (getSumOfProperDivisors(j) == i)
                sum += i + j;
        }
    }
    cout << sum;


    return 0;
}
