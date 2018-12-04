/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_09_Date
 Fichier     : date.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 05.12.2018

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include "date.h"
#include "annexe.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Défini le séparateur de date par défaut. Cette valeur étant déclaré comme extern, elle peut être changé
//en dehors de la librairie
char SEPARATEUR_DATE = '-';

//Valeurs par défaut de la librairie
const unsigned JOUR_MIN      =    1,
               JOUR_MAX      =   31,
               JOURS_FEVRIER =   28,
               JOURS_ANNEE   =  365;

void saisieDate(const std::string& msg,
                const std::string& msgErreur,
                unsigned           anneeMin,
                unsigned           anneeMax,
                unsigned           dateSaisie[]) {
    unsigned dateMin[] = {JOUR_MIN, Mois::Janvier,  anneeMin};
    unsigned dateMax[] = {JOUR_MAX, Mois::Decembre, anneeMax};
    //creerDate(JOUR_MIN, Mois::Janvier,  anneeMin, dateMin);

    saisieDate(msg, msgErreur, dateMin, dateMax, dateSaisie);
}

void saisieDate(const std::string& msg,
                const std::string& msgErreur,
                const unsigned     dateMin[],
                unsigned           anneeMax,
                unsigned           dateSaisie[]) {
    unsigned dateMax[] = {JOUR_MAX, Mois::Decembre, anneeMax};

    saisieDate(msg, msgErreur, dateMin, dateMax, dateSaisie);
}

void saisieDate(const std::string& msg,
                const std::string& msgErreur,
                const unsigned     dateMin[],
                const unsigned     dateMax[],
                unsigned           dateSaisie[]) {

    bool valeurOk;

    do {
        //On assume qu'il n'y a pas d'erreur en début de boucle
        valeurOk = true;

        //Message de saisie
        cout << msg;
        afficherDate(dateMin);
        cout << " et le ";
        afficherDate(dateMax);
        cout << " : ";

        //Lecture du jour
        //Essaie de lire la date et s'arrête à la première erreur.
        //les cin.get vide les SEPARATEUR_DATE du buffer
        //si SEPARATEUR_DATE = '-' on va supprimer le '-'
        valeurOk = cin >> dateSaisie[INDEX_JOUR] and cin.get() == SEPARATEUR_DATE and cin >> dateSaisie[INDEX_MOIS]
                                                 and cin.get() == SEPARATEUR_DATE and cin >> dateSaisie[INDEX_ANNEE];

        if (!valeurOk) {
            cin.clear();
        }
        viderBuffer();

        //Vérification des saisies
        if(!valeurOk or !dateValide(dateSaisie) or !dateDansBorne(dateSaisie, dateMin, dateMax))
        {
            cout << msgErreur << endl;
            valeurOk = false;
        }
    } while(!valeurOk);
}

bool anneeCorrecte(unsigned annee){
    return annee >= ANNEE_MIN and annee <= ANNEE_MAX;
}

bool moisCorrect(unsigned mois){
    return mois >= Mois::Janvier and mois <= Mois::Decembre;
}

bool jourCorrect(const unsigned date[]) {
    return date[INDEX_JOUR] >= JOUR_MIN and date[INDEX_JOUR] <= nbJoursDansMois(date[INDEX_MOIS], date[INDEX_ANNEE]);
}

bool estBissextile(unsigned annee) {
    return annee % 400 == 0 or (annee % 4 == 0 and annee % 100 != 0);
}

unsigned int nbJoursDansMois(unsigned mois, unsigned annee) {
    unsigned int nbJours;

    if (mois == Mois::Fevrier) {
        nbJours = JOURS_FEVRIER + estBissextile(annee);
    } else {
        //Si les mois de (1 à 7)  sont pairs, ils ont 30 jours
        //Si les mois de (8 à 12) sont pairs, ils ont 31 jours
        //%2 est utilisé pour tester la parité
        //%7 est utilisé pour recommencer le numéro des mois (8-12 => 1-7) afin d'avoir une seule condition
        //Exemples :
        //Pour Aout:      31 - (8 - 1) % 7 % 2 => 31 - 0 => 31 jours
        //Pour Septembre: 31 - (9 - 1) % 7 % 2 => 31 - 1 => 30 jours
        nbJours = JOUR_MAX - (mois - 1) % 7 % 2;
    }

    return nbJours;
}

unsigned nbJoursEntre(const unsigned dateDebut[], const unsigned dateFin[]) {
    unsigned nbJoursAnneeDebut,
             nbJoursAnneeFin,
             nbJours;

    //Calcul le nombre de jours de la date de départ jusqu'à la fin de l'année de départ non-compris
    nbJoursAnneeDebut = nbJoursDansAnnee(dateDebut[INDEX_ANNEE]) - nbJoursDepuisDebutAnnee(dateDebut);

    //Calcul le nombre de jours du début de la dernière année à la date de fin compris
    nbJoursAnneeFin   = nbJoursDepuisDebutAnnee(dateFin);

    nbJours = nbJoursAnneeDebut + nbJoursAnneeFin;

    //Calcul le nombre de jours de l'année de debut + 1 à l'année de fin (non-incluse)
    for (unsigned anneeActuelle = dateDebut[INDEX_ANNEE] + 1; anneeActuelle < dateFin[INDEX_ANNEE]; ++anneeActuelle) {
        nbJours += nbJoursDansAnnee(anneeActuelle);
    }

    //Si l'année de depart est identique à l'année de fin, on enlève une année (365 ou 366) au nombre de jours.
    if (dateDebut[INDEX_ANNEE] == dateFin[INDEX_ANNEE])
        nbJours -= nbJoursDansAnnee(dateDebut[INDEX_ANNEE]);

    return nbJours;
}

unsigned nbJoursDansAnnee(unsigned int annee) {
    return JOURS_ANNEE + estBissextile(annee);
}

unsigned nbJoursDepuisDebutAnnee(const unsigned date[]) {
    unsigned nbJours = 0;

    //De janvier jusqu'a mois - 1
    for (unsigned moisActuel = 1; moisActuel < date[INDEX_MOIS]; ++moisActuel) {
        nbJours += nbJoursDansMois(moisActuel, date[INDEX_ANNEE]);
    }

    //Ajoute le nombre de jours du dernier mois
    nbJours += date[INDEX_JOUR];

    return nbJours;
}

void afficherDate(const unsigned date[],
                  char           carRemplissage,
                  int            tailleJour,
                  int            tailleMois,
                  int            tailleAnnee) {
    cout << setfill(carRemplissage)
         << setw(tailleJour)  << date[INDEX_JOUR] << SEPARATEUR_DATE
         << setw(tailleMois)  << date[INDEX_MOIS] << SEPARATEUR_DATE
         << setw(tailleAnnee) << date[INDEX_ANNEE]
         //Redéfini le caractère de remplissage par défaut ' '
         << setfill(' ');
}

bool dateDansBorne(const unsigned date[], const unsigned dateMin[], const unsigned dateMax[]) {
    /**
     *
     * if (annee > annee)
     */
    //Converti les dates vers le format entier AAAAMMJJ afin de pouvoir faire une comparaison entière
    unsigned dateEntier    =    date[INDEX_ANNEE] * 10000 +    date[INDEX_MOIS] * 100 +    date[INDEX_JOUR],
             dateMinEntier = dateMin[INDEX_ANNEE] * 10000 + dateMin[INDEX_MOIS] * 100 + dateMin[INDEX_JOUR],
             dateMaxEntier = dateMax[INDEX_ANNEE] * 10000 + dateMax[INDEX_MOIS] * 100 + dateMax[INDEX_JOUR];

    return dateEntier >= dateMinEntier and dateEntier <= dateMaxEntier;
}

bool creerDate(unsigned jour, unsigned mois, unsigned annee, unsigned date[]) {
    bool dateOk;

    //Affectation du tableau ? Tableau temp ?
    date[INDEX_JOUR]  = jour;
    date[INDEX_MOIS]  = mois;
    date[INDEX_ANNEE] = annee;

    dateOk = anneeCorrecte(date[INDEX_ANNEE]) and moisCorrect(date[INDEX_MOIS]) and jourCorrect(date);

    if (!dateOk) {
        date[INDEX_JOUR]  = 0;
        date[INDEX_MOIS]  = 0;
        date[INDEX_ANNEE] = 0;
    }

    return dateOk;
}

bool dateValide(const unsigned date[]) {
    return anneeCorrecte(date[INDEX_ANNEE]) and moisCorrect(date[INDEX_MOIS]) and jourCorrect(date);
}
