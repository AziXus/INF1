/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_09_Date
 Fichier     : annexe.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 05.12.2018

 But         : Gérer les fonctions d'entrées sorties ainsi que des
               fonctions particulières.

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef ANNEXE_H
#define ANNEXE_H
#include <string>

/**
 * Fonction permettant de vider le buffer
 * @param delimiteur caractère jusqu'ou le buffer doit être vidé (valeur par défaut '/n')
 */
void viderBuffer(char delimiteur = '\n');

/**
 * Permet de déterminer si la partie devra être recommencée ou non
 * @param msg string constante contenant le message à afficher lors de la saisie
 * @param msgErreur string constante contenant le message d'erreur
 * @param oui caractère répresentant une réponse "oui" (valeur par défaut 'O')
 * @param non carcatère répresentant une réponse "non" (valeur par défaut 'N')
 * @return true pour recommencer et false pour arrêter
 */
bool repondsOui(const std::string& msg, const std::string& msgErreur, char oui = 'O', char non = 'N');

/**
 * Détermine si la chaine de caractère en paramètre représente un nombre
 * @param chaineCaractere string à analyser
 * @return true si la valeur de la chaîne est un nombre, false sinon
 */
bool estUnNombre(const std::string& chaineCaractere);
#endif