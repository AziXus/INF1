/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08_Clavier
 Fichier     : reflex.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.11.2018

 But         : Générer des questions pour tester les réflexes de l'utilisateur.
               Vérifier si l'utilisateur a répondu correctement(calcul du score).

 Remarque(s) :nUtilisation des libraires annexe et chrono.              

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef REFLEX_H
#define REFLEX_H

/**
 *
 * @param nbLettre
 * @param lettreMin
 * @param lettreMax
 * @param nbSecondes
 * @return
 */
int  testerReflex(int nbLettre, const char& lettreMin, const char& lettreMax, int& nbSecondes);

#endif
