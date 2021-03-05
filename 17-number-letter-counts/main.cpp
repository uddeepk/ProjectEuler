#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;

string numbersInWords (int n ) {
    string word ;
    vector <string> words { "", "one", "two", "three", "four" , "five", "six" ,"seven" , "eight", "nine", "ten",
                            "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                            "eighteen", "nineteen" };
    vector <string> tens {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    int myTens = n % 100;

    if(myTens < 20) {
        word += words[myTens];
    } else {
        word += tens[myTens/10];
        word += words[myTens%10];
    }
    n /= 100;
    if(n > 0 ) {
        word = words[n] + "hundred" + (word.empty()? "" : "and") + word;
    }
    n /= 10;
    if (n > 0 ) {
        word = words[n] + "thousand";
    }
    return word;
}
int main() {
//    vector <string> vecNumbersInWords;
    int numberOfLetters = 0;
    for (int i = 1 ; i <= 1000 ; ++i) {
        string tempBuffer = numbersInWords(i);
        std::cout<< tempBuffer << "\n";
        numberOfLetters += tempBuffer.length();
    }
    std::cout << numberOfLetters;
    return 0;
}
