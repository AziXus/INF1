

#ifndef DATE_H
#define DATE_H

#include <string>

static unsigned JOUR_MIN =  1,
                JOUR_MAX = 31,
                MOIS_MIN =  1,
                MOIS_MAX = 12;

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
bool moisCorrect(const unsigned int mois);

/**
 *
 * @param jour
 * @return
 */
bool jourCorrect(const unsigned int jour);

/**
 *
 * @param annee
 * @return
 */
bool estBissextile(const unsigned int annee);

#endif /* DATE_H */

