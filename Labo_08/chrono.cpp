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

