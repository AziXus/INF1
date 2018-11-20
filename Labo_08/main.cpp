/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08_Clavier
 Fichier     : main.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.11.2018

 But         : Générer des questions pour tester les réflexes de l'utilisateur.
               L'utilisateur choisi le nombre de lances entre 1 et 10.
               Un résultat indiquant le nombre de réponses correctes et le temps effectué
               pour terminer le questionnaire est donné en fin de programme.

 Remarque(s) : Utilisation de la fonction ctime pour calculer le temps mis pour résoudre le questionnaire.
               Le nombre de lances doit être compris entre 1 et 10.
               Utilisation des libraires annexe et reflex.              

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "annexe.h"
#include "reflex.h"

using namespace std;

int main() {
   const string MSG_NB_LANCES = "Combien de lances ";
   
   const unsigned int NB_LANCES_MIN =  1,
                      NB_LANCES_MAX = 10;
   
   const unsigned char LETTRE_MIN = 'a',
                       LETTRE_MAX = 'z';
   
   int nbLances,
       nbLettresCorrectes,
       nbSecondes;
   
   cout << "ce programme ..." << endl;
   do {
      //Saisie de l'utlisateur pour le nombre de lancé
      nbLances = demanderValeur(MSG_NB_LANCES, NB_LANCES_MIN, NB_LANCES_MAX);
      //Démarrage du questionnaire
      nbLettresCorrectes = testerReflex(nbLances, LETTRE_MIN, LETTRE_MAX, nbSecondes);
      //Affichage du résultat de l'utilisateur
      afficherResultat(nbSecondes, nbLettresCorrectes, nbLances);
   } while(recommencerPartie());
   
   return EXIT_SUCCESS;
}

