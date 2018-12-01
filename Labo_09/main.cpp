/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_09_Date
 Fichier     : main.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.11.2018

 But         : Générer des questions pour tester les réflexes clavier de l'utilisateur.
               Les questions sont des lettres de a à z qui devront être saisies.
               L'utilisateur choisi le nombre de lancés entre 1 et 10.
               Le nombre de réponses correctes et le temps effectué
               pour terminer le questionnaire est donné en fin de programme.
               Le programme peut ensuite être recommencé ou stoppé.

 Remarque(s) : Utilisation de la fonction ctime pour mesurer le temps pris pour résoudre le questionnaire.
               Le nombre de lancés doit être compris entre 1 et 10.
               Utilisation des libraires annexe et reflex.              

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
0 */

#include <cstdlib>
#include <iostream>
#include "date.h"

using namespace std;


int g(int d, int m, int y) {
    m = (m + 9) % 12;
    y = y - m / 10;

    return 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (d - 1);
}

int main() {
    //saisieDate("Saisie : ", "Erreur", 1900, 2200);
    //saisieDate("Saisie : ", "Erreur", 1900, 2200);

    unsigned jourDebut =     1,
             moisDebut  =   11,
             anneeDebut = 2018,
             jourFin   =     1,
             moisFin    =   12,
             anneeFin   = 2018;

    //internet formula
    cout << "Nb jours : " << nombreJourEntre(jourDebut, moisDebut, anneeDebut, jourFin, moisFin, anneeFin)  << endl;
    cout << "Nb jours (internet) : " << g(jourFin, moisFin, anneeFin) - g(jourDebut, moisDebut, anneeDebut) << endl;

    return EXIT_SUCCESS;
}


