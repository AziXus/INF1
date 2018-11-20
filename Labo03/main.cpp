/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_03
 Fichier     : main.cpp
 Auteur(s)   : Robin Müller
 Date        : 02.10.2018

 But         : Créer un programme permettant de choisir les éléments d'un repas et
               ensuite affiche le ticket.

 Remarque(s) : -

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream> //cin, cout, ...
#include <iomanip>  //setw, left, right, fixed, setprecision, ...
#include <string>   //string()

using namespace std;

int main() {
    //Constants used for text formatting
    const unsigned int TEXT_WIDTH = 12,
                       PRICES_WIDTH = 6,
                       RECEIPT_WIDTH = 12,
                       RECEIPT_COLUMNS = 4,
                       NUMBERS_PRECISION = 2;

    //Constants defining the prices
    const double STARTER_PRICE = 4.20,
                 MAIN_COURSE_PRICE = 11.00,
                 DRINK_PRICE = 3.00,
                 DESSERT_PRICE = 7.00,
                 COFFEE_PRICE = 2.80;

    unsigned int nbStarters, nbMainCourses, nbDrinks, nbDesserts, nbCoffees;
    double totalPrice = 0.0;

    //Print information
    cout << "The goal of this program is to make an order and then print the receipt.\n\n";

    //Print the list of prices
    cout << setprecision(NUMBERS_PRECISION) << fixed;
    cout << left  << setw(TEXT_WIDTH) << "Starter" << ":"
         << right << setw(PRICES_WIDTH) << STARTER_PRICE     << " Frs.\n";
    cout << left  << setw(TEXT_WIDTH) << "Main course" << ":"
         << right << setw(PRICES_WIDTH) << MAIN_COURSE_PRICE << " Frs.\n";
    cout << left  << setw(TEXT_WIDTH) << "Drink" << ":"
         << right << setw(PRICES_WIDTH) << DRINK_PRICE       << " Frs.\n";
    cout << left  << setw(TEXT_WIDTH) << "Dessert" << ":"
         << right << setw(PRICES_WIDTH) << DESSERT_PRICE     << " Frs.\n";
    cout << left  << setw(TEXT_WIDTH) << "Coffee" << ":"
         << right << setw(PRICES_WIDTH) << COFFEE_PRICE      << " Frs.\n\n";

    //Get the amount of desired items (starters, main courses, drinks, desserts, coffees)
    cout << "How many starters (" << STARTER_PRICE << " Frs.) would you like ? ";
    cin  >> nbStarters;

    cout << "How many main courses (" << MAIN_COURSE_PRICE << " Frs.) would you like ? ";
    cin  >> nbMainCourses;

    cout << "How many drinks (" << DRINK_PRICE << " Frs.) would you like ? ";
    cin  >> nbDrinks;

    cout << "How many desserts (" << DESSERT_PRICE << " Frs.) would you like ? ";
    cin  >> nbDesserts;

    cout << "How many coffees (" << COFFEE_PRICE << " Frs.) would you like ? ";
    cin  >> nbCoffees;

    //Calculate the total price
    totalPrice += nbStarters * STARTER_PRICE;
    totalPrice += nbMainCourses * MAIN_COURSE_PRICE;
    totalPrice += nbDrinks * DRINK_PRICE;
    totalPrice += nbDesserts * DESSERT_PRICE;
    totalPrice += nbCoffees * COFFEE_PRICE;

    //Display the receipt
    //Calculate the number of "-" necessary to be used as a text separator.
    //{Column Width}*{Number of columns}
    string receiptSeparator = string(RECEIPT_WIDTH * RECEIPT_COLUMNS, '-');

    cout << "\nReceipt:\n";
    cout << receiptSeparator << endl;

    //Print headers
    cout << left << setw(RECEIPT_WIDTH) <<  "Article" << right
                 << setw(RECEIPT_WIDTH) <<  "Quantity"
                 << setw(RECEIPT_WIDTH) <<  "Price"
                 << setw(RECEIPT_WIDTH) <<  "Amount\n";

    cout << receiptSeparator << endl;

    //Print ordered items with the article, quantity, price per unit and total
    cout << left << setw(RECEIPT_WIDTH) <<  "Starter" << right
                 << setw(RECEIPT_WIDTH) <<  nbStarters
                 << setw(RECEIPT_WIDTH) <<  STARTER_PRICE
                 << setw(RECEIPT_WIDTH) <<  nbStarters * STARTER_PRICE << endl;
    cout << left << setw(RECEIPT_WIDTH) <<  "Main course" << right
                 << setw(RECEIPT_WIDTH) <<  nbMainCourses
                 << setw(RECEIPT_WIDTH) <<  MAIN_COURSE_PRICE
                 << setw(RECEIPT_WIDTH) <<  nbMainCourses * MAIN_COURSE_PRICE << endl;
    cout << left << setw(RECEIPT_WIDTH) <<  "Drink" << right
                 << setw(RECEIPT_WIDTH) <<  nbDrinks
                 << setw(RECEIPT_WIDTH) <<  DRINK_PRICE
                 << setw(RECEIPT_WIDTH) <<  nbDrinks * DRINK_PRICE << endl;
    cout << left << setw(RECEIPT_WIDTH) <<  "Dessert" << right
                 << setw(RECEIPT_WIDTH) <<  nbDesserts
                 << setw(RECEIPT_WIDTH) <<  DESSERT_PRICE
                 << setw(RECEIPT_WIDTH) <<  nbDesserts * DESSERT_PRICE << endl;
    cout << left << setw(RECEIPT_WIDTH) <<  "Coffee" << right
                 << setw(RECEIPT_WIDTH) <<  nbCoffees
                 << setw(RECEIPT_WIDTH) <<  COFFEE_PRICE
                 << setw(RECEIPT_WIDTH) <<  nbCoffees * COFFEE_PRICE << endl;

    cout << receiptSeparator << endl;
    cout << "Total: " << totalPrice << " Frs." << endl;
    cout << receiptSeparator << endl;

    return EXIT_SUCCESS;
}