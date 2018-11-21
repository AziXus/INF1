/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08_Clavier
 Fichier     : annexe.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.11.2018

 But         : Gérer les fonctions d'entrées sorties du programme ainsi que des 
               fonctions particulières

 Remarque(s) : Utilisation de la fonction srand pour générer des nombres aléatoires             

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include <iostream>
#include <iomanip>
#include <limits>
#include "annexe.h" 

using namespace std;

void viderBuffer()
{
   cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

int demanderValeur(const string& message,const int& minimum, const int& maximum)
{
   bool valeurOk;
   int  valeurEntrer;
   do {
      cout << message << "[" << minimum << ".." << maximum << "] : ";
      //Vérification que la lecture de la valeur entrée soit valide
      //et comprise entre minimum et maximum
      valeurOk = (cin >> valeurEntrer) and valeurEntrer >= minimum and valeurEntrer <= maximum;
      if(!valeurOk)
      {
         cout << "Veuillez entrer une valeur entre " << minimum << " et " << maximum << endl;
         cin.clear();
      }
      viderBuffer();
   } while(!valeurOk);
   return valeurEntrer;
}

void afficherResultat(const int temps, const int reponsesCorrectes, const int lances)
{
   
   cout << fixed << setprecision(2);
   cout << "nbre de reponses correctes : "  << reponsesCorrectes << endl;
   cout << "temps ecoule               : "  << temps             << endl;
   cout << "=> " << (double) temps / lances << " sec par lettre" << endl << endl;
}

char recommencerPartieSaisie()
{
   char valeurSaisie;
   bool valeurOK;
   //boucle vérifiant que la valeur entrée soit o ou n et aucune autre valeur
   do {
       cout << "voulez vous recommencer : [o|n] : ";
       cin  >> valeurSaisie;
       if(valeurSaisie == 'o' || valeurSaisie == 'n')
       {
          valeurOK = true;
       }
       else
       {
          valeurOK = false;
          cout << "Erreur de saisie. Veuillez entrer la valeur o ou n" << endl;
       }
       viderBuffer();
   } while(!valeurOK);
   
   return valeurSaisie;
}

bool recommencerPartie()
{
    return recommencerPartieSaisie() == 'o';
}

int nombreAleatoire(const int& min, const int& max) {
    static bool premierAppel = true;

    //Initialise le generateur aléatoire avec le temps actuel comme seed lors 
    //du premier appel de la fonction
    if (premierAppel) {
        srand((unsigned int)time(NULL));
        premierAppel = !premierAppel;
    }
    //Génère un nombre aléatoire entre min et max compris
    return rand() % (max - min + 1) + min;
}