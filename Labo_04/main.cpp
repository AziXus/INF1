/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_04
 Fichier     : main.cpp
 Auteur(s)   : Robin Müller
 Date        : 15.10.2018

 But         : Calculer le nombre de jours pour un mois et une année spécifiée par l'utilisateur.

 Remarque(s) : Le mois doit être une valeur entre 1 et 12 alors et l'année entre 1900 et 2100.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    const int MIN_YEAR          =  1900,
              MAX_YEAR          =  2100,
              DAYS_IN_FEBRUARY  =    28,
              DAYS_IN_MONTH     =    31;

    enum MONTH {
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    };

    //Print introduction
    cout << "This program will calculate the number of days in a month based on your selection.\n\n";

    //Read inputs
    int month, year;
    cout << "Elements selection\n";

    //Read and test month value
    cout << "- Month      " << "[" << MONTH::January << "-" << MONTH::December << "]: ";
    cin  >> month;
    //If out of range, error and exit
    if (month < MONTH::January || month > MONTH::December) {
        cout << month << " is an invalid month. Please select a value between " << MONTH::January
                      << " and " << MONTH::December << ".\n";

        cout << "\nPress ENTER to quit\n";
        cin.ignore();
        cin.get();

        return EXIT_FAILURE;
    }

    //Read and test year value
    cout <<  "- Year  " << "[" << MIN_YEAR  << "-" << MAX_YEAR  << "]: ";
    cin  >> year;
    //If out of range, error and exit
    if (year < MIN_YEAR or year > MAX_YEAR) {
        cout << year << " is an invalid year. Please select a value between " << MIN_YEAR
                     << " and " << MAX_YEAR << ".\n";

        cout << "\nPress ENTER to quit\n";
        cin.ignore();
        cin.get();

        return EXIT_FAILURE;
    }

    //Calculate the number of days for the selected month
    int daysInMonth;
    if (month == MONTH::February) {
        //Two possibilities for a leap year:
        //Year divisible by 400 or year divisible by 4 but not by 100
        bool isLeapYear = year % 400 == 0 or (year % 4 == 0 and year % 100 != 0);

        daysInMonth = DAYS_IN_FEBRUARY + isLeapYear;
    } else {
        //If (months  1-7) - 1 are odd, they have 30 days
        //If (months 8-12) - 1 are even, they have 30 days
        //%2 is used to test for parity
        //%7 is used to reset the months number (8-12 => 1-7)
        //
        //For August:    31 - (8 - 1) % 7 % 2 => 31 - 0 => 31 days
        //For September: 31 - (9 - 1) % 7 % 2 => 31 - 1 => 30 days
        daysInMonth = DAYS_IN_MONTH - (month - 1) % 7 % 2;
    }

    //Get month name in english
    string monthName;
    switch(month) {
        case MONTH::January  : monthName = "January";   break;
        case MONTH::February : monthName = "February";  break;
        case MONTH::March    : monthName = "March";     break;
        case MONTH::April    : monthName = "April";     break;
        case MONTH::May      : monthName = "May";       break;
        case MONTH::June     : monthName = "June";      break;
        case MONTH::July     : monthName = "July";      break;
        case MONTH::August   : monthName = "August";    break;
        case MONTH::September: monthName = "September"; break;
        case MONTH::October  : monthName = "October";   break;
        case MONTH::November : monthName = "November";  break;
        case MONTH::December : monthName = "December";  break;
        default              : monthName = "n/a";
    }

    cout << "\nThere are " << daysInMonth << " days in " << monthName << " " << year << endl;

    cout << "\nPress ENTER to quit\n";
    cin.ignore();
    cin.get();

    return EXIT_SUCCESS;
}
//Program output:
//This program will calculate the number of days in a month based on your selection.
//
//Elements selection
//- Month        [1-12]: 1
//- Year    [1900-2100]: 1900
//
//There are 31 days in January 1900
//
//Press ENTER to quit