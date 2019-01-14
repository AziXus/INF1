/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_10_Encodeur
 Fichier     : annexe.cpp
 Auteur(s)   : Robin Müller, Bruno Egremy
 Date        : 14.01.2019

 But         : Cette libraire gère les fonctions de saisies requises par notre programme.
               Elle permet principalement la lecture d'un texte et d'un vecteur de int.

 Remarque(s) : Elle comporte également deux fonctions de manipulations de string requisent
               pour la lecture du vecteur de int

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO_10_ANNEXE_H
#define LABO_10_ANNEXE_H

#include <string>
#include <vector>

/**
 * Cette fonction determine si la chaine de caractères passé en paramètre est un entier.
 * @param str chaine de caractères à analyser
 * @return true si la chaine est un nombre, false sinon
 */
bool estUnNombre(const std::string& str);

/**
 * Cette fonction stocke les entiers contenuent dans une chaine de caractère et les placent dans
 * un vecteur d'entier.
 * @param str chaine de caractère à transformer en vecteur
 * @param delimiteur char delimitant les différents entiers
 * @return vecteur de int contenant les nombres trouvés
 */
std::vector<int> stringSplit(const std::string& str, char delimiteur);

/**
 * Cette fonction lit une chaine de caractère saisie par l'utilisateur.
 * @param MSG_SAISIE message de saisie à afficher lors de la saisie
 * @param MSG_ERREUR message d'erreur à afficher lors d'une saisie invalide
 * @param tailleMin nombre de caractères devant être saisie au minimum
 * @return la chaine de caractères saisie par l'utilisateur
 */
std::string saisieTexte(const std::string& MSG_SAISIE,
                        const std::string& MSG_ERREUR,
                        size_t tailleMin = 1);

/**
 * Cette fonction lit un vecteur d'entier saisie par l'utilisateur.
 * @param MSG_SAISIE message de saisie à afficher lors de la saisie
 * @param MSG_ERREUR message d'erreur à afficher lors d'une saisie invalide
 * @param tailleMin nombre d'entiers devant être saisie au minimum
 * @return les entiers saisies par l'utilisateur sous forme de vecteur
 */
std::vector<int> saisieVecteur(const std::string& MSG_SAISIE,
                               const std::string& MSG_ERREUR,
                               size_t tailleMin = 1);

#endif //LABO_10_ANNEXE_H
