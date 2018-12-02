#include "date.h"
#include "annexe.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;
//global car nécessaire... question
char SEPARATEUR_DATE = '-';

//static unsigned permettant de mettre des valeurs par défaut
static unsigned JOUR_MIN      =    1,
                JOUR_MAX      =   31,
                MOIS_MIN      =    1,
                MOIS_MAX      =   12,
                JOURS_FEVRIER =   28,
                JOURS_ANNEE   =  365;

void saisieDate(const string&  msg,
                const string&  msg_erreur,
                const unsigned annee_min,
                const unsigned annee_max,
                unsigned&      jour,
                unsigned&      mois,
                unsigned&      annee) {
    saisieDate(msg, msg_erreur, JOUR_MIN, MOIS_MIN, annee_min, JOUR_MAX, MOIS_MAX, annee_max, jour, mois, annee);
}

void saisieDate(const string&  msg,
                const string&  msg_erreur,
                const unsigned jour_min,
                const unsigned mois_min,
                const unsigned annee_min,
                const unsigned annee_max,
                unsigned&      jour,
                unsigned&      mois,
                unsigned&      annee) {
    saisieDate(msg, msg_erreur, jour_min, mois_min, annee_min, JOUR_MAX, MOIS_MAX, annee_max, jour, mois, annee);
}

void saisieDate(const string&  msg,
                const string&  msg_erreur,
                const unsigned jour_min,
                const unsigned mois_min,
                const unsigned annee_min,
                const unsigned jour_max,
                const unsigned mois_max,
                const unsigned annee_max,
                unsigned&      jour,
                unsigned&      mois,
                unsigned&      annee) {

    bool valeurOk;

    do {
        //On assume qu'il n'y a pas d'erreur en début de boucle
        valeurOk = true;

        //Message de saisie
        cout << msg;
        afficherDate(jour_min, mois_min, annee_min);
        cout << " et le ";
        afficherDate(jour_max, mois_max, annee_max);
        cout << " : ";

        //Lecture du jour
        //Essaie de lire la date et s'arrête à la première erreur.
        //les cin.get vide les SEPARATEUR_DATE du buffer 
        //si SEPARATEUR_DATE = '-' on va supprimer le '-'
        valeurOk = cin >> jour and cin.get() == SEPARATEUR_DATE and cin >> mois and cin.get() == SEPARATEUR_DATE and cin >> annee;

        if (!valeurOk) {
            cin.clear();
        }
        viderBuffer();

        //Vérification des saisies
        if(!valeurOk or !anneeCorrecte(annee, annee_min, annee_max) or !moisCorrect(mois) or !jourCorrect(jour, mois, annee))
        {
            cout << msg_erreur << endl;
            valeurOk = false;
        }
    } while(!valeurOk);
}


bool anneeCorrecte(const unsigned annee,
                   const unsigned annee_min,
                   const unsigned annee_max){
    return annee >= annee_min and annee <= annee_max;
}

bool moisCorrect(const unsigned mois){
    return mois >= MOIS_MIN and mois <= MOIS_MAX;
}

bool jourCorrect(const unsigned jour, const unsigned mois, const unsigned annee) {
    return jour >= JOUR_MIN and jour <= nbJoursDansMois(mois, annee);
}

bool estBissextile(const unsigned annee) {
    return annee % 400 == 0 or (annee % 4 == 0 and annee % 100 != 0);
}

unsigned int nbJoursDansMois(const unsigned mois, const unsigned annee) {
    unsigned int nbJours;

    if (mois == Mois::Fevrier) {
        nbJours = JOURS_FEVRIER + estBissextile(annee);
    } else {
        nbJours = JOUR_MAX - (mois - 1) % 7 % 2;
    }

    return nbJours;
}

unsigned nbJoursEntre(const unsigned jourDebut,
                      const unsigned moisDebut,
                      const unsigned anneeDebut,
                      const unsigned jourFin,
                      const unsigned moisFin,
                      const unsigned anneeFin) {
    unsigned nbJoursAnneeDebut,
             nbJoursAnneeFin,
             nbJours;

    //Calcul le nombre de jours de la date départ jusqu'à la fin de l'année de départ non-compris
    nbJoursAnneeDebut = nbJoursDansAnnee(anneeDebut) - nbJoursDepuisDebutAnnee(jourDebut, moisDebut, anneeDebut);

    //Calcul le nombre de jours du début de la dernière année à la date de fin compris
    nbJoursAnneeFin   = nbJoursDepuisDebutAnnee(jourFin, moisFin, anneeFin);

    nbJours = nbJoursAnneeDebut + nbJoursAnneeFin;
    //Boucle de l'annee de debut + 1 à l'annee de fin (non-incluse)
    for (unsigned anneeActuelle = anneeDebut + 1; anneeActuelle < anneeFin; ++anneeActuelle) {
        nbJours += nbJoursDansAnnee(anneeActuelle);
    }

    //Si l'annee de depart est identique à l'année de fin, on enlève une année (365 ou 366) au nombre de jours.
    if (anneeDebut == anneeFin)
        nbJours -= nbJoursDansAnnee(anneeDebut);

    return nbJours;
}

unsigned nbJoursDansAnnee(unsigned annee) {
    return JOURS_ANNEE + estBissextile(annee);
}

unsigned nbJoursDepuisDebutAnnee(unsigned jour, unsigned mois, unsigned annee) {
    unsigned nbJours = 0;

    //De janvier jusqu'a mois - 1
    for (unsigned moisActuel = 1; moisActuel < mois; ++moisActuel) {
        nbJours += nbJoursDansMois(moisActuel, annee);
    }

    //Ajoute le nombre de jours du dernier mois
    nbJours += jour;

    return nbJours;
}

void afficherDate(unsigned jour, unsigned mois, unsigned annee) {
    cout << setfill('0') << setw(2) << jour  << SEPARATEUR_DATE
         << setw(2) << mois  << SEPARATEUR_DATE
         << setw(4) << annee << setfill(' ');
}