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
const unsigned JOUR_MIN =  1,
               JOUR_MAX = 31;

void saisieDate(const std::string& msg,
                const std::string& msgErreur,
                unsigned           anneeMin,
                unsigned           anneeMax,
                unsigned           dateSaisie[]) {
    //dateMin et dateMax sont internes à la librairie et donc la taille est fixe
    unsigned dateMin[3];
    unsigned dateMax[3];

    creerTableauDate(JOUR_MIN, Mois::Janvier, anneeMin, dateMin);
    creerTableauDate(JOUR_MAX, Mois::Decembre, anneeMax, dateMax);

    saisieDate(msg, msgErreur, dateMin, dateMax, dateSaisie);
}

void saisieDate(const std::string& msg,
                const std::string& msgErreur,
                const unsigned     dateMin[],
                unsigned           anneeMax,
                unsigned           dateSaisie[]) {
    //dateMax est interne à la librairie et donc la taille est fixe
    unsigned dateMax[3];
    creerTableauDate(JOUR_MAX, Mois::Decembre, anneeMax, dateMax);

    saisieDate(msg, msgErreur, dateMin, dateMax, dateSaisie);
}

void saisieDate(const std::string& msg,
                const std::string& msgErreur,
                const unsigned     dateMin[],
                const unsigned     dateMax[],
                unsigned           dateSaisie[]) {
    //static const pour les initialiser qu'une seule fois
    static const unsigned POS_JOUR     = 0,
                          TAILLE_JOUR  = 2,
                          POS_MOIS     = POS_JOUR + TAILLE_JOUR + 1, //+1 a cause du séparateur
                          TAILLE_MOIS  = 2,
                          POS_ANNEE    = POS_MOIS + TAILLE_MOIS + 1, //+1 a cause du séparateur
                          TAILLE_ANNEE = 4;

    string date, jour, mois, annee;
    bool valeurOk;

    do {
        //Message de saisie
        cout << msg;
        afficherDate(dateMin);
        cout << " et le ";
        afficherDate(dateMax);
        cout << " : ";

        //Lecture de la date
        getline(cin, date);

        //Vérifie que la taille de la saisie correspond exactement au format de date.
        // Si elle est de la bonne taille, on lit les valeurs.
        if (date.size() != POS_ANNEE + TAILLE_ANNEE) {
            valeurOk = false;
        } else {
            //substr permet de sélectionner une partie de la chaîne de caractère
            jour  = date.substr(POS_JOUR, TAILLE_JOUR);
            mois  = date.substr(POS_MOIS, TAILLE_MOIS);
            annee = date.substr(POS_ANNEE, TAILLE_ANNEE);

            //Vérifie que les chaines de caractères sont des nombres
            valeurOk = estUnNombre(jour) and estUnNombre(mois) and estUnNombre(annee);

            //Si la saisie est correct (i.e. toutes les chaines sont des nombres), on créé le tableau date.
            if (valeurOk) {
                //Les valeurs string représentant des nombres sont convertis en int grâce à stoi
                creerTableauDate((unsigned)stoi(jour), (unsigned)stoi(mois), (unsigned)stoi(annee), dateSaisie);
            }
        }

        //Vérification des saisies et que la date soit dans les bornes
        //On assume que les années sont toujours valides car le format de l'année est AAAA (0000-9999)
        //et rien d'autre
        if(!valeurOk or !moisCorrect(dateSaisie[INDEX_MOIS]) or
           !jourCorrect(dateSaisie) or !dateDansBorne(dateSaisie, dateMin, dateMax))
        {
            cout << msgErreur << endl;
            valeurOk = false;
        }
    } while(!valeurOk);
}

bool dateDansBorne(const unsigned date[], const unsigned dateMin[], const unsigned dateMax[]) {
    //Converti les dates vers le format entier AAAAMMJJ afin de pouvoir faire une comparaison entière
    unsigned dateEntier    =    date[INDEX_ANNEE] * 10000 +    date[INDEX_MOIS] * 100 +    date[INDEX_JOUR],
             dateMinEntier = dateMin[INDEX_ANNEE] * 10000 + dateMin[INDEX_MOIS] * 100 + dateMin[INDEX_JOUR],
             dateMaxEntier = dateMax[INDEX_ANNEE] * 10000 + dateMax[INDEX_MOIS] * 100 + dateMax[INDEX_JOUR];

    return dateEntier >= dateMinEntier and dateEntier <= dateMaxEntier;
}

bool moisCorrect(unsigned mois){
    return mois >= Mois::Janvier and mois <= Mois::Decembre;
}

bool jourCorrect(const unsigned date[]) {
    return date[INDEX_JOUR] >= JOUR_MIN and date[INDEX_JOUR] <= nbJoursDansMois(date[INDEX_MOIS], date[INDEX_ANNEE]);
}

void creerTableauDate(unsigned jour, unsigned mois, unsigned annee, unsigned date[]) {
    date[INDEX_JOUR]  = jour;
    date[INDEX_MOIS]  = mois;
    date[INDEX_ANNEE] = annee;
}

bool estBissextile(unsigned annee) {
    return annee % 400 == 0 or (annee % 4 == 0 and annee % 100 != 0);
}

unsigned int nbJoursDansMois(unsigned mois, unsigned annee) {
    //static const afin de l'initialiser une seule fois
    static const unsigned JOURS_FEVRIER = 28;

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

unsigned nbJoursDansAnnee(unsigned int annee) {
    //static const afin de l'initialiser une seule fois
    static const unsigned JOURS_ANNEE = 365;

    //une année bissextile comprend 366 jours
    return JOURS_ANNEE + estBissextile(annee);
}

unsigned nbJoursDepuisDebutAnnee(const unsigned date[]) {
    unsigned nbJours = 0;

    //Boucle de janvier jusqu'au mois en paramètre (non-compris) calculant le nombre de jours total
    for (unsigned moisActuel = 1; moisActuel < date[INDEX_MOIS]; ++moisActuel) {
        nbJours += nbJoursDansMois(moisActuel, date[INDEX_ANNEE]);
    }

    //Ajoute le nombre de jours du dernier mois
    nbJours += date[INDEX_JOUR];

    return nbJours;
}

unsigned nbJoursEntre(const unsigned dateDebut[], const unsigned dateFin[]) {
    unsigned nbJoursAnneeDebut,
             nbJoursAnneeFin,
             nbJours;

    //Calcul le nombre de jours de la date de départ jusqu'à la fin de l'année de départ
    nbJoursAnneeDebut = nbJoursDansAnnee(dateDebut[INDEX_ANNEE]) - nbJoursDepuisDebutAnnee(dateDebut);

    //Calcul le nombre de jours du début de la dernière année à la date de fin
    nbJoursAnneeFin = nbJoursDepuisDebutAnnee(dateFin);

    nbJours = nbJoursAnneeDebut + nbJoursAnneeFin;

    //Calcul le nombre de jours de l'année de debut + 1 à l'année de fin (non-incluse)
    for (unsigned anneeActuelle = dateDebut[INDEX_ANNEE] + 1; anneeActuelle < dateFin[INDEX_ANNEE]; ++anneeActuelle) {
        nbJours += nbJoursDansAnnee(anneeActuelle);
    }

    //Si l'année de départ est identique à l'année de fin, on enlève une année (365 ou 366) au nombre de jours.
    //Car nbJoursAnneeDebut donne les jours de la date de début jusqu'au 31-12 et 
    //nbJoursAnneFin donne de 01-01 à la date de fin.
    //La valeur voulu est celle se situant entre ces deux nombres et c'est pour cela qu'il faut enlever une année.
    if (dateDebut[INDEX_ANNEE] == dateFin[INDEX_ANNEE])
        nbJours -= nbJoursDansAnnee(dateDebut[INDEX_ANNEE]);

    return nbJours;
}

void afficherDate(const unsigned date[],
                  char           carRemplissage,
                  int            tailleJour,
                  int            tailleMois,
                  int            tailleAnnee) {
    cout << setfill(carRemplissage) //Défini le caractère de remplissage
         << setw(tailleJour)  << date[INDEX_JOUR] << SEPARATEUR_DATE
         << setw(tailleMois)  << date[INDEX_MOIS] << SEPARATEUR_DATE
         << setw(tailleAnnee) << date[INDEX_ANNEE]
         << setfill(' '); //Redéfini le caractère de remplissage par défaut ' '
}