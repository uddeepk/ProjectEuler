#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isPrime (int n , vector <int> &p ) { //n needs to be positive according to definition of prime numbers
    //cout << n << endl;
    if (n == 1 ) {
        return false ; // 1 is not prime
    }
    else if ( n < 4 ) {
        p.push_back(n);
        return true; // because only other integers are 2, and 3 which are prime
    }
    else if ( n % 2 == 0 ) {
        return false; //even numbers cannot be prime
    }
    else if ( n % 3 == 0 ) { // because all numbers >3 can be written in the form 6k +-1
        return false;
    }
    else if ( n < 9 ) { // 4, and 6 are taken care of byp above conditions. The numbers left would be 5, and 7 both prime.
        p.push_back(n);
        return true;
    }
    else { // the numbers can only have one prime factor greater than sqrt(n) which would
        auto it = p.begin();
        int limit = floor(sqrt(n));
        //int f = 5;
         while ( it != p.end() && *it <= limit) {
            if ( n % *it == 0 ) {
                return false;
            }
            //f = f + 6;
            it++;
        }

    }
    //sum += n;
    p.push_back(n);
    return true;
}
//using recursion ?
long summation ( int n ) {
    return 0;
}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    vector <int> primes;
    long sum = 0;
    int i = 1;
    while ( i < 2000000) {
        if(isPrime(i , primes))
        {sum += i;
        //cout << i << endl;
        }
        //if(primes.size() == 2000000) {
          //  break;
        //}
        ++i;
    }
    cout << sum << endl;
    return 0;
}
