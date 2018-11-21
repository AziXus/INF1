/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08_Clavier
 Fichier     : chrono.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.11.2018

 But         : Permet de démarrer et d'arrêter un chronomètre.
               Lorsque le chronomètre va être arrêté la libraire va calculer le nombre de secondes 
               séparant le lancement du chrono à la fin.

 Remarque(s) : Utilisation de la fonction ctime pour calculer le temps.              

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include <ctime> //Permet d'utiliser la fonction time et difftime
#include "chrono.h"

using namespace std;

static unsigned int tempsDebut;

void demarrerChrono()
{
   tempsDebut = (unsigned int)time(NULL); //time(null) retourne le temps actuel de l'OS
}

int arreterChrono()
{
   //difftime permet de calculer le temps écouler entre deux variables de temps
   //Dans la déclaration ci-dessous le différence entre le début du chronomètre et
   //le temps actuel du système est calculé
   int secondes = (int)difftime(time(NULL),(time_t)tempsDebut);

   //Reinitialise le chronomètre
   tempsDebut = 0;

   return secondes;
}

