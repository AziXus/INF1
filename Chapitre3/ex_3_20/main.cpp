/*
 -----------------------------------------------------------------------------------
 Laboratoire :
 Fichier     : main.cpp
 Auteur(s)   : Robin Müller
 Date        : 10/28/18

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    const int START_NUMBER = 20;

    int width = (int)log(START_NUMBER);

    int nb = START_NUMBER;
    char separator;

    while (nb >= 1) {
        separator = nb % 3 == 0 ? '\n' : ' ';

        cout << setw(width) << nb << separator;
        nb--;
    }

    cout << endl;
    cout << endl;

    for (nb = START_NUMBER; nb >= 1; nb--) {
        separator = nb % 3 == 0 ? '\n' : ' ';

        cout << setw(width) << nb << separator;
    }

    cout << "\nPress ENTER to quit";
    cin.get();

    return EXIT_SUCCESS;
}