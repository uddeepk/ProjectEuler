#include <iostream>
#include <cmath>
#include <numbers>
#include <vector>
#include <algorithm>
#include <ranges>

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
    LargeInteger& operator+( const LargeInteger& rhs);

    void print() {
        std::vector <int> n (334, 0);
        std::ranges::reverse_copy(_number.begin(), _number.end(), n.begin());
        bool leadingZero = true;
        for ( auto const& x : n) {
            if (!leadingZero || x != 0 ) {
                std::cout << x;
                leadingZero = true;
            }
        }
    }

    std::string getValue () {
        std::string s;
        std::vector <int> n (334, 0);
        std::ranges::reverse_copy(_number.begin(), _number.end(), n.begin());
        bool leadingZero = true;
        for ( auto const& x : n) {
            if (!leadingZero || x != 0 ) {
                s += std::to_string(x);
                leadingZero = true;
            }
        }
        return s;
    }
};

using std::vector;
using std::string;
vector<int> bigNumber(string s) {
    // check for sign
    vector <int> v;
    while ( s.length() > 3) {
        string extracted = s.substr(0, 4);
        v.push_back(std::stoi(extracted));
        s.erase(0,4);
    }
    if ( !s.empty())
        v.push_back(std::stoi(s));

    return v;
}

int main() {
//    std::cout << std::pow(2, 1500) << std::endl;
    LargeInteger l1 ( "12345678901234567890");
    l1.print();
    std::cout << "\n" << l1.getValue();

    return 0;
}
