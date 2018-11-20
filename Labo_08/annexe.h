/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08_Clavier
 Fichier     : main.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.11.2018

 But         : Générer des questions pour tester les réflexes de l'utilisateur.
               L'utilisateur choisi le nombre de lances entre 1 et 10.
               Un résultat indiquant le nombre de réponses correcteset le temps effectué
               est donné en fin de programme

 Remarque(s) : Utilisation de la fonction ctime pour calculer le temps mis pour résoudre le questionnaire.
               Le nombre de lances doit être comrpis entre 1 et 10.
               Utilisation des libraires annexe et reflex.              

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef ANNEXE_H
#define ANNEXE_H
#include <string>

/**
 *
 */
void viderBuffer();

/**
 *
 * @param message
 * @param maximum
 * @param minimum
 * @return
 */
int  demanderValeur(const std::string& message, const int& maximum, const int& minimum);

/**
 *
 * @param temps
 * @param reponsesCorrectes
 * @param lances
 */
void afficherResultat(int temps, int reponsesCorrectes, int lances);

/**
 *
 * @return
 */
char recommencerPartieSaisie();

/**
 *
 * @return
 */
bool recommencerPartie();

/**
 *
 * @param min
 * @param max
 * @return
 */
int  nombreAleatoire(const int& min, const int& max);
#endif


