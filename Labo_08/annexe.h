/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   annexe.h
 * Author: stéphane
 *
 * Created on November 19, 2018, 3:54 PM
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


