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

int main2();

int main() {
    main2();

    return EXIT_SUCCESS;
}

int main2() {
    const string MSG_SAISIE = "Veuillez saisir une date entre le ",
                 MSG_ERREUR = "Date invalide";
    unsigned jourDebut, moisDebut, anneeDebut,
             jourFin,   moisFin  , anneeFin;

    saisieDate(MSG_SAISIE, MSG_ERREUR, jourDebut, moisDebut, anneeDebut);
    saisieDate(MSG_SAISIE, MSG_ERREUR, jourDebut, moisDebut, anneeDebut, jourFin, moisFin, anneeFin);

    //internet formula
    cout << "Nb jours : " << nombreJourEntre(jourDebut, moisDebut, anneeDebut, jourFin, moisFin, anneeFin)  << endl;
    cout << "Nb jours (internet) : " << g(jourFin, moisFin, anneeFin) - g(jourDebut, moisDebut, anneeDebut) << endl;

    return EXIT_SUCCESS;
}


