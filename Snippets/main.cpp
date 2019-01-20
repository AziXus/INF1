#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

using Vect = vector<int>;

//---------------------------------------------------------
int main() {

    vector<int> w = {1, 2, 3};

    w.insert(w.end(), w.rbegin() + 1, w.rend());

    for (auto j = w.begin(); j != w.end(); ++j) {
        cout << *j << " ";
    }
    cout << endl;
    for (int i: w) {
        cout << i << " ";
    }
    cout << endl;

    const int MARGE   =     17;
    const int STEP    =  10000;
    const int MAX     = 100000;
    Vect  v;

    cout  << "-----------------------------------------------------"  << endl
          << "RESIZE"                                                 << endl
          << setw(MARGE) << right << "INSTRUCT"
          << setw(MARGE) << right << "TAILLE"
          << setw(MARGE) << right << "CAPACITY"                       << endl
          << "-----------------------------------------------------"  << endl;

    v.resize(100);
    cout  << setw(MARGE) << left  << "v(100)"
          << setw(MARGE) << right << v.size()
          << setw(MARGE) << right << v.capacity()
          << endl;

    v.resize(10000);
    cout  << setw(MARGE) << left  << "v.resize(1000)"
          << setw(MARGE) << right << v.size()
          << setw(MARGE) << right << v.capacity()
          << endl;

    v.resize(10);
    cout  << setw(MARGE) << left  << "v.resize(10)"
          << setw(MARGE) << right << v.size()
          << setw(MARGE) << right << v.capacity()
          << endl;


    cout  << "-----------------------------------------------------"  << endl
          << "CAPACITY"                                               << endl
          << setw(MARGE) << right << "INSTRUCT"
          << setw(MARGE) << right << "TAILLE"
          << setw(MARGE) << right << "CAPACITY"                       << endl
          << "-----------------------------------------------------"  << endl;

    v.reserve(10);
    v.shrink_to_fit();
    cout  << setw(MARGE) << left  << "v.reserve(10)"
          << setw(MARGE) << right << v.size()
          << setw(MARGE) << right << v.capacity()
          << endl;

    v.reserve(1000);
    cout  << setw(MARGE) << left  << "v.reserve(1000)"
          << setw(MARGE) << right << v.size()
          << setw(MARGE) << right << v.capacity()
          << endl;

    v.reserve(10);
    cout  << setw(MARGE) << left  << "v.reserve(10)"
          << setw(MARGE) << right << v.size()
          << setw(MARGE) << right << v.capacity()
          << endl;

    v.resize(10);
    cout  << setw(MARGE) << left  << "v.resize(10)"
          << setw(MARGE) << right << v.size()
          << setw(MARGE) << right << v.capacity()
          << endl;

    v.shrink_to_fit();
    cout  << setw(MARGE) << left  << "v.shrink_to_fit()"
          << setw(MARGE) << right << v.size()
          << setw(MARGE) << right << v.capacity()
          << endl;


    cout  << "-----------------------------------------------------"  << endl
          << "AJOUT DE VAELURS"                                       << endl
          << setw(MARGE) << right << "VALEURS"
          << setw(MARGE) << right << "TAILLE"
          << setw(MARGE) << right << "CAPACITY"                       << endl
          << "-----------------------------------------------------"  << endl;

    for (int i=1; i<=MAX; ++i) {
        v.push_back(i);

        // affichage stats
        if (i % STEP == 0)
            cout  << setw(MARGE) << right << i
                  << setw(MARGE) << right << v.size()
                  << setw(MARGE) << right << v.capacity()
                  << endl;
    }


    cout  << "-----------------------------------------------------"  << endl
          << "SUPRESSION DE VAELURS"                                  << endl
          << setw(MARGE) << right << "VALEURS"
          << setw(MARGE) << right << "TAILLE"
          << setw(MARGE) << right << "CAPACITY"                       << endl
          << "-----------------------------------------------------"  << endl;

    for (int i=MAX; i>=0; --i) {
        // affichage stats
        if (i % STEP == 0)
            cout  << setw(MARGE) << right << i
                  << setw(MARGE) << right << v.size()
                  << setw(MARGE) << right << v.capacity()
                  << endl;

        v.pop_back();
    }

    return EXIT_SUCCESS;
}
