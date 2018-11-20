/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08_Clavier
 Fichier     : chrono.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.11.2018

 But         : Permet de démarrer et d'arrêter un chronomètre.
               Lorsque le chronomètre va être arrêté la libraire va calculer le nombre de secondes 
               séparant le lancement du chrono à la fin.

 Remarque(s) : Utilisation de la fonction ctime pour calculer le temps              

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
 * Calcul du temps écoulé depuis le lancement du chronomètre tout en calculant 
 * le nombre de seconde depuis le lancment du chronomètre
 * @return les secondes depuis le lancement du chronomètre 
 */
int  arreterChrono();
#endif

