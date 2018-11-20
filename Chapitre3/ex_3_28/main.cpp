/*
 -----------------------------------------------------------------------------------
 Labo       :
 File       : main.cpp
 Author(s)  : Robin Müller
 Date       : 31.10.18

 Purpose    : <to complete>

 Comment(s) : <to completer>

 Compiler : g++ 8.2.1
 -----------------------------------------------------------------------------------
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>

#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

int main() {
    const int DECIMAL_PRECISION = 5;

    int nbValues;
    double harmonicSeries = 0.0;

    bool validInput;

    //Read nbValues until valid
    do {
        cout << "How many values would you like ? ";
        validInput = cin >> nbValues and nbValues > 0;

        if (!validInput) {
            cin.clear();
            cout << "Error. The value must be > 0" << endl;
        }

        EMPTY_BUFFER;
    } while (!validInput);

    for (int n = 1; n <= nbValues; ++n) {
        harmonicSeries += 1.0/n;
    }

    cout << setprecision(DECIMAL_PRECISION);
    cout << "The sum of the first " << nbValues << " values of the harmonic series is " << harmonicSeries << endl;

    cout << "\nPress ENTER to quit\n";
    cin.get();

    return EXIT_SUCCESS;
}