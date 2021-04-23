#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using std::vector;
using std::cout;
vector <int> findDivisors (int n) ;
bool isAbundant (int n);
vector <int> getAbundantNumbers(int n);
vector <int> getAllPossibleSums( const vector<int> &v);

int main() {
    auto vecAbundantNumbers = getAbundantNumbers(28123);
    int sum = 0;
    auto sums = getAllPossibleSums(vecAbundantNumbers);
    for ( int i = 1 ; i <= 28123 ; ++i) {
        if( !std::binary_search(std::begin(sums), std::end(sums), i) )
            sum += i;
    }
    cout << sum;
}

vector<int> findDivisors(int n) {
    vector<int> divisors ;
    for(int i = 2 ; i * i <= n ; ++i ) {
//        int quotient = n / i ;
        if ( n % i == 0 ) {
            divisors.push_back(i);
            int quotient = n / i;
            if ( quotient != i )
                divisors.push_back(quotient);
        }
    }

    return divisors;
}

bool isAbundant(int n) {
    auto divisors = findDivisors(n);
    auto sumOfDivisors = std::accumulate(std::begin (divisors), std::end(divisors), 1);
//    std::cout << sumOfDivisors << "\n" ;
    return (sumOfDivisors > n);
}

vector<int> getAbundantNumbers(int n) {
    vector <int> abundantNumbers;
    for ( int i = 1 ; i <= n ; ++i) {
        if (isAbundant(i))
            abundantNumbers.push_back(i);
    }
    return abundantNumbers;
}

vector<int> getAllPossibleSums(const vector<int> &v) {
    vector <int> twoNumberSums;
    for ( auto it = v.begin() ; it != v.end() ; ++it) {
        twoNumberSums.push_back(*it * 2l);
        for ( auto it2 = it + 1 ; it2 != v.end() ; ++it2) {
            twoNumberSums.push_back(*it + *it2);
        }
    }
    std::sort(std::begin(twoNumberSums), std::end(twoNumberSums));
    auto last = std::unique(std::begin(twoNumberSums), std::end(twoNumberSums));
    twoNumberSums.erase(last, twoNumberSums.end());
    return twoNumberSums;
}
