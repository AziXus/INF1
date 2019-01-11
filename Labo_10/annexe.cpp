/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : annexe.cpp
 Auteur(s)   : Robin Müller
 Date        : 08.01.2019

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include "annexe.h"
#include <iostream>
#include <limits>

using namespace std;

void viderBuffer(char delimiteur) {
    cin.ignore(numeric_limits<streamsize>::max(), delimiteur);
}

string saisieTexte(const string& MSG_SAISIE, const string& MSG_ERREUR, size_t tailleMin) {
    string saisie;
    bool saisieOk;

    //On veut s'assurer que le texte saisie comporte au moins tailleMin carcatères
    do {
        //Message de saisie
        cout << MSG_SAISIE << " (min " << tailleMin << " caractères) : ";

        //Lecture de la saisie
        getline(cin, saisie);
        saisieOk = saisie.size() >= tailleMin;

        if(!saisieOk)
            cout << MSG_ERREUR << endl;
    } while(!saisieOk);

    return saisie;
}

vector<int> saisieVecteur(const string& MSG_SAISIE, const string& MSG_ERREUR) {
    vector<int> vecteurSaisie;
    int saisie;
    bool saisieOk;

    //On veut s'assurer que le texte saisie comporte au moins tailleMin carcatères
    do {
        //Message de saisie
        cout << MSG_SAISIE << " (entrer n'importe quel caractere pour stopper la saisie) : ";

        //On ajouter des valeurs au vecteurs jusqu'à ce qu'il y ai un caractère soit saisie
        while (cin >> saisie) {
            vecteurSaisie.push_back(saisie);
        }

        if (!cin.good())
            cin.clear();
        viderBuffer();

        //Si le vecteur est vide, saisie invalide
        saisieOk = !vecteurSaisie.empty();

        if(!saisieOk)
            cout << MSG_ERREUR << endl;

    } while(!saisieOk);
    return vecteurSaisie;
}