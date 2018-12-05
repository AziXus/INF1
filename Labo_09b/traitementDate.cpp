#include "format.h"
#include "annexe.h"
#include "traitementDate.h"


using namespace std;


int nbrJoursMois(int mois, int annee){
   int nbrJours; 
   // Si le mois est février on vérifie si l'année est bissextile et on incémente 
   // la variable nbrJour. 
   if (mois == 2){
      
      //On attribue le nombre de jour en fonction de l'année bissexile. 
      if(bissextile(annee)){
         nbrJours = 29;
      }
      else{
         nbrJours = 28; 
      }
   }
   // On sait que jusqu'à juillet les mois impair comptent 31 jours et les pairs 30,
   // hormis février.
   else if (mois <= 7){
      if(mois % 2 == 0){
         nbrJours = 30;
      }
      else{
         nbrJours = 31;
      }
   }
   // A partir d'août les mois impairs compte 30 jours et les pairs 31
   else{
      if(mois % 2 == 0){
         nbrJours = 31;
      }
      else{
         nbrJours = 30;
      }
   }
   return nbrJours; 
}
//fonction permettant de verifier si une annee est bissextile ou non
bool bissextile (int annee){
   return (annee % 400 == 0 || (annee % 4 == 0 && annee % 100 != 0)); 
}

//Fonction qui permet de calculer le nombre de jours entre 2 dates
int calculNombreJour(int jour1, int jour2, int mois1, int mois2,  int annee1, int annee2){
    
      const int JANVIER = 1,
                DECEMBRE = 12;
    
   unsigned int nbJoursTotal = 0;
    
   //condition permettant de vérifier si le programme doit juste calculer le nombre de jour entre 2 date du mêmme mois et de la même année
   if(annee1 == annee2 && mois1 == mois2)
   {
      nbJoursTotal = jour2 - jour1;
   }
   else
   {
      //calcul du nombre de jour dans l'intervale des mois non finis
      nbJoursTotal = nbrJoursMois(mois1, annee1) - jour1 + jour2;
      mois1++;
      //calcul du nombre jours total dans l'interval des mois entiers
      while(mois1 != mois2 || annee1 != annee2)
            {  
             nbJoursTotal += nbrJoursMois(mois1, annee1); 
             if(mois1 == DECEMBRE)
             {
                mois1 = JANVIER;
                annee1++;
             }
             else
             {
                mois1++;
             }
           }
   } 
   return nbJoursTotal;
}

//Ajout suite à la demande
bool ajouteJourADate(int& jour, int& mois, int& annee, int nbJour)
{
    if(!dateExistante(jour,mois,annee))
    {
      return false; 
    }
    
    int increment = nbJour < 0 ? -1 : 1;//si le nombre de jour est négatif on décremente
    
    for(int i = abs(nbJour); i >= 0; i--)
    {
        jour += increment;
        //dépassement du jour
        if(!dateExistante(jour,mois,annee))
        {
            jour = nbJour < 0 ? 31 : 1;
            mois += increment;
        }
        //dépassement du mois
        if(!dateExistante(jour,mois,annee))
        {
            mois = nbJour < 0 ? 12 : 1;
            annee += increment;
        }
        //depassement de l'année
        if(!dateExistante(jour,mois,annee))
        {
            return false;
        }
    }
    return true;
}
