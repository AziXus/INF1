
#include <iostream>
#include <string>
#include <cmath>
#include "format.h"
#include "annexe.h"
#include "traitementDate.h"


using namespace std;

//la fonction enregistre une date au format JJ-MM-AAAA
//et l'affecte à trois int jours, mois et annee
void saisie(const string& messSaisie, const string& messErreur, int& jour, int& mois, int& annee, 
        const int jourMin, const int moisMin, const int anneeMin, const int jourMax, const int moisMax, const int anneeMax){
   bool dateOk; 
   do{
      bool saisieOk; 
      string saisie;
      do{
         saisie = ""; 
         cout << messSaisie; 
         cin >> saisie;
         saisieOk = controleSaisie(saisie);
         if(!saisieOk or cin.fail()){
            cin.clear(); 
            cout << messErreur << endl;  
            saisieOk = false; 
         }
         viderBuffer(); 
      }while(!saisieOk);
   
   
      jour = stoi(saisie.substr(0,2));
      mois = stoi(saisie.substr(3,2));
      annee = stoi(saisie.substr(6,4));
      
      dateOk = controleDate(jour, mois, annee, jourMin, moisMin, anneeMin, jourMax, moisMax, anneeMax);
      if(!dateOk){
         cout << messErreur << endl; 
      }
   }while(!dateOk); 
   
}

//Controle le format JJ-MM-AAAA
bool controleSaisie(string saisie){
   
   const char SEPARATION = '-',
       BORNE_CHIFFRE_MIN = '0',
       BORNE_CHIFFRE_MAX = '9';
    
   bool formatOk = saisie[2] == SEPARATION or saisie[5] == SEPARATION; 
         
   bool decimalOk =    ((BORNE_CHIFFRE_MAX >= saisie[0] and saisie[0] >= BORNE_CHIFFRE_MIN) and 
                        (BORNE_CHIFFRE_MAX >= saisie[1] and saisie[1] >= BORNE_CHIFFRE_MIN) and 
                        (BORNE_CHIFFRE_MAX >= saisie[3] and saisie[3] >= BORNE_CHIFFRE_MIN) and 
                        (BORNE_CHIFFRE_MAX >= saisie[4] and saisie[4] >= BORNE_CHIFFRE_MIN) and 
                        (BORNE_CHIFFRE_MAX >= saisie[6] and saisie[6] >= BORNE_CHIFFRE_MIN) and 
                        (BORNE_CHIFFRE_MAX >= saisie[7] and saisie[7] >= BORNE_CHIFFRE_MIN) and 
                        (BORNE_CHIFFRE_MAX >= saisie[8] and saisie[8] >= BORNE_CHIFFRE_MIN) and 
                        (BORNE_CHIFFRE_MAX >= saisie[9] and saisie[9] >= BORNE_CHIFFRE_MIN)); 
  
   return (formatOk and decimalOk);
}

//on verifie que la date saisie est dans les bornes et qu'elle existe 
bool controleDate(int jour, int mois, int annee, const int jourMin, const int moisMin, 
				  const int anneeMin, const int jourMax, const int moisMax, const int anneeMax){
					
   return (date1AntDate2(jourMin, jour, moisMin, mois, anneeMin, annee) and date1AntDate2(jour, jourMax, mois, moisMax, annee, anneeMax)
           and dateExistante(jour, mois, annee)); 
}

//Verifie si la date existe
//Ajour jour >= 1, mois >= 1
bool dateExistante(int jour, int mois, int annee){
   return (jour >= 1 and jour <= nbrJoursMois(mois, annee) and mois >= 1 and mois <=12);
}

//renvoie true si la date 1 est anterieur a la date 2
bool date1AntDate2(int jour1, int jour2, int mois1, int mois2, int annee1, int annee2){
   return ((annee1<annee2) or (annee1==annee2 and mois1 <= mois2 and jour1 <= jour2)); 
}

