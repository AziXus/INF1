#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <limits>

#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

/*
 * xxxx
 * xxx
 * xx
 * x
 */
void printTriangle_1(unsigned int n, char c = 'x');
void printTriangle_2(unsigned int n, char c = 'x');
void printTriangle_3R(unsigned int n, unsigned int w, char c = 'x');
void printTriangle_3(unsigned int n, char c = 'x');
void printTriangle_4(unsigned int n, char c = 'x');
void printTriangle_4R1(unsigned int n, unsigned int w, char c = 'x');
void printTriangle_4R2(unsigned int n, unsigned int w, char c = 'x');
void recursiveChar(unsigned int n, char c = 'x');

int main() {
    printTriangle_1(4);
    cout << endl;
    printTriangle_2(4);
    cout << endl;
    printTriangle_3(4);
    cout << endl;
    printTriangle_4(4);

    cout << "\nPress ENTER to quit\n";
    EMPTY_BUFFER;

    return EXIT_SUCCESS;
}

void recursiveChar(unsigned int n, char c) {
    if (n == 0)
        return;

    cout << c;
    recursiveChar(n - 1);
}

void printTriangle_1(unsigned int n, char c) {
    if (n == 0)
        return;

    cout << string(n, c) << endl;

    printTriangle_1(n - 1, c);
}

void printTriangle_2(unsigned int n, char c) {
    if (n > 0) {
        printTriangle_2(n - 1, c);
        cout << string(n, c) << endl;
    }
}

void printTriangle_3(unsigned int n, char c) {
    printTriangle_3R(n, n, c);
}

void printTriangle_3R(unsigned int n, unsigned int w, char c) {
    if (n > 0) {
        printTriangle_3R(n - 1, w, c);
        cout << setw(w) << string(n, c) << endl;
    }
}

void printTriangle_4(unsigned int n, char c) {
    printTriangle_4R1(n, n, c);
    printTriangle_4R2(n - 1, n, c);
}

void printTriangle_4R1(unsigned int n, unsigned int w, char c) {
    if (n > 0) {
        printTriangle_4R1(n - 1, w, c);
        cout << setw(w) << string(n, c) << endl;
    }
}

void printTriangle_4R2(unsigned int n, unsigned int w, char c) {
    if (n > 0) {
        cout << setw(w) << string(n, c) << endl;
        printTriangle_4R2(n - 1, w, c);
    }

}
