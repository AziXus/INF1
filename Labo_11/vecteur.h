/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : vecteur.h
 Auteur(s)   : <prénom> <nom>
 Date        : <jj.mm.aaaa>

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
 */

#ifndef VECTEUR_H
#define VECTEUR_H
#include <iostream>
#include <vector>

using Ligne = std::vector<int>;
using Matrice = std::vector<Ligne>;

std::ostream& operator <<(std::ostream& os, const std::vector<int>& v);

std::ostream& operator <<(std::ostream& os, const Matrice& v);

bool estCarre(const Matrice& m);

int maxCol(const Matrice& m);

std::vector<int> sommeLignes(const Matrice& m);

int sommeLigne(const Ligne& ligne);

std::vector<int> vectSommeMin(const Matrice& m);

void shuffleMatrice(Matrice& m);

void sortMatrice(Matrice& m);

#endif /* VECTEUR_H */

