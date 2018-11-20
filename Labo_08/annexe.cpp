#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <limits>
#include "annexe.h" 

using namespace std;
/**
 * Fonction permettant de vider le buffer
 */
void viderBuffer()
{
   cin.ignore(numeric_limits<streamsize>::max(),'\n');
}
/**
 * Vérification d'une saisie pour que la valeur entrée par l'utilisateur soit correcte
 * @param message 
 * @param minimum
 * @param maximum
 * @return 
 */
int demanderValeur(const string& message,const int& minimum, const int& maximum)
{
   bool valeurOk;
   int  valeurEntrer;
   do {
      cout << message << "[" << minimum << ".." << maximum << "] : ";
      //Vérification que la valeur saisie soit correcte(convertible en entier)
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

//Affichage du résultat de la partie
void afficherResultat(const int temps, const int reponsesCorrectes, const int lances)
{
   cout << fixed << setprecision(2);
   cout << "nbre de reponses correctes : "  << reponsesCorrectes << endl;
   cout << "temps ecoule               : "  << temps             << endl;
   cout << "=> " << (double) temps / lances << " sec par lettre" << endl;
}

//Vérification que l'utilisateur entre une saisie correcte pour le recommencemnt de la partie(o ou n)
char recommencerPartieSaisie()
{
   char valeurSaisie;
   bool valeurOK;
   
   do{
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
   }while(!valeurOK);
   
   return valeurSaisie;
}

//Permet de définir si la partie devra être recommencée ou non
bool recommencerPartie()
{
    return recommencerPartieSaisie() == 'o';
}


int nombreAleatoire(const int& min, const int& max) {
    static bool premierAppel = true;

    //Initialise le generateur aleatoire avec le temps actuel comme seed lors du premier appel
    if (premierAppel) {
        srand((unsigned int)time(NULL));
        premierAppel = !premierAppel;
    }

    return rand() % (max - min + 1) + min;
}