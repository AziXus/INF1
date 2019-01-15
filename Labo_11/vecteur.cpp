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
        int nbColonnes = m.at(0).size();
        for(size_t i = 0; i < m.size();i++)
        {
            if(m.at(i).size() != nbColonnes)
                return false;
        }
        
        return true;
    }
    return false;
}

bool plusGrand(Ligne i, Ligne j)
{
    return i.size() < j.size();
}

int maxCol(const Matrice& m)
{
    Matrice::const_iterator it = max_element(m.begin(),m.end(),plusGrand);
    return (*it).size();
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
    random_shuffle(m.begin(),m.end(),random);
}

bool comparer(Ligne i, Ligne j)
{
    return sommeLigne(i) < sommeLigne(j);
}

void sortMatrice(Matrice& m)
{
    sort(m.begin(),m.end(),comparer);
}

int random(int i)
{
    static bool premierAppel = true;
    if(premierAppel)
    {
        srand(time(NULL));
        premierAppel = false;
    }
    return rand()%i;
}