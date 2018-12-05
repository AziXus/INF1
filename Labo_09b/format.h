/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo09
 Fichier     : format.h
 Auteur(s)   : Mohamed El-Sheikh et Gaetan Daubresse 
 Date        : 04.12.2018

 But         : Librairie comprenant toutes les fonctions pour le traitement et la vérification 
               du format de la date et des ses bornes.

 Remarque(s) : -  

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef FORMAT_H
#define FORMAT_H

#include <string>

/// La fonction converti une date JJ-MM-AAAA string en trois int jour, mois et annee 
/// \param messSaisie : Message de saisie
/// \param messErreur : Message d'erreur
/// \param jour : Variable jour affectee en fonction de la saisie de l'utilisateur
/// \param mois : Variable mois           "                                   "
/// \param annee : Variable annee         "                                   "
/// \param jourMin :    borne min   pour le jour 
/// \param moisMin :    "     "     pour le mois
/// \param anneeMin :   "     "     pour l'annee
/// \param jourMax :    borne max   pour le jour 
/// \param moisMax :    "     "     pour le mois 
/// \param anneeMax :   "     "     pour l'annee
void saisie(const std::string& messSaisie, const std::string& messErreur, int& jour, int& mois, int& annee,
		const int jourMin, const int moisMin, const int anneeMin, const int jourMax, const int moisMax, const int anneeMax);

/// 
/// \param saisie : Date saisie par l'utilisateur
/// \return : true si le format de saisie et correcte false sinon
bool controleSaisie(std::string saisie); 

/// Sous fonction de la fonction saisie permettant de controler les dates 
/// \param jour : Variable jour affectee en fonction de la saisie de l'utilisateur
/// \param mois : Variable mois           "                                   "
/// \param annee : Variable annee         "                                   "
/// \param jourMin :    borne min   pour le jour 
/// \param moisMin :    "     "     pour le mois
/// \param anneeMin :   "     "     pour l'annee
/// \param jourMax :    borne max   pour le jour 
/// \param moisMax :    "     "     pour le mois 
/// \param anneeMax :   "     "     pour l'annee
/// \return : true si la date est correcte false sinon 
bool controleDate(int jour, int mois, int annee, const int jourMin, const int moisMin, const int anneeMin, const int jourMax, 
				const int moisMax, const int anneeMax); 

/// 
/// \param jour
/// \param mois
/// \param annee 
/// \return : true si la date existe false sinon 
bool dateExistante(int jour, int mois, int annee); 

/// 
/// \param jour1
/// \param jour2
/// \param mois1
/// \param mois2
/// \param annee1
/// \param annee2
/// \return : true si la date 1 est inferieur a la date 2
bool date1AntDate2(int jour1, int jour2, int mois1, int mois2, int annee1, int annee2);

#endif 

