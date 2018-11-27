/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08_Clavier
 Fichier     : chrono.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.11.2018

 But         : Permet de démarrer et d'arrêter un chronomètre.
               Lorsque le chronomètre va être arrêté la libraire calcule sa durée en secondes.

 Remarque(s) : Utilisation de la libraire ctime pour calculer un temps.              

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef CHRONO_H
#define CHRONO_H
/**
 * Démarrage du chronomètre
 */
void demarrerChrono();

/**
 * Calcul du temps écoulé depuis le lancement du chronomètre puis l'arrête.
 * @return entier, les secondes depuis le lancement du chronomètre
 */
int  arreterChrono();
#endif

