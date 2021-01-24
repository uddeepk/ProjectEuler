#include <iostream>
using namespace std;
int fibEven(int a, int b) {
    int newFib = a + b;
    if(newFib > 4000000) {
        return 0;
    }

        return (newFib % 2==0 ? newFib : 0) + fibEven( b, newFib);
}
int main() {
    //where fibionacci number doesn't exceed 4 million or 4,000,000. thus an int should be fine
    //we need to find the sum of the even-valued term.
    cout << fibEven( 0 , 1) << endl;
    return 0;
}
