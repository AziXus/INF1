
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
