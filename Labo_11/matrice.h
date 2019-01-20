/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_11_Matrice
 Fichier     : matrice.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.01.2019

 But         : <à compléter>

 Remarque(s) : <à compléter>

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
 * Surcharge de l'opérateur de flux pour les lignes d'une matrice
 * @param os operateur de flux passé en référence
 * @param ligne ligne de la matrice à injecter dans le flux
 * @return le nouveau flux modifié
 */
std::ostream& operator<<(std::ostream& os, const Ligne& ligne);

/**
 * Surcharge de l'opérateur de flux pour une matrice
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
unsigned maxCol(const Matrice& m);

std::vector<int> sommeLignes(const Matrice& m);

int sommeLigne(const Ligne& ligne);

std::vector<int> vectSommeMin(const Matrice& m);

void shuffleMatrice(Matrice& m);

void sortMatrice(Matrice& m);

bool sommeDiagDG(const Matrice& m, int& sommeDG);

bool sommeDiagGD(const Matrice& m, int& sommeGD);

#endif /* MATRICE_H */

