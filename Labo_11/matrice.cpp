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
#include <iterator>
#include <ctime>

using namespace std;
/**
 * Fonction interne permettant de comparer la taille de deux lignes
 * @param i la ligne de gauche à comparer
 * @param j la ligne de droite à comparer
 * @return vrai si de la ligne de gauche est plus grande que la ligne de droite, sinon faux
 */
bool comparerTaille(const Ligne& i, const Ligne& j);

/**
 * 
 * @param i
 * @return 
 */
int nombreAleatoire(int i);

/**
 *
 * @param i
 * @param j
 * @return
 */
bool comparerElementMax(const Ligne& i, const Ligne& j);

ostream& operator<<(ostream& os, const Ligne& ligne)
{
    os << '[';
    if(ligne.begin() != ligne.end())
    {
        Ligne::const_iterator it = ligne.begin();
        for(; it != prev(ligne.end()); it++) //On parcours du premier à l'avant-dernier élément
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
        for(; it != prev(m.end()); it++) //On parcours de la première à l'avant-dernière ligne
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
            //Vérifie que toutes les lignes sont de la même taille
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
    return (*max_element(m.begin(), m.end(), comparerTaille)).size();
}

int sommeUneLigne(const Ligne& ligne)
{
    return accumulate(ligne.begin(), ligne.end(), 0);
}

vector<int> sommeLigne(const Matrice& m)
{
    /*
    vector<int> sommeLignes;
    for(const Ligne& ligne : m)
    {
        sommeLignes.push_back(sommeUneLigne(ligne));
    }
    return sommeLignes;
     */
    vector<int> sommes(m.size());
    transform(m.begin(), m.end(), sommes.begin(), sommeUneLigne);
    return sommes;
}

Ligne vectSommeMin(const Matrice& m)
{
    vector<int> somme = sommeLigne(m);
    vector<int>::iterator it = min_element(somme.begin(),somme.end());
    //Calcul la position de l'iterateur
    size_t distanceValeur = distance(somme.begin(), it);
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
    sommeDG = 0;
    if(estCarre(m))
    {
        for(size_t i = 0; i < m.size();i++)
        {
          sommeDG += *((m.at(i).end() - 1) - i);
        }
        return true;
    }
    return false;
}

bool sommeDiagGD(const Matrice& m, int& sommeGD)
{
    sommeGD = 0;
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
