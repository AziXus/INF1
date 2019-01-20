/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_10_Encodeur
 Fichier     : codage.h
 Auteur(s)   : Robin Müller, Bruno Egremy
 Date        : 14.01.2019

 But         : Permet d'encoder/décoder une chaîne de caratère en fonction d'une clé

 Remarque(s) : Le message à encoder doit comporter des caractères ASCII 7 bits.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef LABO_10_CODAGE_H
#define LABO_10_CODAGE_H

#include <string>
#include <vector>

/**
 * @brief Permet d'encoder une chaîne de caractère à l'aide d'une clé d'encodage
 * @param message
 * @param cle
 * @return Une chaîne de caractère encodée
 */
std::string encoder(const std::string& message, const std::vector<int>& cle);

/**
 * @brief Permet de décoder une chaîne de caractère à l'aide d'une autre chaîne de
 *        caractère appelé clé
 * @param message
 * @param cle
 * @return Une chaîne de caractère décodée soit, le message original
 */
std::string decoder(const std::string& message, const std::vector<int>& cle);

/**
 * @brief Inverse une clé en multipliant chaque caractère par -1
 * @param cle
 * @return La clé inversée
 */
std::vector<int> inverserCle(const std::vector<int>& cle);


/**
 * @brief Génére un caractère en fonction d'un caractère de base et une valeur entière (clé)
 * @param car
 * @param val
 * @return Un caractère encodé/décodé
 */
char calculCar(char car, int val);


#endif //LABO_10_CODAGE_H