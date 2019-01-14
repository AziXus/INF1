/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_10_Encodeur
 Fichier     : main.cpp
 Auteur(s)   : Robin Müller, Bruno Egremy
 Date        : 14.01.2019

 But         : Coder et décoder un message en fonction d'une clé saisie par l'utilisateur.
               Les erreurs de saisie sont gérées et le programme affiche uniquement les
               caractères imprimables.

 Remarque(s) : La clé saisie par l'utilisateur doit comporter au minimum 1 chiffre et
               est stocké dans un vecteur de int tandis que le message est stockée dans
               une string.
               Les librairies annexe et codage sont nécessaires.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "annexe.h"
#include "codage.h"

using namespace std;
int main() {
    const string SAISIE_MESSAGE = "Veuillez saisir le message à encoder",
                 ERREUR_MESSAGE = "Message à encoder invalide...",
                 SAISIE_CLE     = "Veuillez saisir la cle de codage "
                                  "(entiers separe par un [espace])",
                 ERREUR_CLE     = "Cle de codage invalide...";


    string message = saisieTexte(SAISIE_MESSAGE, ERREUR_MESSAGE);
    vector<int> cle = saisieVecteur(SAISIE_CLE, ERREUR_CLE);

    string messageEncoder = encoder(message, cle);
    cout << "Encodage : " << messageEncoder << endl;

    string messageDecoder = decoder(messageEncoder, cle);
    cout << "Decodage : " << messageDecoder << endl;

    return EXIT_SUCCESS;
}