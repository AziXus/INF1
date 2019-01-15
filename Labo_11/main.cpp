/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : <nom du fichier>.cpp
 Auteur(s)   : <prénom> <nom>
 Date        : <jj.mm.aaaa>

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
 */
#include "vecteur.h"
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> v = {{1,2,4},{3,3,3,3},{3,5},{1,1}};
    cout << v << endl;
    cout << maxCol(v) << endl;
    cout << sommeLignes(v) << endl;
    cout << vectSommeMin(v) << endl;
    shuffleMatrice(v);
    cout << v << endl;
    sortMatrice(v);
    cout << v << endl;
    return EXIT_SUCCESS;
}

