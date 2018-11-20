#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void swapRight(double& a, double& b, double& c) {
    double tmp = a;
    a = c;
    c = b;
    b = tmp;
}

int main() {
    double a = 1.0,
           b = 2.0,
           c = 3.0;

    cout << "a b c = " << a << " " << b << " " << c << endl;
    swapRight(a, b, c);
    cout << "a b c = " << a << " " << b << " " << c << endl;

    return EXIT_SUCCESS;
}