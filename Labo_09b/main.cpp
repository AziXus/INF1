/*
 -----------------------------------------------------------------------------------
 Laboratoire   : Labo09b
 Fichier       : main.cpp
 Auteur(s)     : Mohamed El-Sheikh et Gaetan Daubresse

 Modifié par   : Robin Müller, Stéphane Teixeira Carvalho
 Date          : 11.12.2018

 But           : Programme qui calcule et affiche le nombre de jour entre deux dates.
                 Les dates sont au format JJ-MM-AAAA. Apres la saisie de la 2 eme date
                 le programme affiche le nombre de jours separant ces deux dates.

 Remarque(s)   : le programme gere les erreurs de saisies (date au mauvais format
                 ou date pas dans les bornes), il affiche un message d'erreur et
                 l'utilisateur doit saisir une nouvelle fois les dates.

 Modifications : Ajout de la fonctionnalité permettant de calculer une nouvelle date
                 en ajoutant ou soustrayant un nombre de jour à une date donnée.

 Compilateur   : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */


#include <cstdlib>              
#include <iostream>
#include <string>
#include "annexe.h"
#include "traitementDate.h"
#include "format.h"

using namespace std;

//Fonctionnalité permettant de calculer un nombre de jours entre deux dates (Labo_09)
void calculJoursEntreDates(const string& MESSAGE_DATE,   const string& MESSAGE_DATE2,
                           const string& MESSAGE_ERREUR, const string& MESSAGE_RESULTAT,
                           const int     JOUR_MIN,       const int     MOIS_MIN,
                           const int     ANNEE_MIN,      const int     JOUR_MAX,
                           const int     MOIS_MAX,       const int     ANNEE_MAX);

//Fonctionnalité permettant d'ajouter ou soustraire un nombre de jours à une date (Labo_09b)
void ajouterJoursADate(const string& MSG_DATE,   const string& MSG_JOURS,
                       const string& MSG_ERREUR, const int     JOUR_MIN,
                       const int     MOIS_MIN,   const int     ANNEE_MIN,
                       const int     JOUR_MAX,   const int     MOIS_MAX,
                       const int     ANNEE_MAX);

int main() {
   const string   MESSAGE_CHOIX_FONCTION = "Veuillez entrer\n1) pour additionner/soustraire un nombre de jours à une date, "
                                           "2) pour calculer la différence de jours entre deux dates ",
                  MESSAGE_SAISIE_DATE    = "Veuillez saisir une date : ",
                  MESSAGE_SAISIE_JOURS   = "Veuillez entrez un nombre de jour à additioner/soustraire ",
                  MESSAGE_SAISIE_DATE_2  = "Veuillez saisir la 2 eme date : ",
                  MESSAGE_RESULTAT       = "Nombre de jour separant les deux dates : ",
                  MESSAGE_ERREUR         = "Erreur dans la saisie",
                  MESSAGE_RECOMMENCER    = "Voulez-vous recommencer ? ",
                  MESSAGE_FIN_PROGRAMME  = "Fin du programme, appuyer sur une touche pour quitter";
           
   const char     FONCTION_CALCULER_DATE  = '1',
                  FONCTION_CALCULER_JOURS = '2';

   const int      JOUR_MIN  = 1,
                  MOIS_MIN  = 1,
                  ANNEE_MIN = 1600; //changé pour le Labo_09b
   
   const int      JOUR_MAX  = 31,
                  MOIS_MAX  = 12,
                  ANNEE_MAX = 2200;

   do {
      //Demande à l'utilisateur quelle fonctionnalité lancer
      if (repondsQuestion(MESSAGE_CHOIX_FONCTION, FONCTION_CALCULER_DATE, FONCTION_CALCULER_JOURS))
         ajouterJoursADate(MESSAGE_SAISIE_DATE, MESSAGE_SAISIE_JOURS, MESSAGE_ERREUR, JOUR_MIN, MOIS_MIN, ANNEE_MIN, JOUR_MAX, MOIS_MAX, ANNEE_MAX);
      else
         calculJoursEntreDates(MESSAGE_SAISIE_DATE, MESSAGE_SAISIE_DATE_2, MESSAGE_ERREUR, MESSAGE_RESULTAT, JOUR_MIN, MOIS_MIN, ANNEE_MIN, JOUR_MAX, MOIS_MAX, ANNEE_MAX);
   } while(repondsQuestion(MESSAGE_RECOMMENCER)); //On demande à l'utilisateur s'il veut recommencer

  afficherMessageFin(MESSAGE_FIN_PROGRAMME);
  return EXIT_SUCCESS; 
}

void calculJoursEntreDates(const string& MESSAGE_DATE, const string& MESSAGE_DATE2,
                 const string& MESSAGE_ERREUR, const string& MESSAGE_RESULTAT,
                 const int     JOUR_MIN,       const int     MOIS_MIN,
                 const int     ANNEE_MIN,      const int     JOUR_MAX,
                 const int     MOIS_MAX,       const int     ANNEE_MAX) {

   int jour1, mois1, annee1;

   int jour2, mois2, annee2; 
   
   unsigned int nbrJour; 
   
   
   bool erreurDate;
      //On boucle tant que la 2 eme date est inferieur ou egal a la 1 ere 
      do {
         saisie(MESSAGE_DATE, MESSAGE_ERREUR, jour1, mois1, annee1, JOUR_MIN, MOIS_MIN, ANNEE_MIN, JOUR_MAX, MOIS_MAX, ANNEE_MAX);
         saisie(MESSAGE_DATE2, MESSAGE_ERREUR, jour2, mois2, annee2, JOUR_MIN, MOIS_MIN, ANNEE_MIN, JOUR_MAX, MOIS_MAX, ANNEE_MAX);
         erreurDate = date1AntDate2(jour2, jour1, mois2, mois1, annee2, annee1); 
         if(erreurDate){
            cout << MESSAGE_ERREUR << endl; 
         }
      } while(erreurDate);
      
      //On incremente la variable nbrJour
      nbrJour = calculNombreJour(jour1, jour2, mois1, mois2, annee1, annee2); 
      
      //On affiche le resultat
      cout << MESSAGE_RESULTAT << nbrJour << endl << endl;
}

void ajouterJoursADate(const string& MSG_DATE,   const string& MSG_JOURS,
                       const string& MSG_ERREUR, const int     JOUR_MIN,
                       const int     MOIS_MIN,   const int     ANNEE_MIN,
                       const int     JOUR_MAX,   const int     MOIS_MAX,
                       const int     ANNEE_MAX) {
   int jour, mois, annee, nbJoursMax;
   int nbrJour;
   bool dateValide;

   nbJoursMax = calculNombreJour(JOUR_MIN, JOUR_MAX, MOIS_MIN, MOIS_MAX, ANNEE_MIN, ANNEE_MAX);

   //On boucle tant que la 2 eme date est inferieur ou egal a la 1 ere
   saisie(MSG_DATE, MSG_ERREUR, jour, mois, annee, JOUR_MIN, MOIS_MIN, ANNEE_MIN, JOUR_MAX, MOIS_MAX, ANNEE_MAX);
   nbrJour = saisieValeur(MSG_JOURS, MSG_ERREUR, -nbJoursMax, nbJoursMax);

   dateValide = ajouteJourADate(nbrJour, jour, mois, annee, JOUR_MIN, MOIS_MIN, ANNEE_MIN, JOUR_MAX, MOIS_MAX, ANNEE_MAX);

   if(!dateValide){
      cout << MSG_ERREUR << endl;
   } else {
      cout << jour << "-" << mois << "-" << annee << endl;
   }
}

