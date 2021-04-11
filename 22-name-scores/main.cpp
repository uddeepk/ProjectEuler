#include <iostream>
#include <regex>
#include <fstream>
#include <sstream>
#include <map>
using std::map;
#include <numeric>
#include <algorithm>

std::string getInput();
void getNameScoresMap (const std::string &s,  std::map <std::string, int> &m);
int getScore (const std::string &s);
int main() {

    std::string myInput = getInput();

    map <std::string, int> nameScores;
    getNameScoresMap(myInput, nameScores);
    int counter = 1;
    for ( auto &[f, s] : nameScores) {
        nameScores[f] = counter * s;
        ++counter;
    }

    std::cout << std::accumulate(std::begin(nameScores), std::end(nameScores), 0,
                     [] ( int value, const std::map < std::string, int>::value_type& p)
                     {return value + p.second;}
                      );
    return 0;
}
std::string getInput() {
    std::string readBuffer, retStr;
    std::ifstream myFile("names.txt");
    while (getline(myFile, readBuffer)) {
        retStr += readBuffer;
    }
    return retStr;
}

void getNameScoresMap (const std::string &s,  std::map <std::string, int> &m) {
    const std::regex nameRegex ("([A-Z]+)");
    std::smatch namesMatch {};
    std::vector<std::string> testV;
    for (std::sregex_iterator it = std::sregex_iterator(s.begin(), s.end(), nameRegex);
             it != std::sregex_iterator(); it++) {
        std::smatch namesMatch ;
        namesMatch = *it;
//        std::cout << namesMatch.str(1) << " ";
        std::string name = namesMatch.str(1);
        m.insert({name, getScore(name)});
    }

}
int getScore(const std::string &s) {
    int score = 0;
    for ( auto c : s ) {
        score += (c - 'A' + 1); // because a is 1
    }
    return score;
}