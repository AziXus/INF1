#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <limits>

#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

void afficher() {
    static int nbAppels = 1;
    cout << "Appel numero " << nbAppels << endl;
    ++nbAppels;
}

int main() {
    afficher();
    afficher();
    afficher();

    cout << "\nPress ENTER to quit\n";
    EMPTY_BUFFER;
}