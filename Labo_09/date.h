/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_09_Date
 Fichier     : date.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 05.12.2018

 But         : Permet de gérer les saisies de dates.
               Permet de définir si les années sont bissextiles et de calculer la 
               différence de jour existant entre 2 dates

 Remarque(s) : Utilisation de la libraire annexe.              

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/
#ifndef DATE_H
#define DATE_H

#include <string>

extern char SEPARATEUR_DATE;

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
 *
 * @param msg string constante contenant le message informant sur la saisie voulu 
 * @param msg_erreur string constante contenant le message d'erreur lors d'un mauvaise saisie
 * @param jour_min entier non-signé constant contenant le jour minimal pouvant être entré
 * @param mois_min entier non-signé constant contenant le mois minimial pouvant être entré
 * @param annee_min entier non-signé constant contenant l'année minimal pouvant être entrée
 * @param jour_max entier non-signé constant contenant le jour maximal pouvant être entré
 * @param mois_max entier non-signé constant contenant le mois maximal pouvant être entré
 * @param annee_max entier non-signé constant contenant l'annee maximal pouvant être entré
 * @param jour entier non-signé contenant le jour entré par l'utilisteur
 * @param mois entier non-signé contenant le mois entré par l'utilisteur
 * @param annee entier non-signé contenant l'annee entré par l'utilisteur
 */
void saisieDate(const std::string& msg,
                const std::string& msg_erreur,
                const unsigned     annee_min,
                const unsigned     annee_max,
                const unsigned     jour_min,
                const unsigned     mois_min,                
                const unsigned     jour_max,
                const unsigned     mois_max,
                unsigned&          jour,
                unsigned&          mois,
                unsigned&          annee);

/**
 * Surcharge de saisieDate en utilisant les limites par défaut (01-01-1900 à 31-12-2200)
 * @param msg
 * @param msg_erreur
 * @param jour
 * @param mois
 * @param annee
 */
void saisieDate(const std::string& msg,
                const std::string& msg_erreur,
                unsigned&          jour,
                unsigned&          mois,
                unsigned&          annee);

/**
 * Surcharge de saisieDate en utilisant la limite maximale par défaut (31-12-2200)
 * @param msg
 * @param msg_erreur
 * @param jour_min
 * @param mois_min
 * @param annee_min
 * @param jour
 * @param mois
 * @param annee
 */
void saisieDate(const std::string& msg,
                const std::string& msg_erreur,
                const unsigned     jour_min,
                const unsigned     mois_min,
                const unsigned     annee_min,
                unsigned&          jour,
                unsigned&          mois,
                unsigned&          annee);

/**
 * Fonction vérifiant si l'annee entré par l'utilisateur est correcte
 * Comprise entre deux année(annee_min, annee_max)
 * @param annee_min entier non-signée conteant l'année minimale de la borne
 * @param annee_max entier non-signée conteant l'année maximale de la borne
 * @return true si l'année est dans la borne false dans le cas inverse
 */
bool anneeCorrecte(const unsigned annee,
                   const unsigned annee_min,
                   const unsigned annee_max);

/**
 * Permet de définir si le mois entré par l'utlisateur est correcte
 * @param mois entier non-signé contenant le mois entré par l'utilisateur
 * @return true si le mois est dans les bornes(1-12) false s'il est en dehors
 */
bool moisCorrect(const unsigned mois);

/**
 * Permet de définir si le jour entré par l'utilisateur est correct.
 * Le mois et l'année sont passés en parmaètre pour définir si l'année est bissexitile 
 * et le mois Février. Dans ce cas le borne change de 28 à 29.
 * @param jour entier non-signé constant contenant le jour entré par l'utilisateur
 * @param mois entier non-signé constant contenant le mois entré par l'utilisateur
 * @param annee entier non-signé constant contenant l'annee entrée par l'utlisateur
 * @return true si le jour est dans la borne ou false s'il ne l'est pas
 */
bool jourCorrect(const unsigned jour, const unsigned mois, const unsigned annee);

/**
 * Défini si l'année est bissextile 
 * @param annee entier non-signée constant contenant l'annee entré par l'utilisateur
 * @return true si l'année est bissextile false si ce n'est pas le cas
 */
bool estBissextile(const unsigned annee);

/**
 * Calcul le nombre de jour dans un mois indiqué
 * @param mois entier non-signée constant contenant le mois entre par l'utilisteur
 * @param annee entier non-signée constant contenant l'annee entrée par l'utilisateur
 * @return un entier non-signée indiquant le nombre de jour dans le mois passé en paramètre
 */
unsigned int nbJoursDansMois(const unsigned mois, const unsigned annee);

/**
 * 
 * @param jourDebut
 * @param moisDebut
 * @param anneeDebut
 * @param jourFin
 * @param moisFin
 * @param anneeFin
 * @return 
 */
unsigned nombreJourEntre(const unsigned jourDebut,
                         const unsigned moisDebut,
                         const unsigned anneeDebut,
                         const unsigned jourFin,
                         const unsigned moisFin,
                         const unsigned anneeFin);

//internet formula
//source: https://stackoverflow.com/a/12863278
int g(int d, int m, int y);

/**
 * Permet de définir le nombre de jour dans une année 365 ou 366 si bissextile
 * @param annee entier non-signé contenant l'année entrée par l'utilisateur
 * @return entier non-signé indiquant le nombre de jour dans une année 
 */
unsigned nbJoursDansAnnee(unsigned annee);

/**
 * Permet de définir le nombre de jour écoulés depuis le début d'une année
 * @param jour entier non-signé contenant le jour entré par l'utilisteur
 * @param mois entier non-signé contenant le mois entré par l'utilisteur
 * @param annee entier non-signé contenant l'année entré par l'utilisteur
 * @return  un eiter non-signée inidqiant le nombre de jour écoulé depuis le début de l'annee
 */
unsigned nbJoursDepuisDebutAnnee(unsigned jour, unsigned mois, unsigned annee);

/**
 * 
 * @param jour
 * @param mois
 * @param annee
 */
void afficherDate(unsigned jour, unsigned mois, unsigned annee);
#endif /* DATE_H */

