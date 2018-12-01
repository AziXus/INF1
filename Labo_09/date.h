

#ifndef DATE_H
#define DATE_H

#include <string>

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
 * Fonction permettant de lire une date selon le format suivant : DD-MM-YYYY
 *
 * @param msg
 * @param msg_erreur
 * @param annee_min
 * @param annee_max
 */
void saisieDate(const std::string& msg,
                const std::string& msg_erreur,
                const unsigned     annee_min,
                const unsigned     annee_max);


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
#endif /* DATE_H */

