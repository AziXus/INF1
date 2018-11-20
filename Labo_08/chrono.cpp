#include <ctime> //Permet d'utiliser la fonction time et difftime
#include "chrono.h"

using namespace std;

static unsigned int tempsDebut;

//Démarrage du chronomètre
void demarrerChrono()
{
   tempsDebut = (unsigned int)time(NULL); //time(null) retourne le temps actuel de l'OS
}

//Calcul du temps écoulé depuis le lancement du chronomètre
int arreterChrono()
{
   //difftime permet de calculer le temps écouler entre deux varibales de temps
   //Dans la décalrations ci-dessous le différence va être calculée entre le début du chronomètre
   //et l'heure actuel du système
   int secondes = (int)difftime(time(NULL),(time_t)tempsDebut);

   //Reinitialise le chronomètre
   tempsDebut = 0;

   return secondes;
}

