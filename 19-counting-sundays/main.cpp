#include <iostream>
int getDaysOfMonth ( int, int);
int main() {
//    std::cout << "Hello, World!" << std::endl;
    int dayCount = 366; // Becauase 1900 is not a leap year
    int numberOfSundays = 0;
    for ( int year = 1901 ; year < 2001 ; ++year) {
        for ( int month = 0 ; month < 12 ; ++month) {
            if(dayCount % 7 == 0 )
                ++numberOfSundays;
            dayCount += getDaysOfMonth(month, year);
        }
    }
    std::cout << numberOfSundays;
    return 0;

}
int getDaysOfMonth (int month, int year) {
    ++month;
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                return 29;
            else
                return 28;
            break;

        default:
            return -1;
            break;
    }

}