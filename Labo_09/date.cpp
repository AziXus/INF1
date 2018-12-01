/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : <nom du fichier>.cpp
 Auteur(s)   : <prénom> <nom>
 Date        : <jj.mm.aaaa>

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
 */

#include "date.h"
#include "annexe.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;
char SEPARATEUR_DATE = '-';


static unsigned JOUR_MIN      =    1,
                JOUR_MAX      =   31,
                MOIS_MIN      =    1,
                MOIS_MAX      =   12,
                ANNEE_MIN     = 1900,
                ANNEE_MAX     = 2200,
                JOURS_FEVRIER =   28,
                JOURS_ANNEE   =  365;

void saisieDate(const string&  msg,
                const string&  msg_erreur,
                unsigned&      jour,
                unsigned&      mois,
                unsigned&      annee) {
    saisieDate(msg, msg_erreur, JOUR_MIN, MOIS_MIN, ANNEE_MIN, JOUR_MAX, MOIS_MAX, ANNEE_MAX, jour, mois, annee);
}

void saisieDate(const string&  msg,
                const string&  msg_erreur,
                const unsigned jour_min,
                const unsigned mois_min,
                const unsigned annee_min,
                unsigned&      jour,
                unsigned&      mois,
                unsigned&      annee) {
    saisieDate(msg, msg_erreur, jour_min, mois_min, annee_min, JOUR_MAX, MOIS_MAX, ANNEE_MAX, jour, mois, annee);
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
        printDate(jour_min, mois_min, annee_min);
        cout << " et le ";
        printDate(jour_max, mois_max, annee_max);
        cout << " : ";

        //Lecture du jour
        if (!(cin >> jour)) {
            cin.clear();
            valeurOk = false;
            viderBuffer();
        }
        else {
            //Lecture du mois
            if (cin.get() != '-' or !(cin >> mois)){
                cin.clear();
                valeurOk = false;
                viderBuffer();
            }
            else {
                if (cin.get() != '-' or !(cin >> annee)) {
                    cin.clear();
                    valeurOk = false;
                    viderBuffer();
                }
            }
        }

        //Vérification des saisies
        if(!valeurOk or !anneeCorrecte(annee, annee_min, annee_max) or !moisCorrect(mois) or !jourCorrect(jour, mois, annee))
        {
            cout << msg_erreur << endl;
            valeurOk = false;
        }
        /*viderBuffer();*/
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

unsigned nombreJourEntre(const unsigned jourDebut,
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

    //internet formula
    //nbJours = g(jourDebut, moisDebut, anneeDebut) - g(jourFin, moisFin, anneeFin);


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

void printDate(unsigned jour, unsigned mois, unsigned annee) {
    char fillChar = '0';
    cout << setfill(fillChar) << setw(2) << jour  << SEPARATEUR_DATE
                              << setw(2) << mois  << SEPARATEUR_DATE
                              << setw(4) << annee;
}


/*int g(int d, int m, int y) {
    m = (m + 9) % 12;
    y = y - m / 10;

    //Days since 01-01-0000
    return 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (d - 1);
}*/

/*
 * mois 12
 * m = 9
 * y = 2018 - 9/10
 */