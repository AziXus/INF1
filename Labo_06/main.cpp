/*
 -----------------------------------------------------------------------------------
 Lab        : Labo_06
 File       : main.cpp
 Author(s)  : Robin Müller
 Date       : 30.10.18

 Purpose    : Generate random additions, subtractions, multiplications and divisions
              based on parameters defined by the user.
              Once all calculations are answered, the number of correct answers
              and the percentage are displayed.

 Comment(s) : The number of calculations [1-100] and the minimum and
              maximum number [1-100] are entered by the user.

 Compiler   : g++ 8.2.1
-----------------------------------------------------------------------------------
 */

#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    const int CALCULATIONS_MIN   =   1,
              CALCULATIONS_MAX   = 100,
              NUMBER_MIN         =   1,
              NUMBER_MAX         = 100,
              NB_OPERATORS       =   4,
              DECIMAL_PRECISION  =   2;

    enum class Operator {ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION};
    int nbCalculations, minimumNumber, maximumNumber, nbCorrectAnswers = 0;
    int x, y, result, inputResult;
    char randOperator;
    bool validEntry;

    cout << "This program will generate random calculations based on your selection and check your answers.\n";

    //Read number of calculations until valid
    do {
        cout << " - number of calculations [" << CALCULATIONS_MIN << " - " << CALCULATIONS_MAX << "]: ";
        validEntry = cin >> nbCalculations and nbCalculations >= CALCULATIONS_MIN and nbCalculations <= CALCULATIONS_MAX;
        if (!validEntry) {
            cin.clear();
            cout << "Invalid entry. Value must be between " << CALCULATIONS_MIN << " and " << CALCULATIONS_MAX << endl;
        }
        EMPTY_BUFFER;
    } while (!validEntry);

    //Read minimum number until valid
    do {
        cout << " - minimum number         [" <<       NUMBER_MIN << " - " <<          NUMBER_MAX << "]: ";
        validEntry = cin >> minimumNumber and minimumNumber >= NUMBER_MIN and minimumNumber <= NUMBER_MAX;
        if (!validEntry) {
            cin.clear();
            cout << "Invalid entry. Value must be between " << NUMBER_MIN << " and " << NUMBER_MAX << endl;
        }
        EMPTY_BUFFER;
    } while (!validEntry);

    //Read maximum number until valid
    do {
        cout << " - maximum number         [" <<        minimumNumber << " - " <<          NUMBER_MAX << "]: ";
        validEntry = cin >> maximumNumber and maximumNumber >= minimumNumber and maximumNumber <= NUMBER_MAX;
        if (!validEntry) {
            cin.clear();
            cout << "Invalid entry. Value must be between " << minimumNumber << " and " << NUMBER_MAX << endl;
        }
        EMPTY_BUFFER;
    } while (!validEntry);

    //Initialize random number generator
    srand(time(NULL));

    //For each calculation, generate 2 random integers and an operator and ask the user for the result
    for (int calculationID = 0; calculationID < nbCalculations; ++calculationID) {
        //Get numbers between min and max inclusive from random function
        //Example: User entered limits between 3-10 inclusive
        //145 % (10 - 3 + 1) + 3 = 145 % 8 + 3: %8 gets 8 possibilities (0-7) and +3 sets range (3-10)
        //= 1 + 3 = 4
        x = rand() % (maximumNumber - minimumNumber + 1) + minimumNumber;
        y = rand() % (maximumNumber - minimumNumber + 1) + minimumNumber;

        //Get a random operator and calculate the result of x operator y
        switch (Operator(rand() % NB_OPERATORS)) {
            case Operator::ADDITION       : result = x + y; randOperator = '+'; break;
            case Operator::SUBTRACTION    : result = x - y; randOperator = '-'; break;
            case Operator::MULTIPLICATION : result = x * y; randOperator = '*'; break;
            case Operator::DIVISION       : result = x / y; randOperator = '/'; break;
        }

        //Display calculation and read result until valid
        do {
            cout << calculationID << ": " << x << " " << randOperator << " " << y << " = ";
            validEntry = bool(cin >> inputResult);
            if (!validEntry) {
                cin.clear();
                cout << "Invalid entry.\n";
            }
            EMPTY_BUFFER;
        } while (!validEntry);

        //Increment correct answers if result is correct
        if (inputResult == result)
            nbCorrectAnswers++;
    }

    //Display correct answers
    cout << fixed << setprecision(DECIMAL_PRECISION);
    cout << "you have " << nbCorrectAnswers << "/" << nbCalculations << " correct answers "
         << "(" << (double)nbCorrectAnswers / nbCalculations << ")";

    cout << "\nPress ENTER to quit";
    cin.get();
    EMPTY_BUFFER;

    return EXIT_SUCCESS;
}
//Program output:
//This program will generate random calculations based on your selection and check your answers.
// - number of calculations [1 - 100]: 4
// - minimum number         [1 - 100]: 3
// - maximum number         [3 - 100]: 10
//0: 10 * 6 = 60
//1: 4 + 7 = 8
//2: 7 - 8 = -1
//3: 6 * 5 = 30
//you have 3/4 correct answers (0.75)
//Press ENTER to quit