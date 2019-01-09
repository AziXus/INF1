#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cmath>
#include <limits>
#include <vector>

#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swapTillOdd(int tab[], size_t taille, size_t pos) {
    while (pos - 1 < taille and tab[pos - 1] % 2 == 0) {
        swap(tab[pos], tab[pos-1]);
        --pos;
    }
}

void sort(int tab[], size_t taille) {
    for (size_t i = 1; i < taille; ++i) {
        if (tab[i] % 2 == 0) {
        } else {
            swapTillOdd(tab, taille, i);
        }
    }
}

bool isAllOdd(const vector<int>& v);
vector<int> concat(const vector<int>& v1, const vector<int>& v2);
vector<int> alternateMerge(const vector<int>& v1, const vector<int>& v2);
string vectorToString(const vector<int>& v);
vector<vector<char>> generateCharMatrix();
string matrixToString(const vector<vector<char>>& v);

int main() {
    cout << (unsigned char)(179);
    /*
    int tab[] = {6, 1, 2, 2, 2, 2, 4, 5, 6, 7, 8};
    unsigned taille = sizeof(tab) / sizeof(int);
    unsigned capacite = 7;
    sort(tab, taille);

    for (int i = 0; i < taille; ++i) {
        cout << tab[i] << endl;
    }

    vector<int> a = {1, 3};
    vector<int> b = {2, 4, 5};

    vector<int> c = concat(a, b);
    vector<int> d = alternateMerge(a, b);

    cout << "append(" << vectorToString(a) << ", " << vectorToString(b) << ") = " << vectorToString(c) << endl;
    cout << " merge(" << vectorToString(a) << ", " << vectorToString(b) << ") = " << vectorToString(d) << endl;

    vector<vector<char>> alpha = generateCharMatrix();
    cout << endl << "matrix : " << endl << matrixToString(alpha) << endl;


    const size_t N = 5;
    int t[] = { 1, 3, 5, 7, 9};
    for (int i = N; i > 0; --i) {
        t[i - 1] = ++t[N - i];
    }
*/
    return EXIT_SUCCESS;
}

bool isAllOdd(const vector<int>& v) {
    for (int n : v) {
        if (n % 2 == 0)
            return false;
    }

    return true;
}

vector<int> concat(const vector<int>& v1, const vector<int>& v2) {
    vector<int> vConcatenated = v1;
    vConcatenated.insert(vConcatenated.end(), v2.begin(), v2.end());
    return vConcatenated;
}

vector<int> alternateMerge(const vector<int>& v1, const vector<int>& v2) {
    vector<int> vNew;

    size_t size1 = v1.size();
    size_t size2 = v2.size();

    size_t max = size1 > size2 ? size1 : size2;

    for (size_t i = 0; i < max; ++i) {
        if (i < size1) { //insert v1 if in range
            vNew.insert(vNew.end(), v1.at(i));
        }

        if (i < size2) { //insert v2 if in range
            vNew.insert(vNew.end(), v2.at(i));
        }
    }

    return vNew;
}

string vectorToString(const vector<int>& v) {
    string res = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i > 0)
            res += ", ";
        res += to_string(v.at(i));
    }
    res += "]";

    return res;
}

vector<vector<char>> generateCharMatrix() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    size_t size = alphabet.size();

    vector<vector<char>> alphabetMatrix;
    vector<char> charMatrix;

    for (size_t row = 0; row < size; ++row) {
        for (size_t col = 0; col < size - row; ++col) {
            charMatrix.push_back(alphabet[col]);
        }
        alphabetMatrix.push_back(charMatrix);

        charMatrix.clear();
    }

    return alphabetMatrix;
}

string matrixToString(const vector<vector<char>>& v) {
    string res;

    for (const vector<char>& row: v) {
        for (const char& character: row) {
            res += character; 
        }

        res += '\n';
    }
    return res;
}