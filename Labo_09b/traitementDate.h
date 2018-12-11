/*
 -----------------------------------------------------------------------------------
 Laboratoire   : Labo09b
 Fichier       : traitementDate.h.h
 Auteur(s)     : Mohamed El-Sheikh et Gaetan Daubresse

 Modifié par   : Robin Müller, Stéphane Teixeira Carvalho
 Date          : 11.12.2018

 But           : Librairie comprenant toutes les fonctions pour le traitement des dates et le calcul
                 du nombre de jour entre 2 dates

 Remarque(s)   :  -

 Modifications : Ajout d'une fonction permettant d'ajouter ou soustraire des jours à une date.

 Compilateur   : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef TRAITEMENTDATE_H
#define TRAITEMENTDATE_H


/// 
/// \param mois
/// \param annee
/// \return : nombre de jour dans le mois entre en parametre 
int nbrJoursMois(int mois, int annee); 

/// 
/// \param annee
/// \return : true si l'annee est bissextile false sinon 
bool bissextile(int annee); 

/// 
/// \param jour1
/// \param jour2
/// \param mois1
/// \param mois2
/// \param annee1
/// \param annee2
/// \return : Fonction qui permet de calculer le nombre total de jours entre 2 dates
int calculNombreJour(int jour1, int jour2, int mois1, int mois2, int annee1, int annee2);

/// Ajoute ou soustrait un nombre de jours à la date en référence
/// \param nbJour entier contenant le nombre de jours à additionner ou soustraire
/// \param jour entier en référence contenant le jour
/// \param mois entier en référence contenant le mois
/// \param annee entier en référence contenant l'année
/// \return true si la date calculé est dans les bornes, false sinon
bool ajouteJourADate(int nbJour, int& jour, int& mois, int& annee, int jourMin, int moisMin, int anneeMin, int jourMax, int moisMax, int anneeMax);

#endif 

