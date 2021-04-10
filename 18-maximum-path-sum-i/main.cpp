#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using std::vector;

vector <vector <int>> getVector ();
void print (const vector<vector<int>> &v);
int main()
{
    auto v = getVector();
//    print(v);

    for ( int row = v.size() - 2; row >= 0 ; --row) {
        for ( int col = 0; col < v[row].size() ; ++col) {
            auto leftLower = v[row + 1][col], rightLower = v[row + 1][col + 1];
            auto max = (leftLower > rightLower ? leftLower : rightLower);
            v[row][col] += max;
        }
    }

    std::cout << v[0][0];
    return 0;
}
vector <vector<int>> getVector ()
{
    vector <vector <int>> retVec;
    std::ifstream myFile("input");
    std::string readBuffer ;
    while ( getline(myFile, readBuffer)) {
        std::istringstream iss ( readBuffer);
        int n;
        vector <int> tempVec;
        while ( iss >> n ) {
            tempVec.push_back(n);
        }
        retVec.push_back(tempVec);
    }
    return retVec;
}
void print ( const vector<vector<int>> &v)
{
    for ( auto r : v) {
        for ( auto n : r ) {
            std::cout << n << " ";
        }
        std::cout << "\n";
    }
}