/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : vecteur.cpp
 Auteur(s)   : <prénom> <nom>
 Date        : <jj.mm.aaaa>

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
 */
#include "vecteur.h"
#include <algorithm>
#include <numeric>
#include <iterator>
#include <ctime>

using namespace std;
/**
 * Fonction interne
 * @param i
 * @param j
 * @return 
 */
bool plusGrand(Ligne i, Ligne j);
/**
 * 
 * @param i
 * @return 
 */
int nombreAleatoire(int i);
bool comparerTaille(Ligne i, Ligne j);

ostream& operator <<(ostream& os, const vector<int>& v)
{
    os << '[';
    if(v.begin() != v.end()){
        vector<int>::const_iterator it = v.begin();
        for(; it != prev(v.end()); it++)
        {
            os << *it << ", ";
        }
        os << *it;
    }
    os << ']';
    return os;
}

ostream& operator <<(ostream& os, const Matrice& v)
{
    os << '[';
    if(v.begin() != v.end()){
        Matrice::const_iterator it = v.begin();
        for(; it != prev(v.end()); it++)
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
            for(Ligne ligne : m)
            {
                if(ligne.size() != nbColonnes)
                    return false;
            }
            return true;
        }
        return false;
    }
    return false;
}

int maxCol(const Matrice& m)
{
    return (*max_element(m.begin(),m.end(),plusGrand)).size();
}

vector<int> sommeLignes(const Matrice& m)
{
    vector<int> sommeLignes;
    for(const Ligne& ligne : m)
    {
        sommeLignes.push_back(sommeLigne(ligne));
    }
    return sommeLignes;
}

int sommeLigne(const Ligne& ligne)
{
    return accumulate(ligne.begin(),ligne.end(),0);
}

vector<int> vectSommeMin(const Matrice& m)
{
    vector<int> somme = sommeLignes(m);
    vector<int>::iterator it = min_element(somme.begin(),somme.end());
    int distanceValeur = distance(somme.begin(), it);
    return m.at(distanceValeur);
}

void shuffleMatrice(Matrice& m)
{
    random_shuffle(m.begin(),m.end(),nombreAleatoire);
}

void sortMatrice(Matrice& m)
{
    sort(m.begin(),m.end(),comparerTaille);
}

bool sommeDiagDG(const Matrice& m, int& sommeDG)
{
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

bool plusGrand(Ligne i, Ligne j)
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

bool comparerTaille(Ligne i, Ligne j)
{
    return sommeLigne(i) < sommeLigne(j);
}