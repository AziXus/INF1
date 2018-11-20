#include <ctime> //Permet d'utiliser la fonction time et difftime
#include "chrono.h"

using namespace std;

//Démarrage du chronomètre
double debutChrono()
{
   return time(NULL);//time(null) va retourner le temps actuel de l'OS
}

//Calcul du temps écoulé depuis le lancement du chornomètre
int stopChrono(double tempsDebut)
{
   //difftime permet de calculer le temps écouler entre deux varibales de temps
   //Dans la décalrations ci-dessous le différence va être calculée entre le début du chronomètre
   //et l'heure actuel du système
   int secondes = (int)difftime(time(NULL),(time_t)tempsDebut);
   return secondes;
}

