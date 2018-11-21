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
#include <ctime> //Permet d'utiliser la fonction time et difftime
#include "chrono.h"

using namespace std;

static unsigned int tempsDebut;

void demarrerChrono()
{
   tempsDebut = (unsigned int)time(NULL); //retourne le temps actuel de l'OS
}

int arreterChrono()
{
   //difftime permet de calculer le temps écoulé entre deux variables de type time_t.
   //Calcul de le différence entre le temps actuel et le début du chronomètre.
   int secondes = (int)difftime(time(NULL), (time_t)tempsDebut);

   //Reinitialise le chronomètre
   tempsDebut = 0;

   return secondes;
}

