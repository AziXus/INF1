/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_11_Matrice
 Fichier     : matrice.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.01.2019
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "matrice.h"
#include <algorithm>
#include <numeric>
#include <ctime>

using namespace std;
/**
 * Fonction permettant de comparer la taille de deux lignes
 * @param i la ligne de gauche à comparer
 * @param j la ligne de droite à comparer
 * @return vrai si la ligne de droite est plus grande que la ligne de gauche, sinon faux
 */
bool comparerTaille(const Ligne& i, const Ligne& j);

/**
 * Génère un nombre aléatoire pour le random_shuffle de la matrice
 * @param i taille de la matrice
 * @return un nombre aléatoire
 */
int nombreAleatoire(int i);

/**
 * Compare deux lignes en fonction de leur élément maximal
 * @param i la ligne de gauche à comparer
 * @param j la ligne de droite à comparer
 * @return vrai si l'élément max de la ligne de droite est plus grand que la ligne 
           de gauche, sinon faux
 */
bool comparerElementMax(const Ligne& i, const Ligne& j);

ostream& operator<<(ostream& os, const Ligne& ligne)
{
    os << '[';
    if(ligne.begin() != ligne.end())
    {
        Ligne::const_iterator it = ligne.begin();
        for(; it != prev(ligne.end()); it++) //On parcourt du premier à l'avant-dernier élément
        {
            os << *it << ", ";
        }
        os << *it;
    }
    os << ']';

    return os;
}

ostream& operator<<(ostream& os, const Matrice& m)
{
    os << '[';
    if(m.begin() != m.end())
    {
        Matrice::const_iterator it = m.begin();
        for(; it != prev(m.end()); it++) //On parcourt de la première à l'avant-dernière ligne
        {
            os << *it << ", ";
        }
        os << *it;
    }
    os << ']';

    return os;
}

bool estCarre(const Matrice& m)
{
    if(!m.empty())
    {
        size_t nbColonnes = m.at(0).size();
        size_t nbLignes = m.size();
        if(nbLignes == nbColonnes)
        {
            //Vérifie que toutes les lignes ont le même nombre de colonnes
            for(const Ligne& ligne : m)
            {
                if(ligne.size() != nbColonnes)
                    return false;
            }
            return true;
        }
    }
    return false;
}

size_t maxCol(const Matrice& m)
{
    //retourne la taille de l'iterateur de la ligne la plus grande.
    return (*max_element(m.begin(), m.end(), comparerTaille)).size();
}

int sommeUneLigne(const Ligne& ligne)
{
    return accumulate(ligne.begin(), ligne.end(), 0);
}

vector<int> sommeLigne(const Matrice& m)
{
    vector<int> sommes(m.size());
    //Calcul la somme de chaque ligne et les stockent dans le vecteur d'entier sommes
    transform(m.begin(), m.end(), sommes.begin(), sommeUneLigne);
    return sommes;
}

Ligne vectSommeMin(const Matrice& m)
{
    vector<int> somme = sommeLigne(m);
    //Calcul la position de ligne avec la plus petite somme
    size_t distanceValeur = distance(somme.begin(), min_element(somme.begin(),somme.end()));
    return m.at(distanceValeur);
}

void shuffleMatrice(Matrice& m)
{
    random_shuffle(m.begin(), m.end(), nombreAleatoire);
}

void sortMatrice(Matrice& m)
{
    sort(m.begin(), m.end(), comparerElementMax);
}

bool sommeDiagDG(const Matrice& m, int& sommeDG)
{
    sommeDG = 0;//la valeur de base d'une diagonale est 0
    if(estCarre(m))
    {
        for(size_t i = 0; i < m.size();i++)
        {
          //pour la postion a additionée on effectue m.at(i).end() - 1 qui donnera la dernière
          //case et ensuite - i pour être sur la diagonale
          sommeDG += *((m.at(i).end() - 1) - i);
        }
        return true;
    }
    return false;
}

bool sommeDiagGD(const Matrice& m, int& sommeGD)
{
    sommeGD = 0;//la valeur de base d'une diagonale est 0
    if(estCarre(m))
    {
        for(size_t i = 0; i < m.size();i++)
        {
          sommeGD += m.at(i).at(i);
        }
        return true;
    }
    return false;
}

bool comparerTaille(const Ligne& i, const Ligne& j)
{
    return i.size() < j.size();
}

int nombreAleatoire(int i)
{
    //static car lors du premier appel on définie le srand
    static bool premierAppel = true;
    if(premierAppel)
    {
        srand(time(NULL));
        premierAppel = false;
    }
    return rand()%i;
}

bool comparerElementMax(const Ligne& i, const Ligne& j)
{
    return *max_element(i.begin(), i.end()) < *max_element(j.begin(), j.end());
}
