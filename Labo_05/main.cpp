#include <cstdlib> // EXIT_SUCCESS
#include <cstdio> // cin.get()
#include <iostream> // cout et cin
#include <limits>
#include <string>

using namespace std;

int main() {
    int a, b, c; // variables de travail
    string out;

    // définir et justifier ce que vaut le buffer
    // après chacune des instructions ci-dessous
    cout << "entrer des valeurs";
    //Buffer: empty
    while(cin.get() != '\n');
    //Buffer: empty (wait for input then as buffer is not empty return char till \n)
    cout << endl;
    //Buffer: still empty
    cin >> a;
    //Buffer: _1_94\n
    cout << "\n";
    //Buffer: _1_94\n
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //Buffer: empty
    cin >> b;
    //Buffer: _3.45_Pi
    cout << endl;
    //Buffer _3.45_Pi
    cin >> c;
    //Buffer .45_Pi

    // fin de programme
    cout << "Presser ENTER pour quitter";
    getchar();

    return EXIT_SUCCESS;
}