/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   date.h
 * Author: stéphane
 *
 * Created on November 27, 2018, 1:55 PM
 */

#ifndef DATE_H
#define DATE_H

#include <string>

/**
 *
 * Fonction permettant de lire une date selon le format suivant : DD-MM-YYYY
 *
 * @param msg
 * @param msg_erreur
 * @param annee_min
 * @param annee_max
 */
void saisieDate(const std::string& msg,
                const std::string& msg_erreur,
                const unsigned     annee_min,
                const unsigned     annee_max);


/**
 *
 * Fonction vérifiant si une année
 *
 * @param annee_min
 * @param annee_max
 * @return
 */
bool anneeCorrecte(const unsigned annee,
                   const unsigned annee_min,
                   const unsigned annee_max);



#endif /* DATE_H */

