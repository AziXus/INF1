/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : codage.cpp
 Auteur(s)   : Robin Müller
 Date        : 08.01.2019

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef LABO_10_CODAGE_H
#define LABO_10_CODAGE_H

#include <string>
#include <vector>

std::string encoder(const std::string& message, const std::vector<int>& cle);
std::string decoder(const std::string& message, const std::vector<int>& cle);
std::vector<int> inverserCle(const std::vector<int>& cle);

#endif //LABO_10_CODAGE_H
