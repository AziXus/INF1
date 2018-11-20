/*
 -----------------------------------------------------------------------------------
 Lab        : Labo_07
 File       : main.cpp
 Author(s)  : Robin Müller
 Date       : 13.11.18

 Purpose    : The user is asked to enter the number of players, the number of series per players
              and the number of shots. The program then generate random shots (points on a
              200x200 grid) and calculate the distance from the center of the target to
              the shot. The score is 100 points minus the distance. A message is displayed
              if a best score is reached.

 Comment(s) : The number of players must be between 2 and 10, the number of series between
              1 and 10 and the number of shots between 6 and 12. The target is a circle of
              100 of radius.

 Compiler   : g++ 6.5.0
-----------------------------------------------------------------------------------
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>  //setw
#include <cmath>    //hypot, round
#include <limits>   //numeric_limits
#include <ctime>    //time
#include <string>

using namespace std;

#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

//Generate random coordinate between min and max inclusive
int getCoordinate(int min, int max) {
    return rand() % (max - min + 1) + min;
}

//Calculate distance of (x, y) to center (0, 0)
double distanceToCenter(int x, int y) {
    return hypot(x, y);
}

//Calculate the score (radius - distance, minimum is 0)
int getScore(int distance, int radius) {
    int score = radius - distance;

    return score < 0 ? 0: score;
}

//Read user input until value is between min and max inclusive
int getInput(string text, int min, int max) {
    bool validEntry;
    int input;
    //Loop until input is between min and max
    do {
        cout << text << " [" << min << " - " << max << "]: ";
        validEntry = cin >> input and input >= min and input <= max;
        if (!validEntry) {
            cin.clear();
            cout << "Invalid entry. Value must be between " << min << " and " << max << endl;
        }
        EMPTY_BUFFER;
    } while (!validEntry);

    return input;
}

int main() {
    const int PLAYERS_MIN   =   2,
              PLAYERS_MAX   =  10,
              SERIES_MIN    =   1,
              SERIES_MAX    =  10,
              SHOTS_MIN     =   6,
              SHOTS_MAX     =  12,
              TABLE_WIDTH   =   6;
    const int TARGET_RADIUS = 100;

    const char   SERIES_START_LETTER   = 'A';
    const string BESTSCORE_SERIES      = "series",
                 BESTSCORE_COMPETITION = "competition",
                 TABLE_HEADER          = "| player | series |  shot  |   x    |   y    |  dist  | score  "
                                         "|  best score",
                 SERIES_SEPARATOR      = "|--------|--------|--------|--------|--------|--------|--------"
                                         "|------------------------\n";

    int nbPlayers, nbSeries, nbShots;
    int distance, score, bestScoreSeries = 0, bestScoreCompetition = 0;
    int x, y;

    cout << "This program will generate random scores for a shooting competition.\n";

    //Read number of players until value is between PLAYERS_MIN and MAX
    nbPlayers = getInput(" - number of players  ", PLAYERS_MIN, PLAYERS_MAX);

    //Read number of series until value is between SERIES_MIN and MAX
    nbSeries  = getInput(" - number of series   ", SERIES_MIN,  SERIES_MAX);

    //Read number of shots until value is between SHOTS_MIN and MAX
    nbShots   = getInput(" - number of shots    ", SHOTS_MIN,   SHOTS_MAX);

    //Print header
    cout << endl << TABLE_HEADER << endl << SERIES_SEPARATOR;

    //Initialize random number generator with current time
    srand((unsigned int)time(NULL));

    //Loop through players
    for (int playerNumber = 1; playerNumber <= nbPlayers; ++playerNumber) {
        //Loop through series, starting with SERIES_START_LETTER
        for (char seriesLetter = SERIES_START_LETTER; seriesLetter < SERIES_START_LETTER + nbSeries; ++seriesLetter) {
            //Loop through shots
            for (int shotNumber = 1; shotNumber <= nbShots; ++shotNumber) {
                //Generate x and y coordinates
                //(0, 0) is the center, minimum is -radius and max is radius
                x = getCoordinate(-TARGET_RADIUS, TARGET_RADIUS);
                y = getCoordinate(-TARGET_RADIUS, TARGET_RADIUS);

                //Get rounded distance as int
                distance = (int)round(distanceToCenter(x, y));
                //Score is TARGET_RADIUS - distance
                score = getScore(distance, TARGET_RADIUS);

                //Print player and series information
                cout << right << "| " << setw(TABLE_WIDTH) << playerNumber << " | "
                                      << setw(TABLE_WIDTH) << seriesLetter << " | "
                                      << setw(TABLE_WIDTH) << shotNumber   << " | ";
                //Print shot coordinate, distance and score
                cout                  << setw(TABLE_WIDTH) << x            << " | "
                                      << setw(TABLE_WIDTH) << y            << " | "
                                      << setw(TABLE_WIDTH) << distance     << " | "
                                      << setw(TABLE_WIDTH) << score        << " | ";

                //Print and set best score
                if (score > bestScoreSeries) {
                    bestScoreSeries = score;
                    cout << " "   << BESTSCORE_SERIES;
                }
                if (score > bestScoreCompetition) {
                    bestScoreCompetition = score;
                    cout << " - " << BESTSCORE_COMPETITION;
                }

                cout << endl;
            } //End loop through shots

            cout << SERIES_SEPARATOR;

            //Reset best series score
            bestScoreSeries = 0;
        } //End loop through series
    } //End loop through players

    cout << "\nPress ENTER to quit";
    EMPTY_BUFFER;

    return EXIT_SUCCESS;
}
//Program output:
//This program will generate random scores for a shooting competition.
//- number of players   [2 - 10]: 2
//- number of series    [1 - 10]: 1
//- number of shots     [6 - 12]: 6
//
//| player | series |  shot  |   x    |   y    |  dist  | score  |  best score
//|--------|--------|--------|--------|--------|--------|--------|---------------------
//|      1 |      A |      1 |     13 |    -93 |     94 |      6 |  series - competition
//|      1 |      A |      2 |     66 |    -16 |     68 |     32 |  series - competition
//|      1 |      A |      3 |    -22 |     -7 |     23 |     77 |  series - competition
//|      1 |      A |      4 |     51 |     -7 |     51 |     49 |
//|      1 |      A |      5 |    -45 |     89 |    100 |      0 |
//|      1 |      A |      6 |    -90 |    -84 |    123 |      0 |
//|--------|--------|--------|--------|--------|--------|--------|---------------------
//|      2 |      A |      1 |     96 |    -92 |    133 |      0 |
//|      2 |      A |      2 |    -56 |     55 |     78 |     22 |  series
//|      2 |      A |      3 |     29 |    -31 |     42 |     58 |  series
//|      2 |      A |      4 |     77 |    -70 |    104 |      0 |
//|      2 |      A |      5 |    -54 |     10 |     55 |     45 |
//|      2 |      A |      6 |     67 |    -80 |    104 |      0 |
//|--------|--------|--------|--------|--------|--------|--------|---------------------
//
//Press ENTER to quit