/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08_Clavier
 Fichier     : annexe.h
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

static const int PRECISION_FLOAT = 2;

/**
 * Fonction permettant de vider le buffer
 */
void viderBuffer();

/**
 * Lecture d'une saisie et vérification que la valeur entrée soit un entier
 * et définie dans une borne.
 * @param message string constante contenant le message indiquant le but de la valeur à entrée
 * @param minimum entier constant permettant de définir le minimum de la borne
 * @param maximum entier constant permettant de définir le maximum de la borne 
 * @return le nombre saisi par l'utilisateur
 */
int demanderValeur(const std::string& message, const int minimum, const int maximum);

/**
 * Fonction permettant d'afficher le résultat de la partie
 * et de calculer la vitesse de réponse de l'utilisateur.
 * @param temps entier constant contenant la durée de la partie en secondes
 * @param reponsesCorrectes entier constant contenant le nombre de réponse correctes
 * @param lances entier constant contenant le nombre de lancés pour la partie
 */
void afficherResultat(const int temps,  const int reponsesCorrectes,
                      const int lances, const int precision = PRECISION_FLOAT);

/**
 * Vérification que l'utilisateur entre une saisie correcte pour recomencer la partie(o ou n)
 * @return charactère soit o soit n
 */
char recommencerPartieSaisie();

/**
 * Permet de déterminer si la partie devra être recommencée ou non
 * @return true pour recommencer et false pour arrêter
 */
bool recommencerPartie();

/**
 * Permet de générer un entier aléatoire entre min et max compris
 * @param min entier constant définissant la valeur minimum
 * @param max entier constant définissant la valeur maximum
 * @return nombre entier générer aléatoirement entre min et max
 */
int  nombreAleatoire(const int min, const int max);
#endif


