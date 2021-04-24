#include <iostream>
#include <algorithm>

int main() {
    std::string str {"0123456789"};
    for ( int i = 0 ; i < 1000000 - 1 ; ++i ) {
        std::next_permutation(std::begin(str), std::end(str));
    }
    std::cout << str;
    return 0;
}
