/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_11_Matrice
 Fichier     : matrice.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.01.2019

 But         : Mettre à disposition des fonctions nécessaire à la manipulation de
               matrice. 

 Remarque(s) : Surcharge de la fonction operator.
               Utilisation de la libraire vector et algorithm.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef MATRICE_H
#define MATRICE_H
#include <iostream>
#include <vector>

using Ligne = std::vector<int>;
using Matrice = std::vector<Ligne>;

/**
 * Surcharge de l'opérateur de flux pour pouvoir afficher une ligne
 * @param os operateur de flux passé en référence
 * @param ligne ligne de la matrice à injecter dans le flux
 * @return le nouveau flux modifié
 */
std::ostream& operator<<(std::ostream& os, const Ligne& ligne);

/**
 * Surcharge de l'opérateur de flux pour l'affichage d'une matrice
 * @param os operateur de flux passé en référence
 * @param ligne matrice à injecter dans le flux
 * @return le nouveau flux modifié
 */
std::ostream& operator<<(std::ostream& os, const Matrice& m);

/**
 * Détermine si la matrice est carré
 * @param m matrice à analyser
 * @return vrai si carré, faux sinon
 */
bool estCarre(const Matrice& m);

/**
 * Détermine la longueur maximale des lignes de la matrice
 * @param m matrice à analyser
 * @return taille de la ligne la plus grande
 */
size_t maxCol(const Matrice& m);

/**
 * Calcul la somme des valeurs d'une ligne
 * @param ligne la ligne à utiliser
 * @return la somme de la ligne
 */
int sommeUneLigne(const Ligne& ligne);

/**
 * Calcul la somme des valeurs, ligne par ligne, d'une matrice. 
 * Les sommes sont stockés dans un vecteur.
 * @param m la matrice à utiliser
 * @return vecteur de int contenant la somme des différentes lignes dans l'ordre d'origine
 */
std::vector<int> sommeLigne(const Matrice& m);

/**
 * Retourne la ligne ayant la somme la plus faible d'une matrice
 * @param m la matrice à analyser
 * @return la ligne ayant la plus petite somme
 */
Ligne vectSommeMin(const Matrice& m);

/**
 * Mélange les lignes d'une matrice aléatoirement
 * @param m matrice en référence à mélanger
 */
void shuffleMatrice(Matrice& m);

/**
 * Tri la matrice dans un ordre croissant en fonction de l'élement le plus grand de chaque ligne
 * @param m matrice à trier
 */
void sortMatrice(Matrice& m);

/**
 * Calcul la somme de la diagonale "/" (droite-gauche)
 * @param m matrice à analyser
 * @param sommeDG entier en référence contenant la somme de la diagonale
 * @return vrai si la matrice est carree, faux sinon
 */
bool sommeDiagDG(const Matrice& m, int& sommeDG);

/**
 * Calcul la somme de la diagonale "\" (gauche-droite)
 * @param m matrice à analyser
 * @param sommeGD entier en référence contenant la somme de la diagonale
 * @return vrai si la matrice est carree, faux sinon
 */
bool sommeDiagGD(const Matrice& m, int& sommeGD);

#endif /* MATRICE_H */

