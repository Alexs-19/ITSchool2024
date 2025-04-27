#include <iostream>
#include "card.h"

card::card(string r, string s) : rank(r), suit(s) {} // card constructor

string card::getRank() const { // function to get the rank of a card
    return rank;
}

void card::printCard() const { // function to print a card
    cout << rank << " of " << suit << endl;
}