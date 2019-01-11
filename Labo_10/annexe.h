/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : annexe.cpp
 Auteur(s)   : Robin Müller
 Date        : 08.01.2019

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef LABO_10_ANNEXE_H
#define LABO_10_ANNEXE_H

#include <string>
#include <vector>

void viderBuffer(char delimiteur = '\n');
std::string saisieTexte(const std::string& MSG_SAISIE, const std::string& MSG_ERREUR, size_t tailleMin = 1);
std::vector<int> saisieVecteur(const std::string& MSG_SAISIE, const std::string& MSG_ERREUR);

#endif //LABO_10_ANNEXE_H
