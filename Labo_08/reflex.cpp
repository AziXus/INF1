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
#include <ctime>

using namespace std;

/**
 *
 * @param caractere
 * @return
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
    for (int i = 0; i < nbLettre; ++i) {
        lettreAttendue = (char)(nombreAleatoire(lettreMin, lettreMax));
        
        lettreEntree = saisieLettre(lettreAttendue);
        
        //Lettre correctement entrée ?
        if (lettreEntree == lettreAttendue)
            ++nbLettresCorrectes;
    }

    //arreterChrono() retourne le nombre de secondes depuis son départ
    nbSecondes = arreterChrono();
    
    return nbLettresCorrectes;
}