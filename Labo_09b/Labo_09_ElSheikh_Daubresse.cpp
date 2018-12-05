/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo09
 Fichier     : Labo_09_ElSheikh_Daubresse.cpp
 Auteur(s)   : Mohamed El-Sheikh et Gaetan Daubresse 
 Date        : 04.12.2018

 But         : Programme qui calcule et affiche le nombre de jour entre deux dates. 
               Les dates sont au format JJ-MM-AAAA. Apres la saisie de la 2 eme date
               le programme affiche le nombre de jours separant ces deux dates.    

 Remarque(s) : le programme gere les erreurs de saisies (date au mauvais format
               ou date pas dans les bornes), il affiche un message d'erreur et 
               l'utilisateur doit saisir une nouvelle fois les dates. 

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */


#include <cstdlib>              
#include <iostream>
#include <string>
#include "annexe.h"
#include "traitementDate.h"
#include "format.h"

using namespace std;

void calcul2date();
void calculjour();

int main() {
   const string   MESSAGE_SAISIE1   = "Veuillez saisir la 1 ere date : ",  
                  MESSAGE_SAISIE2   = "Veuillez saisir la 2 eme date : ", 
                  MESSAGE_RESULTAT  = "Nombre de jour separant les deux dates : ",
                  MESSAGE_ERREUR    = "Erreur dans la saisie", 
                  MESSAGE_RECOMMENCER = "Voulez-vous recommencer ? ",
                  MESSAGE_FIN_PROGRAMME = "Fin du programme, appuyer sur une touche pour quitter";
           
   const char     OUI = 'o', 
                  NON = 'n'; 
   
   const int      JOUR_MIN = 1,
                  MOIS_MIN = 1, 
                  ANNEE_MIN = 1600;//changé pour l'exercice 
   
   const int      JOUR_MAX = 31, 
                  MOIS_MAX = 12, 
                  ANNEE_MAX = 2200;  
   do{
      
   }while(recommencer(OUI, NON, MESSAGE_RECOMMENCER)); //On demande à l'utilisateur s'il veut recommencer
   
  afficherMessageFin(MESSAGE_FIN_PROGRAMME);
   return EXIT_SUCCESS; 
}
void calcul2date(const string& MESSAGE_SAISIE1,const string& MESSAGE_SAISIE2, const string& MESSAGE_ERREUR,const string& MESSAGE_RESULTAT, const int JOUR_MIN, const int MOIS_MIN,const int ANNEE_MIN
                 ,const int JOUR_MAX, const int MOIS_MAX,  const int ANNEE_MAX)
{
    int jour1, mois1, annee1; 
   
   int jour2, mois2, annee2; 
   
   unsigned int nbrJour; 
   
   
   bool erreurDate;
    //On boucle tant que la 2 eme date est inferieur ou egal a la 1 ere 
      do{
         saisie(MESSAGE_SAISIE1, MESSAGE_ERREUR, jour1, mois1, annee1, JOUR_MIN, MOIS_MIN, ANNEE_MIN, JOUR_MAX, MOIS_MAX, ANNEE_MAX);
         saisie(MESSAGE_SAISIE2, MESSAGE_ERREUR, jour2, mois2, annee2, JOUR_MIN, MOIS_MIN, ANNEE_MIN, JOUR_MAX, MOIS_MAX, ANNEE_MAX);
         erreurDate = date1AntDate2(jour2, jour1, mois2, mois1, annee2, annee1); 
         if(erreurDate){
            cout << MESSAGE_ERREUR << endl; 
         }
      }while(erreurDate); 
      
      //On incremente la variable nbrJour
      nbrJour = calculNombreJour(jour1, jour2, mois1, mois2, annee1, annee2); 
      
      //On affiche le resultat
      cout << MESSAGE_RESULTAT << nbrJour << endl << endl;
}
void calculjour(const string& MESSAGE_SAISIE1,const string& MESSAGE_SAISIE2, const string& MESSAGE_ERREUR,const string& MESSAGE_RESULTAT, const int JOUR_MIN, const int MOIS_MIN,const int ANNEE_MIN
                 ,const int JOUR_MAX, const int MOIS_MAX,  const int ANNEE_MAX)
{
   int jour1, mois1, annee1; 
   
   int jour2, mois2, annee2; 
   
   unsigned int nbrJour = 10;
   
   
   bool erreurDate;
    //On boucle tant que la 2 eme date est inferieur ou egal a la 1 ere 
      do{
         saisie(MESSAGE_SAISIE1, MESSAGE_ERREUR, jour1, mois1, annee1, JOUR_MIN, MOIS_MIN, ANNEE_MIN, JOUR_MAX, MOIS_MAX, ANNEE_MAX);
         
         if(ajouteJourADate(jour1, mois1, annee1, nbrJour)){
            cout << MESSAGE_ERREUR << endl; 
         }
      }while(erreurDate); 
      
      //On incremente la variable nbrJour
      nbrJour = calculNombreJour(jour1, jour2, mois1, mois2, annee1, annee2); 
    
    
}

