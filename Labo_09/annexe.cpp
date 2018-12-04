/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_09_Date
 Fichier     : annexe.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 05.12.2018

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include <iostream>
#include <limits>
#include "annexe.h"

using namespace std;

void viderBuffer(char delimiteur)
{
   cin.ignore(numeric_limits<streamsize>::max(), delimiteur);
}

bool repondsOui(const string& msg, const string& msgErreur, char oui, char non)
{
    char valeurSaisie;
    bool valeurOK;

    //boucle vérifiant que la valeur entrée soit o ou n et aucune autre valeur
    do {
        cout << msg << " [" << oui << "/" << non << "] : ";
        cin  >> valeurSaisie;

        if(valeurSaisie == oui || valeurSaisie == non)
            valeurOK = true;
        else
        {
            valeurOK = false;
            cout << msgErreur << endl;
        }
        viderBuffer();
    } while(!valeurOK);
    
    return valeurSaisie == oui;
}

bool estUnNombre(const string& chaineCaractere) {
    //Caractère '0' (plus petit chiffre)
    static const char CAR_ZERO = '0'; //static afin de l'initialiser qu'une seule fois
    //boucle parcourant la chaîne de caractère
    for (char c: chaineCaractere) {
        //CAR_ZERO + 9 correspond au caractère '9'
        if (c < CAR_ZERO or c > CAR_ZERO + 9)
            return false;
    }

    return true;
}