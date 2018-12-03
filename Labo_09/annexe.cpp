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

bool repondsOui(const string& msg, const string& msg_erreur, const char oui, const char non)
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
            cout << msg_erreur << endl;
        }
        viderBuffer();
    } while(!valeurOK);
    
    return valeurSaisie == oui;
}