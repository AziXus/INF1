/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo09
 Fichier     : traitementDate.h.h
 Auteur(s)   : Mohamed El-Sheikh et Gaetan Daubresse 
 Date        : 04.12.2018

 But         : Librairie comprenant toutes les fonctions pour le traitement des dates et le calcul 
               du nombre de jour entre 2 dates   

 Remarque(s) : -  

 Compilateur : MinGW-g++ 6.3.0
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

bool ajouteJourADate(int& jour, int& mois, int& annee, int nbJour);

#endif 

