/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08_Clavier
 Fichier     : annexe.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.11.2018

 But         : Gérer les fonctions d'entrées sorties du programme ainsi que des 
               fonctions particulières

 Remarque(s) : Utilisation de la fonction srand pour générer des nombres aléatoires             

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef ANNEXE_H
#define ANNEXE_H
#include <string>
/**
 * Fonction permettant de vider le buffer
 */
void viderBuffer();

/**
 * Vérification d'une saisie pour que la valeur entrée par l'utilisateur soit correcte
 * et définie dans une borne.
 * @param message string constante contenant le message indiquant le but de la borne
 * @param minimum entier constant permettant de définir le minimum de la borne
 * @param maximum entier constant permettant de définir le maximum de la borne 
 * @return le nombre saisi par l'utilisateur
 */
int  demanderValeur(const std::string& message, const int& maximum, const int& minimum);

/**
 * Fonction permmetant d'afficher le résultat de la partie.
 * Elle permet également de calculer la vitesse de réponse de l'utilisateur.
 * @param temps entier contenant la durée de la partie
 * @param reponsesCorrectes entier constant contenant le nombre de réponse correctes
 * @param lances entier constant contenant le nombre de question pour la partie
 */
void afficherResultat(const int temps, const int reponsesCorrectes, const int lances);

/**
 * Vérification que l'utilisateur entre une saisie correcte pour le recommencemnt de la partie(o ou n)
 * @return un charactère soit o soit n
 */
char recommencerPartieSaisie();

/**
 * Permet de définir si la partie devra être recommencée ou non
 * @return un booléan qui défini si la partie devra être recommencée(true) ou arrêtée(false)
 */
bool recommencerPartie();

/**
 * Permet de générer un entier aléatoire entre min et max
 * @param min entier constant qui permet de définir le nombre minimum pouvant être générer aléatoirement
 * @param max entier constant qui permet de définir le nombre maximum pouvant être générer aléatoirement
 * @return un nombre entier générer aléatoirement entre min et max
 */
int  nombreAleatoire(const int& min, const int& max);
#endif


