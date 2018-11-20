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
    double tempsDebut;

    int nbLettresCorrectes = 0;

    //Initialise le generateur aleatoire avec le temps actuel comme seed
    srand(time(NULL));

    tempsDebut = debutChrono();

    for (int i = 0; i < nbLettre; ++i) {
        lettreAttendue = (char)(nombreAleatoire(lettreMin, lettreMax));
        
        lettreEntree = saisieLettre(lettreAttendue);
        
        //Lettre correctement entrée ?
        if (lettreEntree == lettreAttendue)
            ++nbLettresCorrectes;
    }

    nbSecondes = stopChrono(tempsDebut);
    
    return nbLettresCorrectes;
}