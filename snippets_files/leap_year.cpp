#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool isLeapYear(int year) {
    return year % 400 == 0 or (year % 4 == 0 and year % 100 != 0);
}

int main() {
    cout << boolalpha
         << "Is 1900 a leap year: " << isLeapYear(1900) << endl
         << "Is 2000 a leap year: " << isLeapYear(2000) << endl
         << "Is 2010 a leap year: " << isLeapYear(2010) << endl
         << "Is 2010 a leap year: " << isLeapYear(2020) << endl;

    return EXIT_SUCCESS;
}