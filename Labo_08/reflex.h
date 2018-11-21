/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08_Clavier
 Fichier     : reflex.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.11.2018

 But         : Générer des questions pour tester les réflexes clavier de l'utilisateur.
               Les questions sont des lettres, situées dans une borne, qui devront être saisies.
               Vérifie si l'utilisateur a répondu correctement(calcul du score) et calcul le temps.

 Remarque(s) : Utilisation des libraires annexe et chrono.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef REFLEX_H
#define REFLEX_H

/**
 * Génère des lettres aléatoirement et mesure les réflexes de l'utilisateur.
 * @param nbLettre entier constant contenant le nombre de lettre demandée pour tester les reflex
 * @param lettreMin entier constant définissant la lettre minimum pouvant être demandé
 * @param lettreMax entier constant définissant la lettre maximum pouvant être demandé
 * @param nbSecondes entier par référence avec le nombre de secondes totales.
 * @return entier contenant le nombre de lettres correctement saisies par l'utilisateur
 */
int testerReflex(const int nbLettre, const char lettreMin, const char lettreMax, int& nbSecondes);

#endif
