/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : codage.cpp
 Auteur(s)   : Robin Müller
 Date        : 08.01.2019

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include "codage.h"

using namespace std;

char calculCar(char car, int val);

string encoder(const string& message, const vector<int>& cle) {
    string messageEncoder;
    size_t tailleCle = cle.size();

    //On decale chaque caractère de la chaine par la valeur de la clé en position i % tailleCle
    //Grâce au modulo, la clé peut être plus petite que le message
    for (size_t i = 0; i < message.size(); ++i) {
        messageEncoder += calculCar(message.at(i), cle.at(i % tailleCle));
    }

    return messageEncoder;
}

string decoder(const string& message, const vector<int>& cle) {
    //Le décodage fonctionne de la même façon que l'encodage mais en inversant le signe de la clé
    return encoder(message, inverserCle(cle));
}

vector<int> inverserCle(const vector<int> &cle) {
    vector<int> cleInverse = cle;

    for(int& i: cleInverse) {
        i *= -1;
    }

    return cleInverse;
}

char calculCar(char car, int val) {
    static const char CAR_MIN = ' ',
                      CAR_MAX = '~';

    //On calcul la nouvelle valeur en int afin de ne pas perdre d'informations
    int newCar = car + val;

    //On veut seulement des valeurs entre [space] et [~] (caractères imprimables)
    if (newCar >= CAR_MIN and newCar <= CAR_MAX)
        return (char)newCar;
    //Si la valeur est superieur au car max -> on passe au car min
    else if (newCar > CAR_MAX) {
        //On commence par obtenir une valeur partant de 0 (au lieu de 32 = [space]) grâce
        //à la première soustraction, ensuite on obtient un nombre de valeurs finies
        //puis on décale les valeurs avec le min
        return (char)((newCar - CAR_MIN) % (CAR_MAX - CAR_MIN + 1) + CAR_MIN);
    //Sinon on passe du car min au car max
    } else {
        //On part depuis le maximum puis on décale la valeur
        return (char)(CAR_MAX - (CAR_MIN - 1 - newCar) % (CAR_MAX - CAR_MIN + 1));
    }
}