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

bool estUnNombre(const string& str) {
    //Caractère '0' (plus petit chiffre)
    static const char CAR_ZERO    = '0', //static afin de l'initialiser qu'une seule fois
            CAR_POSITIF = '+',
            CAR_NEGATIF = '-';

    if (str.empty())
        return false;
    else if (str.size() == 1 and
             (str[0] == CAR_POSITIF or str[0] == CAR_NEGATIF))
        return false;


    //boucle parcourant la chaîne de caractère
    for (char c: str) {
        //CAR_ZERO + 9 correspond au caractère '9'
        if (c != CAR_POSITIF and c != CAR_NEGATIF and (c < CAR_ZERO or c > CAR_ZERO + 9))
            return false;
    }

    return true;
}

vector<int> stringSplit(const string& str, char delimiteur) {
    vector<int> splitValues;
    string splitString;

    //On parcours les caractères de la chaine
    for (char c: str) {
        //On concat si différent du dénominateur
        if (c != delimiteur)
            splitString += c;
        //Sinon on ajoute une case au vecteur si c'est un entier
        else {
            if (estUnNombre(splitString))
                splitValues.push_back(stoi(splitString));
            splitString = "";
        }
    }

    //On verifie s'il reste une valeur dans splitValues
    if (estUnNombre(splitString))
        splitValues.push_back(stoi(splitString));

    return splitValues;
}

string saisieTexte(const string& MSG_SAISIE, const string& MSG_ERREUR, size_t tailleMin) {
    string saisie;
    bool saisieOk;

    //On veut s'assurer que le texte saisie comporte au moins tailleMin carcatères
    do {
        //Message de saisie
        cout << MSG_SAISIE << " (min " << tailleMin << " caractère(s)) : ";

        //Lecture de la saisie
        getline(cin, saisie);
        saisieOk = saisie.size() >= tailleMin;

        if(!saisieOk)
            cout << MSG_ERREUR << endl;
    } while(!saisieOk);

    return saisie;
}

vector<int> saisieVecteur(const string& MSG_SAISIE, const string& MSG_ERREUR, size_t tailleMin) {
    vector<int> vecteurSaisie;
    string saisie;
    bool saisieOk;

    //On veut s'assurer que le texte saisie comporte au moins tailleMin carcatères
    do {
        //Message de saisie
        cout << MSG_SAISIE << " (min " << tailleMin << " nombre(s)) : ";

        //On ajouter des valeurs au vecteurs jusqu'à ce qu'il y ai un caractère soit saisie
        getline(cin, saisie);

        //Delimiteur en const ?
        vecteurSaisie = stringSplit(saisie, ' ');

        //Si le vecteur est vide, saisie invalide
        saisieOk = vecteurSaisie.size() >= tailleMin;

        if(!saisieOk)
            cout << MSG_ERREUR << endl;

    } while(!saisieOk);
    return vecteurSaisie;
}