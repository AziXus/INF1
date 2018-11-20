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
void viderBuffer();

int  demanderValeur(const std::string& message, const int& maximum, const int& minimum);

void afficherQuestion(const char& caractere);

void afficherResultat(int temps, int reponsesCorrectes, int lances);

char recommencerPartieSaisie();

bool recommencerPartie();
#endif


