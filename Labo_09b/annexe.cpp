#include <iostream>
#include <string>
#include "annexe.h"

using namespace std;

// fonction permettant à l'utilisateur de recommence le programme
bool repondsQuestion(const string& message, char oui, char non) {
   char recommencer; 
   do{
      cout << message << "[" << oui << "-" << non << "]";
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

int saisieValeur(const string& msg, const string& msgErreur, int minimum, int maximum) {
   bool valeurOk;
   int valeurSaisie;
   do {
      cout << msg << "[" << minimum << ".." << maximum << "] : ";
      //Vérification que la lecture de la valeur entrée soit valide
      //et comprise entre minimum et maximum
      valeurOk = (cin >> valeurSaisie) and valeurSaisie >= minimum and valeurSaisie <= maximum;
      if(!valeurOk)
      {
         cout << msgErreur;
         cin.clear();
      }
      viderBuffer();
   } while(!valeurOk);
   return valeurSaisie;
}

