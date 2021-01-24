#include <iostream>

using namespace std;

void answer ( ) {
    for ( int i = 1 ; i < 1000 ; ++i ) {

        for ( int j = i+1 ; j < 1000 ; ++j) {
            if ( ( i* j ) > (500 * 1000) ) {
                break;
            }
            for (int k = j +1 ; k < 500 ; ++k) {
                if( ( i + j + k ) > 1000 ) {
                    break;

                }
                if ( (i*i + j*j) == (k*k) && i + j + k == 1000 ) {
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    answer();
    return 0;
}
