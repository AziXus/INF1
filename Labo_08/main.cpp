/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_07_Tir
 Fichier     : Labo_07_TeixeiraCarvalho.cpp
 Auteur(s)   : Stéphane Teixeira Carvalho
 Date        : 13.11.2018

 But         : Afficher une grille de résultats des différents tirs de joueurs lors d'un 
               concour de tir.
               Le résultat peut être de 100 au maximum et le joueur perd 1 point 
               de penalité par cm d'écart du centre.

 Remarque(s) : Utiliser la fonction srand.
               Le nombre de joueur sera compris entre 2 et 10.
               Le nombre de séries sera compris entre 1 et 10.
               Le nombre de tirs sera compris entre 6 et 12.              

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
      //
      nbLances = demanderValeur(MSG_NB_LANCES, NB_LANCES_MIN, NB_LANCES_MAX);
      //
      nbLettresCorrectes = testerReflex(nbLances, LETTRE_MIN, LETTRE_MAX, nbSecondes);
      //
      afficherResultat(nbSecondes, nbLettresCorrectes, nbLances);
   } while(recommencerPartie());
   
   return EXIT_SUCCESS;
}

