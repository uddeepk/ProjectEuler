/* 
   Uddeep Karki
   CS202
   Project Euler Problem 13 Large Sum
   
   Writing a program to workout the first ten digits of the sum of 100 50-digit numbers.

*/

/*
  Proposed Solution: Reading input from a file line at a time. Storing the numbers
  as a string. Then working for the sum from the last digit. 
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

using std::vector;
using std::getline;
using std::string;
using std::cerr; using std::cout; using std::endl;

string getSumOfNumbers ( const vector <string>& );

const char defaultFileName[] {"input.txt"} ;

int main(int argc, char **argv) {
  vector <string> fiftyDigitNumbers ;//Vector to store the numbers

  const char *fileName;
  
  std::ifstream myFile ;

  if (argc == 1) {
    fileName = defaultFileName ;
  }
  else if ( argc == 2 ) {
    fileName = argv[1];
  }
  else {
    cerr <<"Too many arguments! Please enter filename likes so : \n"
	 <<"$ large-sum inputfile.txt\n or to use default input file input.txt,"
	 <<" do not enter a filename argument." << endl;
  }
  
  myFile.open(fileName);

  if(myFile.fail()) { 
    //If file opening failed. This happens when no file is present.
    cerr << "input.txt not available. \n"
	 << "Place input.txt in the same locations as this file." << endl;
    return 1;
  }

  string temp;
  while (getline(myFile, temp)) {
    //Continues while input is good(or until it reaches eof)

    if(temp.empty()) //skips empty line
      continue;
    
    //Added regex to ensure input is correct
    std::regex re ("\\D");
    std::smatch m;
    
    if (std::regex_search( temp, m, re)) {
      cerr << "Invalid input. Non digit character present. Search for "
	   << m.str() << endl;
      return 1;
    }
      
    if (temp.length() != 50 ) {
      //terminate and display error
      cerr << "The numbers are not 50 digits long ! " << "look for \n" 
	   << temp << endl;
      return 1;
    }  
    //Push temp into vecNum
    fiftyDigitNumbers.push_back(temp);
  }
  
  if(fiftyDigitNumbers.empty()) {
    //if there is no data in the input file.
    cerr << "No data. Please check input file." << endl;
  }
 
  myFile.close();
  
  string sumOfNumbers = getSumOfNumbers (fiftyDigitNumbers);
  //cout << sumOfNumbers << endl;

  cout << sumOfNumbers.substr(0, 10) <<endl; //only display first 10 digits.
  
  return 0;
}

string getSumOfNumbers( const vector <string> &v ) {
  //Computes sum by getting  sum of rightmost digits and carrying to the left
  long long sumOfDigits = 0 ;  //This will store the sum of digits at the certain location
  string sum ;
  
  for ( int i = 0 ; i < 50 ; ++i)  {
    for (const auto &s : v) {
      sumOfDigits += ( s[49-i] - '0');
    }
    char tempDigit = ((sumOfDigits % 10) + '0'); //Extracting last digit
    sum = tempDigit + sum;
    sumOfDigits /= 10;
      
  }

  sum = std::to_string(sumOfDigits) + sum;

  return sum;
  
}
    
