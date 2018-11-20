/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : <nom du fichier>.cpp
 Auteur(s)   : <prénom> <nom>
 Date        : <jj.mm.aaaa>

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
 */

#ifndef ANNEXE_H
#define ANNEXE_H
#include <string>

/**
 *
 */
void viderBuffer();

/**
 *
 * @param message
 * @param maximum
 * @param minimum
 * @return
 */
int  demanderValeur(const std::string& message, const int& maximum, const int& minimum);

/**
 *
 * @param temps
 * @param reponsesCorrectes
 * @param lances
 */
void afficherResultat(int temps, int reponsesCorrectes, int lances);

/**
 *
 * @return
 */
char recommencerPartieSaisie();

/**
 *
 * @return
 */
bool recommencerPartie();

/**
 *
 * @param min
 * @param max
 * @return
 */
int  nombreAleatoire(const int& min, const int& max);
#endif


