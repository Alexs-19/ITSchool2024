#include <iostream>
#include <windows.h>
#include "person.h"
#include "deck.h"

// function to add card to the player - dealer hand
void person::addCard(const card& c) {
    hand.emplace_back(c);
}

// function to get the hand value from the player - dealer
int person::getHandValue() {
    int value = 0;
    for (auto& c : hand) {
        if (c.getRank() == "Jack" || c.getRank() == "Queen" || c.getRank() == "King") value += 10;
        else if (c.getRank() == "Ace") {
            if (value + 11 <= 21) value += 11;
            else value += 1;
        }
        else value += stoi(c.getRank()); // function to turn a string into an integer, stoi -> 's'tring - 'to' - 'i'nteger. Ex: "10" -> 10
    }
    return value;
}

void person::printHand() const {
    for (const auto& c : hand) c.printCard();
}

// function to get the hand size (number of cards in a hand)
int player::getHandSize() const {
    return hand.size();
}

// here it starts the player turn
bool player::playerTurn(deck& d, bool& blackjack, double& balance) {
    char choice;

    cout << "P";
    Sleep(150);
    cout << "l";
    Sleep(150);
    cout << "a";
    Sleep(150);
    cout << "y";
    Sleep(150);
    cout << "e";
    Sleep(150);
    cout << "r";
    Sleep(150);
    cout << " ";
    Sleep(150);
    cout << "h";
    Sleep(150);
    cout << "a";
    Sleep(150);
    cout << "n";
    Sleep(150);
    cout << "d";
    Sleep(150);
    cout << ":\n";
    Sleep(250);

    while (true) {
        printHand();
        cout << "Value: " << getHandValue() << endl;

        if (getHandValue() > 21) return false; // If player hand value is > 21, player bust
        else if (getHandSize() == 2 && getHandValue() == 21) {
            cout << "\nBlackJack!\n";
            blackjack = true;
            return true;
        }
        else {
            cout << "\nDo you want to [H]it or [S]tand?\n\n-> ";
            cin >> choice;

            if (choice == 'H' || choice == 'h') {
                addCard(d.dealCard());

                Sleep(250);

                if (getHandValue() > 21) {
                    cout << endl;
                    printHand();
                    cout << "Value: " << getHandValue() << endl;
                    Sleep(1000);
                    return false;
                }

                cout << endl;
            }

            else if (choice == 'S' || choice == 's') return true;
            else cout << "Invalid input! Enter 'H' to hit or 'S' to stand.\n";
        }
    }
}

void dealer::revealFirstCard() {
    hand[0].printCard();
    int value = (hand[0].getRank() == "Ace") ? 11 : (hand[0].getRank() == "Jack" || hand[0].getRank() == "Queen" || hand[0].getRank() == "King") ? 10 : stoi(hand[0].getRank());
    cout << "Hidden card\nValue: " << value;
}

// here it starts the dealer turn
void dealer::dealerTurn(deck& d) {
    cout << endl;
    hand[0].printCard();
    Sleep(1000);
    cout << "Hidden card -> ";
    hand[1].printCard();
    Sleep(1000);

    // while the hand value is < 16 the dealer will take cards from the deck until the value will be > 16
    while (getHandValue() < 16) {
        card newCard = d.dealCard();
        addCard(newCard);
        newCard.printCard();
        Sleep(1000);
    }

    cout << "Value: " << getHandValue() << endl;
}