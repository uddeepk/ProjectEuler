#include <iostream>
//#include <cmath>
//#include <numbers>
#include <vector>
#include <algorithm>
#include <ranges>
#include <iomanip>
#include <sstream>

std::vector<int> bigNumber(std::string s) ;

struct LargeInteger {
    LargeInteger(int number) {
        _number = std::vector<int> (334, 0);
        auto n = bigNumber(std::to_string(number));
        std::reverse_copy(std::begin(n), std::end(n), std::begin(_number));
    }

    LargeInteger(const std::string &number) {
        _number = std::vector<int> (334, 0);
        auto n = bigNumber(number);
        std::reverse_copy(std::begin(n), std::end(n), std::begin(_number));
    }

    std::vector <int> _number ;
    LargeInteger& operator+=( const LargeInteger& rhs) {
        int carryover = 0;
        for ( int i = 0 ; i < 334 ; ++i) {
            _number[i] += rhs._number[i];
            int &n = _number[i];

            n += carryover;

            if( n >= 1000) {
                carryover = n / 1000;
                n %= 1000;
            }

        }
        return *this;
    }

    void print() {
        std::vector <int> n (334, 0);
        std::ranges::reverse_copy(_number.begin(), _number.end(), n.begin());
        bool leadingZero = true;
        for ( auto const& x : n) {
            if (!leadingZero || x != 0 ) {
                std::cout << std::setw(3) << std::setfill('0')<< x;
                leadingZero = false;
            }
        }
    }

    std::string getValue () {
        std::stringstream ss;
        std::string s;
        std::vector <int> n (334, 0);
        std::ranges::reverse_copy(_number.begin(), _number.end(), n.begin());
        bool leadingZero = true;
        for ( auto const& x : n) {
            if (!leadingZero || x != 0 ) {
                ss << std::setw(3) << std::setfill('0') << x;
                leadingZero = false;
            }
        }
        return ss.str();
    }
};
LargeInteger operator+ (const LargeInteger &lhs, const LargeInteger &rhs) {
    auto sum = lhs;
    sum += rhs;
    return sum;
}
using std::vector;
using std::string;
vector<int> bigNumber(string s) {
    // check for sign
    vector <int> v;
    while ( s.length() > 2) {
        string extracted = s.substr(0, 3);
//        std::cout << "*" << extracted << "*";
//        std::cout <<  extracted ;

        v.push_back(std::stoi(extracted));
        s.erase(0,3);
    }
    if ( !s.empty())
        v.push_back(std::stoi(s));

    return v;
}

int main() {
//    std::cout << std::pow(2, 1500) << std::endl;
    LargeInteger l(1);
    LargeInteger l1 ( "123456789000000001234567890");
    l1.print();
    std::cout << "\n" << l1.getValue() << "\n";
    auto l2 = l + l1;
    l2.print();
    std::cout << "\n";
    std::vector <LargeInteger> vec {1, 1};
    int n = 2;
    while (1) {;
        vec.push_back(vec[n-1] + vec[n-2]);
        ++n;
        if (vec.back()._number[1] != 0)
            break;
    }
    std::cout << n << " " << vec.back().getValue();
    return 0;
}
