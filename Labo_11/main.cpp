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

using namespace std;

int main() {
    vector<vector<int>> v = {{1,2,4},{3,3,3},{3,5,5},{6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,}};
    int somme = 0;
    cout << v << endl;
    cout << maxCol(v) << endl;
    cout << sommeLignes(v) << endl;
    cout << vectSommeMin(v) << endl;
    shuffleMatrice(v);
    cout << v << endl;
    sortMatrice(v);
    cout << v << endl;
    bool matriceCarree;
    matriceCarree = sommeDiagDG(v,somme);
    cout << somme << endl;
    somme=0;
    matriceCarree = sommeDiagGD(v,somme);
    cout << somme << endl;
    return EXIT_SUCCESS;
}

