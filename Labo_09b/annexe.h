/*
 -----------------------------------------------------------------------------------
 Laboratoire   : Labo09
 Fichier       : annexe.h
 Auteur(s)     : Mohamed El-Sheikh et Gaetan Daubresse

 Modifié par   : Robin Müller, Stéphane Teixeira Carvalho
 Date          : 11.12.2018

 But           : Librairie comprenant toutes les fonctions utiles usuelle utilisé dans la plupart des programmes

 Remarque(s)   : -

 Modifications : Ajout ajdksfl

 Compilateur   : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef ANNEXE_H
#define ANNEXE_H

#include <string>

/// 
/// \param oui : lettre pour réponse positive
/// \param non : lettre pour réponse négative
/// \param message : message a l'utilisateur
/// \return : true si l'utilisateur répond positif, false s'il répond négatif
bool repondsQuestion(const std::string& message, char oui = 'o', char non = 'n');

/// 
/// \param message : message de fin 
/// \return : affiche le message de fin du programme
void afficherMessageFin(const std::string message);

/// La fonction vide le buffer 
void viderBuffer();

//Ajout
/**
 * Lecture d'une saisie et vérification que la valeur entrée soit un entier
 * et définie dans une borne.
 * @param message string constante contenant le message indiquant le but de la valeur à entrée
 * @param minimum entier constant permettant de définir le minimum de la borne
 * @param maximum entier constant permettant de définir le maximum de la borne
 * @return le nombre saisi par l'utilisateur
 */
int saisieValeur(const std::string& msg, const std::string& msgErreur, int minimum, int maximum);

#endif 

