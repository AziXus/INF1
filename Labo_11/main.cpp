/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_11_Matrice
 Fichier     : main.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 21.01.2019

 But         : Mise en place de différentes fonctions permettant la manipulation 
               d'une matrice ou un vecteur d'entier.
               Test des différentes fonctionnalités de la librairie matrice.h 
               dans le main.cpp.

 Remarque(s) : Utilisation de fonction des libraires vector et algorithm.
               Utilisation de la libraire matrice.h.
             

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include "matrice.h"
#include <cstdlib>

using namespace std;

int main() {
    //déclaration de la matrice à manipuler
    Matrice m = {{1,2,4,4},{3,3,3,3},{3,5,5,5},{6,6,6,6}};
    int sommeDiag;
    
    //Test de l'affichage de la matrice
    cout << "La matrice a manipulee est la suivante : " << m << endl;
    
    cout << "Maximum de valeurs contenues dans une ligne de la matrice : " << maxCol(m) << endl;
    
    cout << "Somme des valeurs pour chaque ligne de la matrice : " << sommeLigne(m) << endl;
    
    cout << "Ligne ayant la somme la plus petite de la matrice : " << vectSommeMin(m) << endl;
    
    shuffleMatrice(m);//Mélange les lignes de la matrice
    cout << "Affichage de la matrice apres un Randomshuffle : " << m << endl;
    
    sortMatrice(m);
    cout << "Tri croissant de la matrice en fonction de l'élément max d'une ligne : " << m << endl;
    
    cout << boolalpha << "La matrice est-elle carree ? " << sommeDiagDG(m,sommeDiag) << endl;
    cout << "Somme de la diagonale de droite a gauche : " << sommeDiag << endl;
    
    cout << boolalpha << "La matrice est-elle carree ? " << sommeDiagGD(m,sommeDiag) << endl;
    cout << "Somme de la diagonale de gauche a droite : " << sommeDiag << endl;
    
    return EXIT_SUCCESS;
}

