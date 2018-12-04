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

void viderBuffer(const char DELIMITEUR)
{
   cin.ignore(numeric_limits<streamsize>::max(), DELIMITEUR);
}

bool repondsOui(const string& MSG, const string& MSG_ERREUR, const char OUI, const char NON)
{
    char valeurSaisie;
    bool valeurOK;

    //boucle vérifiant que la valeur entrée soit o ou n et aucune autre valeur
    do {
        cout << MSG << " [" << OUI << "/" << NON << "] : ";
        cin  >> valeurSaisie;

        if(valeurSaisie == OUI || valeurSaisie == NON)
            valeurOK = true;
        else
        {
            valeurOK = false;
            cout << MSG_ERREUR << endl;
        }
        viderBuffer();
    } while(!valeurOK);
    
    return valeurSaisie == OUI;
}