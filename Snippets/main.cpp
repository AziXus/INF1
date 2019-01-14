#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cmath>
#include <limits>
#include <vector>

#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

bool estUnNombre(const string& str) {
    //Caractère '0' (plus petit chiffre)
    static const char CAR_ZERO    = '0', //static afin de l'initialiser qu'une seule fois
                      CAR_POSITIF = '+',
                      CAR_NEGATIF = '-';

    if (str.empty())
        return false;
    else if (str.size() == 1 and
            (str[0] == CAR_POSITIF or str[0] == CAR_NEGATIF))
        return false;


    //boucle parcourant la chaîne de caractère
    for (char c: str) {
        //CAR_ZERO + 9 correspond au caractère '9'
        if (c != CAR_POSITIF and c != CAR_NEGATIF and (c < CAR_ZERO or c > CAR_ZERO + 9))
            return false;
    }

    return true;
}

vector<int> stringSplit(const string& str, char delimiteur) {
    vector<int> splitValues;
    string splitString;

    //On parcours les caractères de la chaine
    for (char c: str) {
        //On concat si différent du dénominateur
        if (c != delimiteur)
            splitString += c;
        //Sinon on ajoute une case on vecteur si c'est un entier
        else {
            if (estUnNombre(splitString))
                splitValues.push_back(stoi(splitString));
            splitString = "";
        }
    }

    //On verifie s'il reste une valeur dans splitValues
    if (estUnNombre(splitString))
        splitValues.push_back(stoi(splitString));

    return splitValues;
}

bool isAllOdd(const vector<int>& v);
vector<int> concat(const vector<int>& v1, const vector<int>& v2);
vector<int> alternateMerge(const vector<int>& v1, const vector<int>& v2);
string vectorToString(const vector<int>& v);
vector<vector<char>> generateCharMatrix();
string matrixToString(const vector<vector<char>>& v);

int main() {
    string str;

    cout << "Entrer une ligne : ";
    getline(cin, str);
    cout << "Valeur split : ";
    vector<int> v = stringSplit(str, ' ');
    for (int i: v)
        cout << i << endl;

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