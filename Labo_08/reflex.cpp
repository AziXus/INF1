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
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

int testerReflex(int nbLettre, const char& lettreMin, const char& lettreMax, int& nbSecondes) {
    char lettreEntree,
         lettreAttendue;
    double tempsDebut;

    int nbLettresCorrectes = 0;
    tempsDebut = debutChrono();

    //Initialise le generateur aleatoire avec le temps actuel comme seed
    srand(time(NULL));

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

int nombreAleatoire(const int& min, const int& max) {
        return rand() % (max - min + 1) + min;
}

char saisieLettre(const char& caractere) {
    char lettreEntree;
    
    afficherQuestion(caractere);
    
    cin >> lettreEntree;
    viderBuffer();

    return lettreEntree;
}