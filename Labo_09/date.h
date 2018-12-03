/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_09_Date
 Fichier     : date.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 05.12.2018

 But         : Permet de gérer les saisies de dates.
               Permet de définir si les années sont bissextiles et de calculer la 
               différence de jours entre 2 dates.

 Remarque(s) : Utilisation de la libraire annexe.              

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/
#ifndef DATE_H
#define DATE_H

#include <string>
//permet de changer la valeur de SEPRATEUR_CHAR si nécessaire 
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
 * Fonction permettant de lire une date saisie par l'utilisateur dans une borne donnée en gérant les
 * erreurs de saisie.
 * @param msg string constante contenant le message à afficher lors de la saisie
 * @param msg_erreur string constante contenant le message d'erreur lors d'une saisie erronée
 * @param jour_min entier non-signé constant contenant le jour minimal pouvant être saisie
 * @param mois_min entier non-signé constant contenant le mois minimial pouvant être saisie
 * @param annee_min entier non-signé constant contenant l'année minimal pouvant être saisie
 * @param jour_max entier non-signé constant contenant le jour maximal pouvant être saisie
 * @param mois_max entier non-signé constant contenant le mois maximal pouvant être saisie
 * @param annee_max entier non-signé constant contenant l'annee maximal pouvant être saisie
 * @param jour entier non-signé contenant le jour saisie par l'utilisteur
 * @param mois entier non-signé contenant le mois saisie par l'utilisteur
 * @param annee entier non-signé contenant l'annee saisie par l'utilisteur
 */
void saisieDate(const std::string& msg,
                const std::string& msg_erreur,
                const unsigned     jour_min,
                const unsigned     mois_min,
                const unsigned     annee_min,
                const unsigned     jour_max,
                const unsigned     mois_max,
                const unsigned     annee_max,
                unsigned&          jour,
                unsigned&          mois,
                unsigned&          annee);

 /**
 * Surcharge de saisieDate en spécifiant la borne des années.
 * @param msg string constante contenant le message à afficher lors de la saisie
 * @param msg_erreur string constante contenant le message d'erreur lors d'une saisie erronée
 * @param annee_min entier non-signé constant contenant l'année minimal pouvant être saisie
 * @param annee_max entier non-signé constant contenant l'annee maximal pouvant être saisie
 * @param jour entier non-signé contenant le jour saisie par l'utilisteur
 * @param mois entier non-signé contenant le mois saisie par l'utilisteur
 * @param annee entier non-signé contenant l'annee saisie par l'utilisteur
  */
void saisieDate(const std::string& msg,
                const std::string& msg_erreur,
                const unsigned     annee_min,
                const unsigned     annee_max,
                unsigned&          jour,
                unsigned&          mois,
                unsigned&          annee);

/**
 * Surcharge de saisieDate en spécifiant la date minimale et uniquement l'année maximale
 * @param msg string constante contenant le message à afficher lors de la saisie
 * @param msg_erreur string constante contenant le message d'erreur lors d'une saisie erronée
 * @param jour_min entier non-signé constant contenant le jour minimal pouvant être saisie
 * @param mois_min entier non-signé constant contenant le mois minimial pouvant être saisie
 * @param annee_min entier non-signé constant contenant l'année minimal pouvant être saisie
 * @param annee_max entier non-signé constant contenant l'annee maximal pouvant être saisie
 * @param jour entier non-signé contenant le jour saisie par l'utilisteur
 * @param mois entier non-signé contenant le mois saisie par l'utilisteur
 * @param annee entier non-signé contenant l'annee saisie par l'utilisteur
 */
void saisieDate(const std::string& msg,
                const std::string& msg_erreur,
                const unsigned     jour_min,
                const unsigned     mois_min,
                const unsigned     annee_min,
                const unsigned     annee_max,
                unsigned&          jour,
                unsigned&          mois,
                unsigned&          annee);

/**
 * Vérifie si l'année passée en paramètre est comprise entre deux années (annee_min, annee_max)
 * @param annee entier non-signée contenant l'année à vérifier
 * @param annee_min entier non-signée contenant l'année minimale de la borne
 * @param annee_max entier non-signée contenant l'année maximale de la borne
 * @return true si l'année est dans la borne et false sinon
 */
bool anneeCorrecte(const unsigned annee,
                   const unsigned annee_min,
                   const unsigned annee_max);

/**
 * Vérifie si le mois passée en paramètre est correct
 * @param mois entier non-signé contenant le mois à vérifier
 * @return true si le mois est dans la borne (1-12) et false sinon
 */
bool moisCorrect(const unsigned mois);

/**
 * Permet de définir si le jour passé en paramètre est correct.
 * Le mois et l'année sont passés en paramètre afin de déterminer si l'année est bissexitile
 * et si le mois est Février. Dans ce cas la borne passe de 28 ou 29 au lieu de 30 ou 31.
 * @param jour entier non-signé constant contenant le jour à vérifier
 * @param mois entier non-signé constant contenant le mois
 * @param annee entier non-signé constant contenant l'annee
 * @return true si le jour est dans la borne et false sinon
 */
bool jourCorrect(const unsigned jour, const unsigned mois, const unsigned annee);

/**
 * Détermine si l'année est bissextile
 * @param annee entier non-signée constant contenant l'annee à vérifier
 * @return true si l'année est bissextile false si ce n'est pas le cas
 */
bool estBissextile(const unsigned annee);

/**
 * Calcul le nombre de jour dans un mois donné
 * @param mois entier non-signée constant contenant le mois à utiliser
 * @param annee entier non-signée constant contenant l'annee
 * @return un entier non-signée indiquant le nombre de jour dans le mois donné
 */
unsigned int nbJoursDansMois(const unsigned mois, const unsigned annee);

/**
 * Calcul le nombre de jours écoulés entre deux dates. La date de fin n'est pas incluse de sorte
 * à ce que la différence entre le 01-01-2000 et le 01-01-2000 soit de 0 jours.
 * @param jourDebut entier non-signé constant contenant le jour de départ
 * @param moisDebut entier non-signé constant contenant le mois de départ
 * @param anneeDebut entier non-signé constant contenant l'année de départ
 * @param jourFin entier non-signé constant contenant le jour de fin
 * @param moisFin entier non-signé constant contenant le mois de fin
 * @param anneeFin entier non-signé constant contenant l'année de fin
 * @return un entier non-signé représentant le nombre de jours entre deux dates
 */
unsigned nbJoursEntre(const unsigned jourDebut,
                      const unsigned moisDebut,
                      const unsigned anneeDebut,
                      const unsigned jourFin,
                      const unsigned moisFin,
                      const unsigned anneeFin);

/**
 * Calcul le nombre de jours pour une année donnée
 * @param annee entier non-signé contenant l'année à utiliser
 * @return entier non-signé indiquant le nombre de jour dans une année (365 ou 366 si bissextile)
 */
unsigned nbJoursDansAnnee(unsigned annee);

/**
 * Permet de définir le nombre de jour écoulés depuis le début d'une année donnée
 * @param jour entier non-signé contenant le jour à utiliser
 * @param mois entier non-signé contenant le mois à utiliser
 * @param annee entier non-signé contenant l'année à utiliser
 * @return un entier non-signée indiquant le nombre de jour écoulé depuis le début de l'annee
 */
unsigned nbJoursDepuisDebutAnnee(unsigned jour, unsigned mois, unsigned annee);

/**
 * Affiche la date dans le format JJ-MM-AAAA
 * @param jour entier non-signé contenant le jour à afficher
 * @param mois entier non-signé contenant le mois à afficher
 * @param annee entier non-signé contenant l'année à afficher
 */
void afficherDate(unsigned jour, unsigned mois, unsigned annee);
#endif

