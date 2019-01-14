/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_10_Encodeur
 Fichier     : main.cpp
 Auteur(s)   : Robin Müller
 Date        : 08.01.2019

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <cstdlib>

#include "annexe.h"
#include "codage.h"

using namespace std;
int main() {
    const string SAISIE_MESSAGE = "Veuillez saisir le message à encoder",
                 ERREUR_MESSAGE = "Message à encoder invalide...",
                 SAISIE_CLE     = "Veuillez saisir la cle de codage",
                 ERREUR_CLE     = "Cle de codage invalide...";


    string message = saisieTexte(SAISIE_MESSAGE, ERREUR_MESSAGE);
    vector<int> cle = saisieVecteur(SAISIE_CLE, ERREUR_CLE);

    string messageEncoder = encoder(message, cle);
    cout << "Encodage : " << messageEncoder << endl;

    string messageDecoder = decoder(messageEncoder, cle);
    cout << "Decodage : " << messageDecoder << endl;

    return EXIT_SUCCESS;
}