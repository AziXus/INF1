#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    const double CM3_TO_LITERS = 0.001;

    double r1, r2;
    double h1, h2, h3;

    double v1, v2, v3, bottleVolume;

    //Print introduction
    cout << "This program will ask you to enter different sizes of a bottle and determine its volume.\n";

    //Get values (r1, r2, h1, h2, h3)
    cout << "Please enter r1 (in cm) ";
    cin >> r1;

    cout << "Please enter h1 (in cm) ";
    cin >> h1;

    cout << "Please enter r2 (in cm) ";
    cin >> r2;

    cout << "Please enter h2 (in cm) ";
    cin >> h2;

    cout << "Please enter h3 (in cm) ";
    cin >> h3;

    //Calculate volumes
    //Cylinder volume = PI * r^2 * h
    v1 = M_PI * r1 * r1 * h1;
    v2 = M_PI * r2 * r2 * h2;

    //Truncated cone volume = (PI/3 * h3)*(r1^2 + r2^2 + r1 * r2)
    v3 = (M_PI/3 * h3) * (r1 * r1 + r2 * r2 + r1 * r2);

    bottleVolume = v1 + v2 + v3;

    //Print the final result with a precision of 1
    cout << setprecision(1) << fixed;
    cout << "The volume of the bottle is: " << bottleVolume * CM3_TO_LITERS << " l\n";

    return 0;
}