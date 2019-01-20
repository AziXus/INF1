/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_10_Encodeur
 Fichier     : annexe.cpp
 Author(s)   : Robin Müller, Bruno Egremy
 Date        : 14.01.19

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include "annexe.h"
#include <iostream>

using namespace std;

bool estUnNombre(const string& str) {
    //Caractère '0' (plus petit chiffre)
    static const char CAR_ZERO    = '0', //static afin d'initialiser une seule fois
                      CAR_POSITIF = '+',
                      CAR_NEGATIF = '-';

    //Si la chaine est vide ou ne comporte qu'un signe, on sort de la fonction
    if (str.empty())
        return false;
    else if (str.size() == 1 and (str[0] == CAR_POSITIF or str[0] == CAR_NEGATIF))
        return false;


    //Boucle parcourant la chaîne de caractère
    for (char c: str) {
        //CAR_ZERO + 9 correspond au caractère '9'
        //Si ce n'est pas un nombre, on retourne faux
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
        //On concat si différent du delimiteur
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

    //On veut s'assurer que le texte saisie comporte au moins tailleMin caractères
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

    //On veut s'assurer que le texte saisie comporte au moins tailleMin caractères
    do {
        //Message de saisie
        cout << MSG_SAISIE << " (min " << tailleMin << " entier(s)) : ";

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