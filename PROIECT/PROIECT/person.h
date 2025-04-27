#pragma once
#include <vector>
#include "card.h"

class person {
public:
    vector<card> hand; // vector to hold the player cards

    void addCard(const card& c);
    int getHandValue();
    void printHand() const;
};

class player : public person {
public:
    int getHandSize() const;
    bool playerTurn(class deck& d, bool& blackjack, double& balance);
};

class dealer : public person {
public:
    void revealFirstCard();
    void dealerTurn(class deck& d);
};