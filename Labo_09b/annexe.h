/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo09
 Fichier     : annexe.h
 Auteur(s)   : Mohamed El-Sheikh et Gaetan Daubresse 
 Date        : 04.12.2018

 But         : Librairie comprenant toutes les fonctions utiles usuelle utilisé dans la plupart des programmes   

 Remarque(s) : -  

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef ANNEXE_H
#define ANNEXE_H

#include <string>

/// 
/// \param oui : lettre pour oui 
/// \param non : lettre pour non 
/// \param messageRecommencer : message a l'utilisateur 
/// \return : true si l'utilisateur presse oui, false s'il presse sur non 
bool recommencer(char oui, char non, std::string messageRecommencer);

/// 
/// \param message : message de fin 
/// \return : affiche le message de fin du programme
void afficherMessageFin(const std::string message);

/// La fonction vide le buffer 
void viderBuffer(); 
#endif 

