/*
 -----------------------------------------------------------------------------------
 Lab        : Labo_07
 File       : main.cpp
 Author(s)  : Robin Müller
 Date       : 30.10.18

 Purpose    :

 Comment(s) :

 Compiler   : g++ 6.5.0
-----------------------------------------------------------------------------------
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <limits>

using namespace std;

#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define PI 3.14159265358979323846

//Generate random coordinate between min and max inclusive
int getCoordinate(int min, int max) {
    return rand() % (max * 2 + 1) - abs(min);
}

//Calculate distance of (x, y) to center
double distanceToCenter(int x, int y) {
    return hypot(x, y);
}

//Calculate the score. If distance is greater than radius, score is 0 else radius - distance
int getScore(int distance, int radius) {
    int score = radius - distance;

    return score < 0 ? 0: score;
}

//Read user input until value is between min and max inclusive
int getInput(string text, int min, int max) {
    bool validEntry;
    int input;
    //Read number of calculations until valid
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

double randomTo1() {
    return (rand() % 100) / 100.;
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

    const char SERIES_START_LETTER = 'A';
    const string BESTSCORE_SERIES      = "series",
                 BESTSCORE_COMPETITION = "competition",
                 MISSED_SHOT           = "n/a",
                 LINE_SEPARATOR        = "|--------|--------|--------|--------|--------|--------|--------"
                                         "|---------------------\n";

    int nbPlayers, nbSeries, nbShots;
    int distance, score, bestScoreSeries = 0, bestScoreCompetition = 0;
    int x, y;

    cout << "This program...\n";

    //Read number of players until value is between PLAYERS_MIN and MAX
    nbPlayers = getInput(" - number of players  ", PLAYERS_MIN, PLAYERS_MAX);

    //Read number of series until value is between SERIES_MIN and MAX
    nbSeries  = getInput(" - number of series   ", SERIES_MIN,  SERIES_MAX);

    //Read number of shots until value is between SHOTS_MIN and MAX
    nbShots   = getInput(" - number of shots    ", SHOTS_MIN,   SHOTS_MAX);

    //Initialize random number generator with current time
    srand((unsigned int)time(NULL));

    //Print header
    cout << endl;
    cout << "| joueur | serie  |  tir   |   x    |   y    |  dist  | score  |  meilleur score\n" << LINE_SEPARATOR;

    //Loop through players
    for (int playerNumber = 1; playerNumber <= nbPlayers; ++playerNumber) {
        //Loop through series, starting with SERIES_START_LETTER
        for (char seriesLetter = SERIES_START_LETTER; seriesLetter < SERIES_START_LETTER + nbSeries; ++seriesLetter) {
            //Loop through shots
            for (int shotNumber = 1; shotNumber <= nbShots; ++shotNumber) {
                //Generate x and y coordinates
                //Trigonometric even distribution
                double randomRadius = TARGET_RADIUS * sqrt(randomTo1());
                double angle = randomTo1() * 2. * PI;
                x = int(cos(angle) * randomRadius);
                y = int(sin(angle) * randomRadius);

                //Trigonometric uneven distribution
                randomRadius = rand() % TARGET_RADIUS;
                angle = rand() % 100 / 100. * 2. * PI;
                x = int(cos(angle) * randomRadius);
                y = int(sin(angle) * randomRadius);

                //(0, 0) is the center, minimum is -radius and max is radius
                //x = getCoordinate(-TARGET_RADIUS, TARGET_RADIUS);
                //y = getCoordinate(-TARGET_RADIUS, TARGET_RADIUS);

                //Get rounded distance as int
                distance = (int)round(distanceToCenter(x, y));
                //Score is TARGET_RADIUS - distance
                score = getScore(distance, TARGET_RADIUS);

                //print shot
                cout << right << "| " << setw(TABLE_WIDTH) << playerNumber << " | "
                                      << setw(TABLE_WIDTH) << seriesLetter << " | "
                                      << setw(TABLE_WIDTH) << shotNumber   << " | ";

                //If distance is greater than radius, missed shot
                if (distance > TARGET_RADIUS) {
                    cout << setw(TABLE_WIDTH) << MISSED_SHOT << " | "
                         << setw(TABLE_WIDTH) << MISSED_SHOT << " | "
                         << setw(TABLE_WIDTH) << MISSED_SHOT;
                } else {
                    cout << setw(TABLE_WIDTH) << x           << " | "
                         << setw(TABLE_WIDTH) << y           << " | "
                         << setw(TABLE_WIDTH) << distance;
                }

                //Print score
                cout << " | " << setw(TABLE_WIDTH) << score << " | ";

                //Print and set best score
                if (score > bestScoreSeries) {
                    bestScoreSeries = score;
                    cout << " " << BESTSCORE_SERIES;
                }
                if (score > bestScoreCompetition) {
                    bestScoreCompetition = score;
                    cout << " " << BESTSCORE_COMPETITION;
                }

                cout << endl;
            } //End loop through shots

            cout << LINE_SEPARATOR;
            //Reset best series score
            bestScoreSeries = 0;
        } //End loop through series
    } //End loop through players

    cout << "\nPress ENTER to quit";
    EMPTY_BUFFER;

    return EXIT_SUCCESS;
}
//Program output:
//This program...
//- number of players   [2 - 10]: 2
//- number of series    [1 - 10]: 1
//- number of shots     [6 - 12]: 6
//
//| joueur | serie  |  tir   |   x    |   y    |  dist  | score  |  meilleur score
//|--------|--------|--------|--------|--------|--------|--------|---------------------
//|      1 |      A |      1 |     23 |    -48 |     53 |     47 |  series competition
//|      1 |      A |      2 |     34 |     60 |     69 |     31 |
//|      1 |      A |      3 |     16 |    -82 |     84 |     16 |
//|      1 |      A |      4 |     48 |    -76 |     90 |     10 |
//|      1 |      A |      5 |    -39 |    -55 |     67 |     33 |
//|      1 |      A |      6 | missed | missed | missed |      0 |
//|--------|--------|--------|--------|--------|--------|--------|---------------------
//|      2 |      A |      1 |     66 |     62 |     91 |      9 |  series
//|      2 |      A |      2 |    -43 |    -71 |     83 |     17 |  series
//|      2 |      A |      3 |      3 |    -82 |     82 |     18 |  series
//|      2 |      A |      4 | missed | missed | missed |      0 |
//|      2 |      A |      5 |     25 |     -1 |     25 |     75 |  series competition
//|      2 |      A |      6 |    -47 |     68 |     83 |     17 |
//|--------|--------|--------|--------|--------|--------|--------|---------------------
//
//Press ENTER to quit