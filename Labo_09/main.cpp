/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_09_Date
 Fichier     : main.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 05.12.2018

 But         : Calculer le nombre de jours séparant 2 dates entrées par l'utilsateur.
               Les dates doivent être au format JJ-MM-AAAA.
               Les erreurs de saisie doivent être gérées.
               Le programme peut ensuite être recommencé ou stoppé.

 Remarque(s) : Les dates entrées doivent être incluses entre 01-01-1900 et 31-12-2200.
               Utilisation des libraires annexe et date.
               Les dates sont stockées dans un tableau d'entiers non-signés avec en
               position 0 le jour, en position 1 le mois et en position 2 l'année.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include "date.h"
#include "annexe.h"

using namespace std;

/**
 * Fonction permettant d'afficher le nombre de jours entre deux dates
 * @param nbJoursEntreDate entier non-signé contenant le nombre de jours entre dateDebut et dateFin
 * @param dateDebut tableau d'entiers non-signés contenant la date de début
 * @param dateFin tableau d'entiers non-signés contenant la date de fin
 */
void afficherResultat(unsigned nbJoursEntreDate, const unsigned dateDebut[], const unsigned dateFin[]);

int main() {
    const string MSG_SAISIE_DEBUT = "Veuillez saisir la date de debut entre le ",
                 MSG_SAISIE_FIN   = "Veuillez saisir la date de fin entre le ",
                 MSG_ERREUR       = "Saisie incorrecte, veuillez recommencer",
                 MSG_RECOMMENCER  = "Voulez-vous recommencer ?";
    
    const unsigned int ANNEE_MIN = 1800,
                       ANNEE_MAX = 2200;
    //Initialisation des tableaux qui contiendront le jour, mois, annee 
    //saisie par l'utilisateur
    unsigned dateDebut[3],
             dateFin[3];

    unsigned nbJoursEntreDate;

    cout << "Ce programme permet de calculer le nombre de jours entre deux dates saisies\n\n";

    do {
        //Demande de saisie des dates à l'utilisateur
        saisieDate(MSG_SAISIE_DEBUT, MSG_ERREUR, ANNEE_MIN, ANNEE_MAX, dateDebut);
        saisieDate(MSG_SAISIE_FIN, MSG_ERREUR, dateDebut, ANNEE_MAX, dateFin);
        //calcul de la différence de jour entre la date de début et de fin
        nbJoursEntreDate = nbJoursEntre(dateDebut, dateFin);

        afficherResultat(nbJoursEntreDate, dateDebut, dateFin);
    } while(repondsOui(MSG_RECOMMENCER, MSG_ERREUR)); //Demande à l'utilisateur s'il veut recommencer

    return EXIT_SUCCESS;
}

void afficherResultat(unsigned nbJoursEntreDate, const unsigned dateDebut[], const unsigned dateFin[]) {
    cout << "Il y a " << nbJoursEntreDate << " jour(s) entre le ";
    afficherDate(dateDebut);
    cout << " et le ";
    afficherDate(dateFin);
    cout << endl;
}