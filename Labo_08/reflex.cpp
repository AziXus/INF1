/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : reflex.cpp
 Auteur(s)   : Robin Müller
 Date        : 19.11.2018

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include "reflex.h"
#include "annexe.h"
#include "chrono.h"
#include <iostream>

using namespace std;

/**
 * Demande à l'utilisateur d'entrer un caractère.
 * @param caractere Le caractère à demander lors de la saisie.
 * @return          Le caractère saisie par l'utilisateur.
 */
char saisieLettre(const char& caractere) {
    char lettreEntree;

    cout << "lettre : " << caractere << " : ";

    cin >> lettreEntree;
    viderBuffer();

    return lettreEntree;
}

int testerReflex(int nbLettre, const char& lettreMin, const char& lettreMax, int& nbSecondes) {
    char lettreEntree,
         lettreAttendue;

    int nbLettresCorrectes = 0;

    demarrerChrono();
    //Génère des lettre aléatoire et compte le nombre de lettres correctement saisie jusqu'à nbLettre
    for (int i = 0; i < nbLettre; ++i) {
        lettreAttendue = (char)(nombreAleatoire(lettreMin, lettreMax));
        
        lettreEntree = saisieLettre(lettreAttendue);
        
        //Incrémente le nombre de lettre correctes si la saisie est correcte
        if (lettreEntree == lettreAttendue)
            ++nbLettresCorrectes;
    }

    //arreterChrono() retourne le nombre de secondes depuis son démarrage
    nbSecondes = arreterChrono();
    
    return nbLettresCorrectes;
}