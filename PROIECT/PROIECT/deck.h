#pragma once
#include <vector>
#include "card.h"

class deck {
    vector<card>cards; // vector to hold all the 52 cards

    string suit[4] = { "Diamonds", "Clubs", "Hearts", "Spades" };
    string rank[13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
public:
    deck();
    void shuffleDeck();
    card dealCard();
    void printDeck() const;
};