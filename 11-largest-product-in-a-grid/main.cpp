#include <iostream>
#include <vector>
#include <deque>
#include <fstream>
#include <sstream>

using namespace std;
int product( const deque<int> &d) {
    int p= 1;
    for (auto it = d.begin() ; it != d.end() ; ++it) {
        p*= *it;
    }
    return p;
}
int calculateHorizontal( const vector <vector<int>> &v , int n) {
    int prod = 1, max = -1, prod2 = 1;
    deque <int> dq , dq2;

    for ( int i = 0 ; i < v.size() ; ++i) {

        for ( int j = 0 ; j < n ; ++j) {
            dq.push_back(v[i][j]);
            dq2.push_back(v[j][i]);
        }
        prod = product(dq);
        prod2 = product(dq2);
        if ( prod > max) {
            max = prod;
        }
        if ( prod2 > max ) {
            max = prod2;
        }
        for(int j = n ; j < v[i].size() ; ++j) {
           dq.pop_front();
           dq.push_back(v[i][j]);
           prod = product(dq);

           dq2.pop_front();
           dq2.push_back(v[j][i]);
           prod2 = product ( dq2);

           if ( prod > max) {
               max = prod;
           }

           if( prod2 > max) {
               max = prod2;
           }

        }

        dq.clear();
        dq2.clear();
    }
    return max;
}
int calculateDiagonalDownRight ( const vector<vector<int>> &v , int n) {
    // Starting at 00 going down and then right ?
    int prod = 1, max = -1 , prod2 = 1;
    deque <int> dqDR, dqU;
    for ( int i = 0 ; i < v.size() ; ++i ) {
        for (int j = 0 ; j < v[i].size() ; ++j) {

            for ( int d = 0 ; (i+n-1) < v.size() && (j+n-1) < v[i].size() && d < n ; ++d ) {
                dqDR.push_back(v[i+d][j+d]); //will go out of bounds.
            }
            if(dqDR.size() < 4 ) {
                prod = 0;
            }
            else {
                prod = product ( dqDR);
            }
            if ( prod > max ) {
                max = prod;
            }
            dqDR.clear();

            for ( int dd = 0 ; (i-n+1)>= 0 && ( j+n-1) < v[i].size() && dd < n ; ++dd) {
                dqU.push_back(v[i-dd][j+dd]);
            }
            if(dqU.size() <4 ) {
                prod2 = 0;
            }
            else {
                prod2 = product (dqU);
            }
            if ( prod2 > max) {
                max = prod2;

            }
            dqU.clear();
        }

    }
    return max;
}

int main() {
    ifstream myFile;
    myFile.open("input");
    istringstream iss;
    string line ;
    vector <vector<int>> problemInput;
    while (getline ( myFile, line)) {
        iss.str(line);
        int temp ;
        vector <int> row;
        while ( iss >> temp) {
            row.push_back(temp);
            //cout << temp << " " ;
        }
        //cout << endl;
        problemInput.push_back(row);
        row.clear();
        iss.str("");
        iss.clear();
    }
    //cout << problemInput.size() << endl;
    cout << calculateHorizontal(problemInput , 4) << endl;
    cout << calculateDiagonalDownRight(problemInput , 4) << endl;
    cout << "The biggest number of the above " << endl;
    return 0;
}
