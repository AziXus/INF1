/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08_Clavier
 Fichier     : annexe.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 05.12.2018

 But         : Gérer les fonctions d'entrées sorties du programme ainsi que des 
               fonctions particulières

 Remarque(s) :              

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef ANNEXE_H
#define ANNEXE_H
#include <string>

static const int PRECISION_FLOAT = 2;

/**
 * Fonction permettant de vider le buffer
 */
void viderBuffer(const char delimiteur = '\n');

/**
 * Permet de déterminer si la partie devra être recommencée ou non
 * @return true pour recommencer et false pour arrêter
 */
bool repondsOui(const std::string& msg, const std::string& msgErreur, const char oui = 'O', const char non = 'N');
#endif