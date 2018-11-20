/*
 -----------------------------------------------------------------------------------
 Laboratoire :
 Fichier     : main.cpp
 Auteur(s)   : Robin Müller
 Date        : 10/28/18

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    const int TARGET_MULTIPLE = 2;

    double startAmount, currentAmount, targetAmount;
    double interestRate;
    int years = 0;

    cout << "Please enter an amount: ";
    cin  >> startAmount;
    cout << "Please enter an interest rate (in %): ";
    cin  >> interestRate;

    targetAmount = startAmount * TARGET_MULTIPLE;
    currentAmount = startAmount;

    while (currentAmount < targetAmount) {
        currentAmount += currentAmount * interestRate / 100;

        years++;
    }

    //A = P(1+r/m)^(mt)
    //With m = 1:
    // t = ln(A/P)/ln(1+r)
    //A = Amount after t years
    //P = Initial amount
    //r = Interest rate
    //m = Interest periods in a year
    //t = number of years
    years = (int)ceil(log(targetAmount / startAmount) / log(1. + interestRate / 100.));

    cout << "The amount will be x" << TARGET_MULTIPLE << " in " << years << " years.\n";

    cout << "\nPress ENTER to quit\n";
    cin.ignore();
    cin.get();

    return EXIT_SUCCESS;
}