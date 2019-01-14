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

ostream& operator <<(ostream& os, const vector<vector<int>>& v)
{
    os << '[';
    if(v.begin() != v.end()){
        vector<vector<int>>::const_iterator it = v.begin();
        for(; it != prev(v.end()); it++)
        {
            //os << *v;
            os << *it << ", ";
        }
        os << *it;
    }
    os << ']';
    return os;
}