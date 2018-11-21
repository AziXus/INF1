/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08_Clavier
 Fichier     : reflex.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.11.2018

 But         : Générer des questions pour tester les réflexes clavier de l'utilisateur.
               Les questions sont des lettres, situées dans une borne, qui devront être saisies.
               Vérifie si l'utilisateur a répondu correctement(calcul du score) et calcul le temps.

 Remarque(s) : Utilisation des libraires annexe et chrono.

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
 * @return Le caractère saisie par l'utilisateur.
 */
char saisieLettre(const char caractere) {
    char lettreEntree;

    cout << "lettre : " << caractere << " : ";

    cin >> lettreEntree;
    viderBuffer();

    return lettreEntree;
}

int testerReflex(const int nbLettre, const char lettreMin, const char lettreMax, int& nbSecondes) {
    char lettreEntree,
         lettreAttendue;

    int nbLettresCorrectes = 0;

    demarrerChrono();
    //Génère des lettres aléatoire et compte le nombre de lettres correctement saisie jusqu'à nbLettre
    for (int i = 0; i < nbLettre; ++i) {
        //Génère une lettre aléatoire entre lettreMin et lettreMax
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