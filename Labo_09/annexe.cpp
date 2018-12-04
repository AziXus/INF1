/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08_Clavier
 Fichier     : annexe.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 05.12.2018

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include <iostream>
#include <iomanip>
#include <limits>
#include "annexe.h"

using namespace std;

void viderBuffer(const char delimiteur)
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
    //La valeur ASCII 48 correspond au nombre 0
    const int INDEX_NOMBRE_ASCII = 48;

    for (char c: chaineCaractere) {
        //INDEX_NOMBRE_ASCII + 9 correspond au caractère 9
        if (c < INDEX_NOMBRE_ASCII or c > INDEX_NOMBRE_ASCII + 9)
            return false;
    }

    return true;
}