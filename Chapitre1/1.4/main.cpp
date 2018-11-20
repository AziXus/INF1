/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : <file>.cpp
 Auteur(s)   : Robin Müller
 Date        : jj.mm.yyyy

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    const int CURRENT_YEAR = 2018;

    string firstName;
    int age;
    int birthYear;

    cout << "Please enter your first name: " ;
    getline(cin, firstName);

    cout << "Please enter your age: ";
    cin >> age;
    getline(cin, firstName);
    birthYear = CURRENT_YEAR - age;

    cout << "Hello " << firstName << ",\n"
         << "You have " << age << " years and you were born in " << birthYear << "." << endl;

    system("pause");
    return EXIT_SUCCESS;
}