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

void printTriangle1(unsigned n, char c = 'x');
void printTriangle2(unsigned n, char c = 'x');
void printTriangle3(unsigned n, char c = 'x');
void printTriangle3R(unsigned n, char c, int w);
void printTriangle4R(unsigned n, char c, int w);
void printTriangle4(unsigned n, char c = 'x');
bool isDigit(const string& val);
string substring(const string& chaine, int position, int longueur);

int main() {
    cout << "Saisie : ";
    string valeurSaisie, jour, mois, annee;

    getline(cin, valeurSaisie);

    jour  = substring(valeurSaisie, 0, 2);
    mois  = substring(valeurSaisie, 3, 2);
    annee = substring(valeurSaisie, 6, 4);

    cout << jour << "-" << mois << "-" << annee << endl;
    cout << "Date valide : " << boolalpha << (isDigit(jour) and isDigit(mois) and isDigit(annee)) << endl;

    cout << "\nPress ENTER to quit\n";
    EMPTY_BUFFER;

    return EXIT_SUCCESS;
}

void printTriangle1(unsigned n, char c) {
    if (n > 0) {
        cout << string(n, c) << endl;
        printTriangle1(n - 1, c);
    }
}

void printTriangle2(unsigned n, char c) {
    if (n > 0) {
        printTriangle2(n - 1, c);
        cout << string(n, c) << endl;
    }
}

void printTriangle3(unsigned n, char c) {
    printTriangle3R(n, c, 0);
}

void printTriangle3R(unsigned n, char c, signed w) {
    if (n > 0) {
        printTriangle3R(n - 1, c, w + 1);
        cout << string(w, ' ') << string(n, c) << endl;
    }
}

void printTriangle4(unsigned n, char c) {
    printTriangle3R(n, c, 0);
    printTriangle4R(n - 1, c, 1);
}


void printTriangle4R(unsigned n, char c, signed w) {
    if (n > 0) {
        cout << string(w, ' ') << string(n, c) << endl;
        printTriangle4R(n - 1, c, w + 1);
    }
}

bool isDigit(const string& val) {
    const int NOMBRE_ASCII = 48;

    for (char c: val) {
        if (c < NOMBRE_ASCII or c > NOMBRE_ASCII + 9)
            return false;
    }

    return true;
}

std::string substring(const std::string& chaineCaractere, int position, int longueur) {
    string nouvelleChaine;

    for (int i = position; i < position + longueur; ++i) {
        nouvelleChaine += chaineCaractere[i];
    }

    return nouvelleChaine;
}