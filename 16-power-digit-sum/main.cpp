#include <iostream>
#include <vector>
using std::vector;
using std::cout;

int sumOfDigits (int n) {
    int sum = 0;
    while ( n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main() {
    // Create a vector of ints to store the number in different sections
    vector <int> theNumber (500, 0);
    theNumber[0] = 1;
    int n = 1000;
    for ( int i = 0 ; i < n; ++i ) {
        // Multiply by 2, or left shift << 1
        for ( auto &partial : theNumber) {
            partial = partial << 1;
        }
        // Check if overflow. If yes then carry over overflow to higher index
        int carry = 0;
        for ( auto &partial : theNumber ) {
            partial += carry;
            if(partial >= 10000) {
                carry = partial / 10000;
                partial %= 10000;
            } else {
                carry = 0;
            }
        }
    }

    int answer = 0;

    for (const auto &n : theNumber) {
        answer += sumOfDigits(n);
    }
    cout << answer;
    return 0;
}
