/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_09_Date
 Fichier     : date.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 05.12.2018

 But         : Permet de gérer les saisies de dates et de vérifier la validité des dates.
               Permet de déterminer si les années sont bissextiles et de calculer la
               différence de jours entre 2 dates.

 Remarque(s) : Utilisation de la libraire annexe.
               Les dates sont stockées dans un tableau d'entiers non-signés de taille
               minimum de 3 avec en position 0 le jour, en position 1 le mois 
               et en position 2 l'année.
               Utilisation de la fonction Substring(substr) et StringToInt(stoi) car
               cela a été autorisé pour ce labo.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/
#ifndef DATE_H
#define DATE_H

#include <string>

//La valeur de SEPARATEUR_CHAR peut être changé, sa valeur par défaut est '-'
extern char SEPARATEUR_DATE;

//Index de l'emplacement de jour, mois, année dans les tableaux de dates.
//La position 0 est le jour, la position 1 le mois et la position 2 l'année.
const unsigned INDEX_JOUR  = 0,
               INDEX_MOIS  = 1,
               INDEX_ANNEE = 2;

//Défini les numéros des mois. Les mois ont tous été définis afin de pouvoir réutiliser 
//l'enum dans d'autres programmes.
enum Mois {
    Janvier = 1,
    Fevrier,
    Mars,
    Avril,
    Mai,
    Juin,
    Juillet,
    Aout,
    Septembre,
    Octobre,
    Novembre,
    Decembre
};

/**
 * Fonction permettant de lire une date saisie par l'utilisateur dans une borne donnée en gérant les
 * erreurs de saisie.
 * @param msg string constante contenant le message à afficher lors de la saisie
 * @param msgErreur string constante contenant le message d'erreur lors d'une saisie erronée
 * @param dateMin tableau d'entiers non-signés contenant la date minimale pouvant être saisie
 * @param dateMax tableau d'entiers non-signés contenant la date maximale pouvant être saisie
 * @param dateSaisie tableau d'entiers non-signés qui va contenir la date saisie
 */
void saisieDate(const std::string& msg,
                const std::string& msgErreur,
                const unsigned     dateMin[],
                const unsigned     dateMax[],
                unsigned           dateSaisie[]);

 /**
 * Surcharge de saisieDate en spécifiant la date minimale et l'année maximale (31-12-AAAA).
 * @param msg string constante contenant le message à afficher lors de la saisie
 * @param msgErreur string constante contenant le message d'erreur lors d'une saisie erronée
 * @param dateMin tableau d'entiers non-signés contenant la date minimale pouvant être saisie
 * @param anneeMax entier non-signé contenant l'année maximale pouvant être saisie
 * @param dateSaisie tableau d'entiers non-signés qui va contenir la date saisie
 */
 void saisieDate(const std::string& msg,
                 const std::string& msgErreur,
                 const unsigned     dateMin[],
                 unsigned           anneeMax,
                 unsigned           dateSaisie[]);

/**
* Surcharge de saisieDate en spécifiant uniquement l'année minimale (01-01-AAAA) et l'année maximale (31-12-AAAA).
* @param msg string constante contenant le message à afficher lors de la saisie
* @param msgErreur string constante contenant le message d'erreur lors d'une saisie erronée
* @param anneeMin entier non-signé contenant l'annee minimale pouvant être saisie
* @param anneeMax entier non-signé contenant l'annee maximale pouvant être saisie
* @param dateSaisie tableau d'entiers non-signés qui va contenir la date saisie
*/
void saisieDate(const std::string& msg,
                const std::string& msgErreur,
                unsigned           anneeMin,
                unsigned           anneeMax,
                unsigned           dateSaisie[]);

/**
 * Fonction vérifiant si la date en paramètre se situe dans une intervalle (dateMin et dateMax)
 * @param date tableau d'entiers non-signés contenant la date à vérifier
 * @param dateMin tableau d'entiers non-signés contenant la date minimale
 * @param dateMax tableau d'entiers non-signés contenant la date maximale
 * @return true si la date est dans l'intervalle, false sinon
 */
bool dateDansBorne(const unsigned date[], const unsigned dateMin[], const unsigned dateMax[]);

/**
 * Vérifie si le mois passée en paramètre est correct
 * @param mois entier non-signé contenant le mois à vérifier
 * @return true si le mois est dans la borne (1-12) et false sinon
 */
bool moisCorrect(unsigned mois);

/**
 * Permet de définir si le jour contenu dans date est correct.
 * La date complète est passée en paramètre afin de déterminer si l'année est bissexitile ou non,
 * et si le mois est Février. Dans ce cas la borne a pour maximum 28 ou 29 au lieu de 30 ou 31.
 * @param date tableau d'entiers non-signés contenant la date à vérifier
 * @return true si le jour est valide et false sinon
 */
bool jourCorrect(const unsigned date[]);

/**
 * Place les valeurs en paramètre dans un tableau nommé date
 * @param jour entier non-signé représentant un jour
 * @param mois entier non-signé représentant un mois
 * @param annee entier non-signé représentant une année
 * @param date tableau d'entiers non-signés qui va contenir la date
 */
void creerTableauDate(unsigned jour, unsigned mois, unsigned annee, unsigned date[]);

/**
 * Détermine si l'année est bissextile
 * @param annee entier non-signée contenant l'année à vérifier
 * @return true si l'année est bissextile false si ce n'est pas le cas
 */
bool estBissextile(unsigned annee);

/**
 * Calcul le nombre de jour dans un mois donné
 * @param mois entier non-signée contenant le mois
 * @param annee entier non-signée contenant l'annee
 * @return un entier non-signée indiquant le nombre de jour dans le mois donné
 */
unsigned int nbJoursDansMois(unsigned mois, unsigned annee);

/**
 * Calcul le nombre de jours pour une année donnée
 * @param annee entier non-signé contenant l'année à utiliser
 * @return entier non-signé indiquant le nombre de jour dans une année (365 ou 366 si bissextile)
 */
unsigned nbJoursDansAnnee(unsigned int annee);

/**
 * Permet de calculer le nombre de jour écoulés depuis le début d'une année donnée
 * @param date tableau d'entiers non-signés contenant la date à utiliser
 * @return un entier non-signée indiquant le nombre de jour écoulé depuis le début de l'année
 */
unsigned nbJoursDepuisDebutAnnee(const unsigned date[]);

/**
 * Calcul le nombre de jours écoulés entre deux dates. Si les deux dates sont égales,
 * la différence est de 0 jour.
 * @param dateDebut tableau d'entiers non-signés contenant la date de début pouvant être saisie
 * @param dateFin tableau d'entiers non-signés contenant la date de fin pouvant être saisie
 * @return un entier non-signé représentant le nombre de jours séparant deux dates
 */
unsigned nbJoursEntre(const unsigned dateDebut[], const unsigned dateFin[]);

/**
 * Affiche la date dans le format JJ-MM-AAAA
 * @param date tableau d'entiers non-signés contenant la date à afficher
 * @param carRemplissage caractère de remplissage pour la fonction setfill et setw (valeur par défaut '0')
 * @param tailleJour entier signé représentant la taille à réserver pour l'affichage du jour (valeur par défaut 2)
 * @param tailleMois entier signé représentant la taille à réserver pour l'affichage du mois (valeur par défaut 2)
 * @param tailleAnnee entier signé représentant la taille à réserver pour l'affichage de l'année (valeur par défaut 4)
 */
void afficherDate(const unsigned date[],
                  char           carRemplissage = '0',
                  int            tailleJour     =  2,
                  int            tailleMois     =  2,
                  int            tailleAnnee    =  4);

#endif