

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
 * @param msg
 * @param msg_erreur
 * @param jour_min
 * @param mois_min
 * @param annee_min
 * @param jour_max
 * @param mois_max
 * @param annee_max
 * @param jour
 * @param mois
 * @param annee
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
 *
 * Fonction vérifiant si une année
 *
 * @param annee_min
 * @param annee_max
 * @return
 */
bool anneeCorrecte(const unsigned annee,
                   const unsigned annee_min,
                   const unsigned annee_max);

/**
 *
 * Vléfm
 *
 * @param mois
 * @return
 */
bool moisCorrect(const unsigned mois);

/**
 *
 * @param jour
 * @return
 */
bool jourCorrect(const unsigned jour, const unsigned mois, const unsigned annee);

/**
 *
 * @param annee
 * @return
 */
bool estBissextile(const unsigned annee);

/**
 *
 * @param mois
 * @param annee
 * @return
 */
unsigned int nbJoursDansMois(const unsigned mois, const unsigned annee);

unsigned nombreJourEntre(const unsigned jourDebut,
                         const unsigned moisDebut,
                         const unsigned anneeDebut,
                         const unsigned jourFin,
                         const unsigned moisFin,
                         const unsigned anneeFin);

//internet formula
//source: https://stackoverflow.com/a/12863278
int g(int d, int m, int y);

unsigned nbJoursDansAnnee(unsigned annee);

unsigned nbJoursDepuisDebutAnnee(unsigned jour, unsigned mois, unsigned annee);

void printDate(unsigned jour, unsigned mois, unsigned annee);
#endif /* DATE_H */

