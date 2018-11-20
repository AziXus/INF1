#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {
    const int NB_GRADES = 4,
              PRECISION = 1;

    double grade1, grade2, grade3, grade4, averageGrade;
    string appreciation;

    cout << "Please enter 4 grades: ";
    cin  >> grade1 >> grade2 >> grade3 >> grade4;

    averageGrade = (grade1 + grade2 + grade3 + grade4) / NB_GRADES;

    if (averageGrade < 4.0)
        appreciation = "Insufficient";
    else if (averageGrade <= 4.5)
        appreciation = "Intermediary";
    else if (averageGrade <= 5)
        appreciation = "Good";
    else if (averageGrade <= 5.5)
        appreciation = "Very good";
    else
        appreciation = "Perfect";

    cout << fixed << setprecision(PRECISION) << endl;
    cout << "Average = " << averageGrade << " - " << appreciation;

    cout << "\nPress ENTER to quit\n";
    cin.ignore();
    cin.get();

    return EXIT_SUCCESS;
}