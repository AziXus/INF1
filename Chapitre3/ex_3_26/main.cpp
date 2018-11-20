/*
 -----------------------------------------------------------------------------------
 Labo       :
 File       : main.cpp
 Author(s)  : Robin Müller
 Date       : 31.10.18

 Purpose    : <to complete>

 Comment(s) : <to completer>

 Compiler   : g++ 8.2.1
 -----------------------------------------------------------------------------------
 */

#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>

#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

int main() {
    const int  MIN_HEIGHT = 0;
    const char SEPARATOR = ' ',
               CHARACTER = '*';

    int triangleHeight;
    bool validInput;

    //Read triangle's height until valid
    do {
        cout << "Triangle's height (h >= " << MIN_HEIGHT << "): ";
        validInput = cin >> triangleHeight and triangleHeight > MIN_HEIGHT;

        if (!validInput) {
            cin.clear();
            cout << "Height must be >= " << MIN_HEIGHT << endl;
        }

        EMPTY_BUFFER;
    } while (!validInput);

    //Print triangle
    for (int line = 1; line <= triangleHeight; ++line) {
        cout << string(triangleHeight - line, SEPARATOR);
        cout << string(line * 2 - 1, CHARACTER);

        /*2 loops
         * //print separator
        for (int space = 1; space <= triangleHeight - line; ++space) {
            cout << SEPARATOR;
        }

        //print stars
        for (int star = 1; star < line * 2; ++star) {
            cout << CHARACTER;
        }*/

        cout << endl;
    }

    return EXIT_SUCCESS;
}
