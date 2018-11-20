/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08_Clavier
 Fichier     : reflex.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.11.2018

 But         : Générer des questions pour tester les réflexes de l'utilisateur.
               Vérifier si l'utilisateur a répondu correctement (calcul du score).

 Remarque(s) : Utilisation des libraires annexe et chrono.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef REFLEX_H
#define REFLEX_H

/**
 * Génère des lettres aléatoirement et mesure les réflexes de l'utilisateur.
 * @param nbLettre   Le nombre de lettre demandée pour tester les reflex
 * @param lettreMin  La plus petite lettre pouvant être demandé
 * @param lettreMax  La plus grande lettre pouvant être demandé
 * @param nbSecondes Contient le nombre de secondes totales.
 * @return           Retourne le nombre de lettres correctement saisies par l'utilisateur
 */
int  testerReflex(int nbLettre, const char& lettreMin, const char& lettreMax, int& nbSecondes);

#endif
