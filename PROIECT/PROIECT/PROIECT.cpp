#include <iostream>
#include <windows.h>
#include "deck.h"
#include "person.h"
#include "balance.h"

// ================= COLOR =================

// function to set the color of text
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// ================= LOADING =================

// function for the "loading dots" animation, ex: starting game"..." <-
void loadingDots(string text, int dotCount) {
    cout << text;
    setColor(14);
    for (int i = 0; i < dotCount; i++) {
        Sleep(500);
        cout << ".";
    }
    setColor(15);
    Sleep(100);
}

// ================= GAME =================

void startGame(int& playerWins, int& dealerWins, double& balance) {
    double betAm = 0; // bet amount variable
    bet(betAm, balance); // bet menu to choose the bet to play

    deck deck; // creating the deck of cards

    deck.shuffleDeck(); // shuffle deck function

    player p; // creating the player
    dealer d; // creating the dealer

    // Add 2 cards to the player
    p.addCard(deck.dealCard());
    p.addCard(deck.dealCard());

    // Add 2 cards to the dealer
    d.addCard(deck.dealCard());
    d.addCard(deck.dealCard());

    cout << "Balance: " << " $" << balance;
    cout << " | Bet amount: " << " $" << betAm << "\n\n";

    cout << "Dealer's Hand:\n";
    d.revealFirstCard(); // function to reaveal the first card of the dealer (the second one is hidden)
    cout << "\n\n----------------\n\n";

    bool blackjack = false;

    // condition to check if the player busts (lose)
    if (!p.playerTurn(deck, blackjack, balance)) {
        cout << "\nPlayer busts! Dealer wins.\n";
        dealerWins++;
    }
    else { // if the player did not busts then its the dealer turn
        d.dealerTurn(deck);

        int playerValue = p.getHandValue(); // taking the cards value from the player hand
        int dealerValue = d.getHandValue(); // taking the cards value from the dealer hand

        // condition to check who wins
        if (dealerValue > 21 || playerValue > dealerValue) {
            cout << "\nPlayer wins! ";
            if (blackjack) {
                cout << "You win $" << betAm * 2.5 << endl;
                playerWins++;
                balance += betAm * 2.5;
            }
            else {
                cout << "You win $" << betAm * 2 << endl;
                playerWins++;
                balance += betAm * 2;
            }
        }
        else if (playerValue == dealerValue) {
            cout << "\nIt's a tie! Your bet is returned\n";
        }
        else {
            cout << "\nDealer wins!\n";
            dealerWins++;
        }
    }

    saveBalance(balance); // function to save the balance
    saveStats(playerWins, dealerWins); // function to save the stats (player wins - dealer wins)

    int choice;

    // menu layout after the game ends
    while (true) {
        cout << "\n(1) Play again\n(2) Return to menu\n\n-> ";
        cin >> choice;

        if (choice == 1) {
            system("cls"); // clear the terminal

            loadingDots("starting game", 3);

            system("cls");

            startGame(playerWins, dealerWins, balance); // start the game again

            return;
        }
        else if (choice == 2) {
            system("cls");

            loadingDots("returning to menu", 3);

            system("cls");

            return;
        }
        else cout << "Invalid input!";
    }
}

// ================= MENU =================

int main()
{
    int choice;
    int playerWins, dealerWins;
    double balance = loadBalance();
    loadStats(playerWins, dealerWins);

    while (true) {
        setColor(4);
        cout << "Welcome to the BlackJack game!\n\n";
        setColor(15);
        cout << "Choose an option:\n(1) Start game.\n(2) See stats.\n(3) Rules.\n(4) Exit.\n\n";
        cout << "-> ";
        cin >> choice;

        if (choice == 1) {
            system("cls");

            loadingDots("starting game", 3);

            system("cls");

            startGame(playerWins, dealerWins, balance);
        }
        else if (choice == 2) {
            system("cls");

            cout << "Player Wins: " << playerWins << endl;
            cout << "Dealer Wins: " << dealerWins << endl;
            cout << "Balance: $" << balance << endl;

            cout << "\n(1) Return to menu\n\n-> ";

            while (true) {
                cin >> choice;
                if (choice == 1) {
                    system("cls");
                    break;
                }
                else {
                    cout << "Invalid option. Please enter (1) to return to the menu: ";
                }
            }
        }
        else if (choice == 3) {
            system("cls");
            cout << "=== Blackjack Rules ===\n\n";
            cout << "1. Card Values:\n";
            cout << "   - Number cards (2-10): Face value (ex., 2 is worth 2, 7 is worth 7).\n";
            cout << "   - Face cards (J, Q, K): Each is worth 10.\n";
            cout << "   - Ace: Can be worth 1 or 11, whichever can fit in the hand.\n\n";

            cout << "2. Objective:\n";
            cout << "   - Try to get as close to 21 as possible, but without exceeding it.\n";
            cout << "   - If you go over 21, you 'bust' and lose.\n";
            cout << "   - A Blackjack is an Ace and a 10 - value card (10, Jack, Queen, King) - the best possible hand.\n\n";

            cout << "3. Game Setup:\n";
            cout << "   - Players are dealt two cards face - up. The dealer has one card face - up (upcard) and one face - down (hidden card).\n";
            cout << "   - Players can 'Hit' (take another card), 'Stand' (keep their hand).\n\n";

            cout << "4. Dealer's Turn:\n";
            cout << "   - The dealer must hit till the hand values is <= 16, after 16 the game will declare the winner.\n";

            cout << "5. Winning and Payouts:\n";
            cout << "   - If your hand is closer to 21 than the dealer's, you win.\n";
            cout << "   - If you get a Blackjack (Ace and a 10 - value card), you win 1.5 times your bet.\n";
            cout << "   - Regular wins pay 1:1.\n\n";

            cout << "=== End of Rules ===\n\n";

            cout << "Press (0) to return to the menu: ";

            char input;

            while (true) {
                cin >> input;
                if (input == '0') {
                    system("cls");
                    break;
                }
                else {
                    cout << "Invalid input. Please press 0 to return to the menu: ";
                }
            }
        }
        else if (choice == 4) break;
        else cout << "Invalid input!\n";
    }

    return 0;
}