/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_11_Matrice
 Fichier     : matrice.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.01.2019

 But         : Mise en place de différentes fonctions permettant la manipulation 
               d'une matrice ou un vecteur d'entier.
               Test des différentes focntionnalités de la librairie matrice.h 
               grâce au main.cpp

 Remarque(s) : Utilisation de fonction des libraires vector et algorithm.
               Utilisation de la libraire matrice.h
             

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include "matrice.h"
#include <cstdlib>

using namespace std;

int main() {
    //déclaration de la matrice à manipuler
    vector<vector<int>> v = {{1,2,4,4},{3,3,3,3},{3,5,5,5},{6,6,6,6}};
    int sommeDiag;
    //Test de l'affichage de la matrice
    cout << "La matrice a manipulee est la suivante : " << v << endl;
    
    //Affichage du nombre de valeur max contenue dans vecteur d'une matrice
    cout << "Maximum de valeur contenues dans une ligne de la matrice : " << maxCol(v) << endl;
    
    cout << "Somme des valeurs pour chaque ligne de la matrice : " << sommeLignes(v) << endl;
    
    cout << "Ligne ayant la somme la plus petite de la matrice : " << vectSommeMin(v) << endl;
    
    shuffleMatrice(v);
    cout << "Affichage de la matrice apres un Randomshuffle : " << v << endl;
    
    sortMatrice(v);
    cout << "Mise en ordre de la matrice de la plus petite somme a la plus grande : " << v << endl;
    
    cout << boolalpha << "La matrice est-elle carree ? " << sommeDiagDG(v,sommeDiag) << endl;
    cout << "Somme de la diagonale de droite a gauche: " << sommeDiag << endl;
    
    cout << boolalpha << "La matrice est-elle carree ? " << sommeDiagGD(v,sommeDiag) << endl;
    cout << "Somme de la diagonale de gauche a droite: " << sommeDiag << endl;
    
    return EXIT_SUCCESS;
}

