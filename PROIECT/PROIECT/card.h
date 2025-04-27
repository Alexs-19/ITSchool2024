#pragma once
#include <string>
using namespace std;

class card {
    string rank;
    string suit;
public:
    card(string r, string s);

    string getRank() const;

    void printCard() const;
};