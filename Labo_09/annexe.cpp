/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08_Clavier
 Fichier     : annexe.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.11.2018

 But         : Gérer les fonctions d'entrées sorties du programme ainsi que des 
               fonctions particulières

 Remarque(s) : Utilisation de la fonction srand pour générer des nombres aléatoires             

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
        cout << msg << " : " << " [ " << oui << " |  " << non << "] : ";
        cin  >> valeurSaisie;
        if(valeurSaisie == 'o' || valeurSaisie == 'n')
            valeurOK = true;
        else
        {
            valeurOK = false;
            cout << "Erreur de saisie. Veuillez entrer la valeur o ou n" << endl;
        }
        viderBuffer();
    } while(!valeurOK);
    
    return valeurSaisie == oui;
}