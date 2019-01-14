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

std::ostream& operator <<(std::ostream& os, const std::vector<int>& v);

std::ostream& operator <<(std::ostream& os, const std::vector<std::vector<int>>& v);

#endif /* VECTEUR_H */

