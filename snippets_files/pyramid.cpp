#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double getRectangleVolume(double length, double width) {
    return length * width;
}
double getRectangleVolume(double length) {
    return getRectangleVolume(length, length);
}

double getPyramidVolume(double length, double width, double height) {
    return 1./3. * getRectangleVolume(length, width) * height;
}

double getPyramidVolume(double length, double height) {
    return getPyramidVolume(length, length, height);
}

int main() {
    cout << setprecision(1) << fixed
         << "Length: 10\nWidth: 3.5\nHeight: 12\n       = " << getPyramidVolume(10, 3.5, 12)   << endl
         << "Length: 3.6\nWidth: 2.4\nHeight: 2.7\n     = " << getPyramidVolume(3.6, 2.4, 2.7) << endl;

}