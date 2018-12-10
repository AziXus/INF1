
#include <iostream>
#include <string>
#include "annexe.h"



using namespace std;


// fonction permettant à l'utilisateur de recommence le programme
bool recommencer(char oui, char non, string messageRecommencer){
   char recommencer; 
   do{
      cout << messageRecommencer << "[" << oui << "-" << non << "]";
      cin >> recommencer; 
   }while(recommencer != oui and recommencer != non);
   return (recommencer == oui);
}

//fonction permettant d'afficher le message de fin

void afficherMessageFin(const string message)
{
   cout << message << endl;
   cin.ignore(); 
   viderBuffer();
}

void viderBuffer(){
   while(cin.get() != '\n');
}

/**
 * Lecture d'une saisie et vérification que la valeur entrée soit un entier
 * et définie dans une borne.
 * @param msg string constante contenant le message indiquant le but de la valeur à entrée
 * @param minimum entier constant permettant de définir le minimum de la borne
 * @param maximum entier constant permettant de définir le maximum de la borne
 * @return le nombre saisi par l'utilisateur
 */
int saisieValeur(const std::string& msg, const std::string& msgErreur, int minimum, int maximum) {
   bool valeurOk;
   int valeurSaisie;
   do {
      cout << msg << "[" << minimum << ".." << maximum << "] : ";
      //Vérification que la lecture de la valeur entrée soit valide
      //et comprise entre minimum et maximum
      valeurOk = (cin >> valeurSaisie) and valeurSaisie >= minimum and valeurSaisie <= maximum;
      if(!valeurOk)
      {
         cout << "Veuillez entrer une valeur entre " << minimum << " et " << maximum << endl;
         cin.clear();
      }
      viderBuffer();
   } while(!valeurOk);
   return valeurSaisie;
}

