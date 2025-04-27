#include <random>
#include <algorithm>
#include "deck.h"

// deck constructor
deck::deck() { 
    // for loop to add cards to the deck
    for (auto& s : suit) {
        for (auto& r : rank) {
            cards.emplace_back(r, s);
        }
    }
}

// function to shuffle the deck using the mt19937 class pseudo-random number generator
void deck::shuffleDeck() {
    random_device rd;
    mt19937 rng(rd());
    shuffle(cards.begin(), cards.end(), rng);
}

// functio to deal card to the player - dealer
card deck::dealCard() {
    card dealtCard = cards.back();
    cards.pop_back();
    return dealtCard;
}

// optional function to print the deck
void deck::printDeck() const {
    for (auto& c : cards)
        c.printCard();
}