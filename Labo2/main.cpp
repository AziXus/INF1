#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <limits>
#include <iomanip>
#include <cmath>

using namespace std;
//Integers
//bool, char, shot, int, long, long long

//Reals
//float, double, long double

int main() {
    pow
    const int w = 22;

    signed short signedShort = 10000;
    unsigned short unsignedShort = 10000;
    
    signed int signedInt = 10000;
    unsigned int unsignedInt = 10000;

    signed long signedLong = 10000;
    unsigned long unsignedLong = 10000;

    signed long long signedLongLong = 10000;
    unsigned long long unsignedLongLong = 10000;

    float myFloat = 100.00;
    double myDouble = 100e23;
    long double myLongDouble = 100.00;

    cout << setw(w) << "Type"
         << setw(w) << "Size (bytes)"
         << setw(w) << "Content"
         << setw(w) << "Precision"
         << setw(w) << "Minimum"
         << setw(w) << "Maximum"
         << setw(w) << "Bigger value"
         << setw(w) << "Maximum + 1" << scientific << endl;
    cout << string(w*8, '-') << endl;

    cout << setw(w) << "signed short"
         << setw(w) << sizeof(signedShort)
         << setw(w) << signedShort
         << setw(w) << "-"
         << setw(w) << numeric_limits<short>::min()
         << setw(w) << numeric_limits<short>::max()
         << setw(w) << (short)1000000000000000000
         << setw(w) << short(numeric_limits<short>::max() + 1) << endl;

    cout << setw(w) << "unsigned short"
         << setw(w) << sizeof(unsignedShort)
         << setw(w) << unsignedShort
         << setw(w) << "-"
         << setw(w) << numeric_limits<unsigned short>::min()
         << setw(w) << numeric_limits<unsigned short>::max()
         << setw(w) << (unsigned short)1000000000000000000
         << setw(w) << (unsigned short)(numeric_limits<unsigned short>::max() + 1) << endl;

    cout << setw(w) << "signed int"
         << setw(w) << sizeof(signedInt)
         << setw(w) << signedInt
         << setw(w) << "-"
         << setw(w) << numeric_limits<signed int>::min()
         << setw(w) << numeric_limits<signed int>::max()
         << setw(w) << (signed int)1000000000000000000
         << setw(w) << (signed int)(numeric_limits<signed int>::max() + 1) << endl;

    cout << setw(w) << "unsigned int"
         << setw(w) << sizeof(unsignedInt)
         << setw(w) << unsignedInt
         << setw(w) << "-"
         << setw(w) << numeric_limits<unsigned int>::min()
         << setw(w) << numeric_limits<unsigned int>::max()
         << setw(w) << (unsigned int)1000000000000000000
         << setw(w) << (unsigned int)(numeric_limits<unsigned int>::max() + 1) << endl;

    cout << setw(w) << "signed long"
         << setw(w) << sizeof(signedLong)
         << setw(w) << signedLong
         << setw(w) << "-"
         << setw(w) << numeric_limits<signed long>::min()
         << setw(w) << numeric_limits<signed long>::max()
         << setw(w) << (signed long)1000000000000000000
         << setw(w) << (signed long)(numeric_limits<signed long>::max() + 1) << endl;

    cout << setw(w) << "unsigned long"
         << setw(w) << sizeof(unsignedLong)
         << setw(w) << unsignedLong
         << setw(w) << "-"
         << setw(w) << numeric_limits<unsigned long>::min()
         << setw(w) << numeric_limits<unsigned long>::max()
         << setw(w) << (unsigned long)1000000000000000000
         << setw(w) << (unsigned long)(numeric_limits<unsigned long>::max() + 1) << endl;

    cout << setw(w) << "signed long long"
         << setw(w) << sizeof(signedLongLong)
         << setw(w) << signedLongLong
         << setw(w) << "-"
         << setw(w) << numeric_limits<signed long long>::min()
         << setw(w) << numeric_limits<signed long long>::max()
         << setw(w) << (signed long long)100000000000000000000
         << setw(w) << (signed long long)(numeric_limits<signed long long>::max() + 1) << endl;

    cout << setw(w) << "unsigned long long"
         << setw(w) << sizeof(unsignedLongLong)
         << setw(w) << unsignedLongLong
         << setw(w) << "-"
         << setw(w) << numeric_limits<unsigned long long>::min()
         << setw(w) << numeric_limits<unsigned long long>::max()
         << setw(w) << (unsigned long long)100000000000000000000
         << setw(w) << (unsigned long long)(numeric_limits<unsigned long long>::max() + 1) << endl;

    cout << setw(w) << "float"
         << setw(w) << sizeof(myFloat)
         << setw(w) << myFloat
         << setw(w) << FLT_MANT_DIG
         << setw(w) << numeric_limits<float>::min()
         << setw(w) << numeric_limits<float>::max()
         << setw(w) << (float)100000000000000000000
         << setw(w) << (float)(numeric_limits<float>::max() + 1) << endl;

    cout << setw(w) << "double"
         << setw(w) << sizeof(myDouble)
         << setw(w) << myDouble
         << setw(w) << DBL_MANT_DIG
         << setw(w) << numeric_limits<double>::min()
         << setw(w) << numeric_limits<double>::max()
         << setw(w) << (double)100000000000000000000
         << setw(w) << (double)(numeric_limits<double>::max() + 1) << endl;

    cout << setw(w) << "long double"
         << setw(w) << sizeof(myLongDouble)
         << setw(w) << myLongDouble
         << setw(w) << LDBL_MANT_DIG
         << setw(w) << numeric_limits<long double>::min()
         << setw(w) << numeric_limits<long double>::max()
         << setw(w) << (long double)100000000000000000000
         << setw(w) << (long double)(numeric_limits<long double>::max() + 1) << endl;

    system("pause");
    return 0;
}