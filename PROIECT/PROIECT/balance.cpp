#include <iostream>
#include <fstream>
#include <windows.h>
#include "balance.h"
using namespace std;

// ================= FILE =================

// load balance
double loadBalance() {
    ifstream balanceFileIN("balance.txt");
    double balance = 1000;

    if (balanceFileIN.is_open()) {
        balanceFileIN >> balance;
        balanceFileIN.close();
    }

    return balance;
}

// save balance
void saveBalance(double balance) {
    ofstream balanceFileOUT("balance.txt");

    if (balanceFileOUT.is_open()) {
        balanceFileOUT << balance;
        balanceFileOUT.close();
    }
}

// load stats (player - dealer wins)
void loadStats(int& playerWins, int& dealerWins) {
    ifstream file("stats.txt");
    playerWins = 0;
    dealerWins = 0;
    if (file.is_open()) {
        file >> playerWins >> dealerWins;
        file.close();
    }
}

//save stats
void saveStats(int playerWins, int dealerWins) {
    ofstream file("stats.txt");
    if (file.is_open()) {
        file << playerWins << " " << dealerWins;
        file.close();
    }
}

// ================= BET MENU =================

void bet(double& betAm, double& balance) {
    system("cls");

    int chooseBet;

    while (true) {
        system("cls");

        cout << "Choose the bet, you can enter the same bet multiple times.\n(When u finished press '0' to continue)\n\n";
        cout << "| 1, 5, 10, 25, 50, 100, 250, 500, 1000 |\n\nBalance = " << " $" << balance << "\nBet = " << " $" << betAm << "\n\n-> ";

        cin >> chooseBet;

        if (chooseBet == 0) {
            system("cls");
            return;
        }
        else if (chooseBet == 1 || chooseBet == 5 || chooseBet == 10 || chooseBet == 25 || chooseBet == 50 || chooseBet == 100 || chooseBet == 250 || chooseBet == 500 || chooseBet == 1000) {
            if (balance >= chooseBet) {
                betAm += chooseBet;
                balance -= chooseBet;
            }
            else {
                cout << "\nNot enough balance!";
                Sleep(1500);
            }
        }
        else {
            cout << "\nYou can't use this bet, please choose another one!";
            Sleep(1500);
        }
    }
}
