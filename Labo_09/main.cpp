/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_09_Date
 Fichier     : main.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.11.2018

 But         : Générer des questions pour tester les réflexes clavier de l'utilisateur.
               Les questions sont des lettres de a à z qui devront être saisies.
               L'utilisateur choisi le nombre de lancés entre 1 et 10.
               Le nombre de réponses correctes et le temps effectué
               pour terminer le questionnaire est donné en fin de programme.
               Le programme peut ensuite être recommencé ou stoppé.

 Remarque(s) : Utilisation de la fonction ctime pour mesurer le temps pris pour résoudre le questionnaire.
               Le nombre de lancés doit être compris entre 1 et 10.
               Utilisation des libraires annexe et reflex.              

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include "date.h"

using namespace std;

int main() {
    saisieDate("Saisie : ", "Erreur", 1900, 2200);

    return EXIT_SUCCESS;
}

