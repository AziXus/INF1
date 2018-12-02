/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_09_Date
 Fichier     : main.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 05.12.2018

 But         : Calucler le nombre de jorus séparant 2 dates entrées par l'utilsateur.
               Les dates doivent être au format JJ-MM-AAAA.
               L'erreur de saisie doit être gérée.
               Le programme peut ensuite être recommencé ou stoppé.

 Remarque(s) : Les dates entrées doivent être incluses entre 01-01-1900 et 31-12-2200.
               Utilisation des libraires annexe et date.              

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "date.h"
#include "annexe.h"

using namespace std;

int g(int d, int m, int y) {
    m = (m + 9) % 12;
    y = y - m / 10;

    return 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (d - 1);
}

int main2();

int main() {
    const string MSG_SAISIE      = "Veuillez saisir une date entre le ",
                 MSG_ERREUR      = "Saisie incorrecte veuillez recommencer",
                 MSG_RECOMMENCER = "Voulez-vous recommencer ?";
    
    const unsigned int ANNEE_MIN = 1900,
                       ANNEE_MAX = 2200;
    do{
        //Demande de saisie des dates à l'utilisateur
        SaisieDate(MSG_SAISIE, MSG_ERREUR, ANNEE_MIN, ANNEE_MAX);
        SaisieDate(MSG_SAISIE, MSG_ERREUR, ANNEE_MIN, ANNEE_MAX);
        //affichage du nombre de jour séparant les 2 dates rentrées
        cout << nombreJourEntre() << endl;
    }while(!repondsOui(MSG_RECOMMENCER, MSG_ERREUR));

    return EXIT_SUCCESS;
}

int main2() {
    const string MSG_SAISIE_DEBUT = "Veuillez saisir la date de debut entre le ",
                 MSG_SAISIE_FIN   = "Veuillez saisir la date de fin   entre le ",
                 MSG_ERREUR       = "Date invalide";
    unsigned jourDebut, moisDebut, anneeDebut,
             jourFin,   moisFin  , anneeFin;

    saisieDate(MSG_SAISIE_DEBUT, MSG_ERREUR, jourDebut, moisDebut, anneeDebut);
    saisieDate(MSG_SAISIE_FIN,   MSG_ERREUR, jourDebut, moisDebut, anneeDebut, jourFin, moisFin, anneeFin);

    cout << "Nb jours            : " << nbJoursEntre(jourDebut, moisDebut, anneeDebut, jourFin, moisFin, anneeFin)  << endl;
    //internet formula
    cout << "Nb jours (internet) : " << g(jourFin, moisFin, anneeFin) - g(jourDebut, moisDebut, anneeDebut) << endl;

    return EXIT_SUCCESS;
}


