#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct zi //ex1
{
    string nume;
    double temp;
};

void ex1()
{
    srand(time(0));

    vector<zi>sapt = { { "luni", 0 }, { "marti", 0 }, { "miercuri", 0 }, { "joi", 0 }, { "vineri", 0 }, { "sambata", 0 }, { "duminica", 0 } };

    //temperatura random
    for (int i = 0; i < 7; i++)
    {
        sapt[i].temp = (rand() % 251) / 10 - 5;
        cout << sapt[i].nume << ": " << sapt[i].temp << "\370" << endl;
    }

    int maxtemp = sapt[0].temp;

    //temperatura maxima
    for (int i = 1; i < 7; i++)
    {
        if (sapt[i].temp > maxtemp)
        {
            maxtemp = sapt[i].temp;
        }
    }

    cout << "\nZilele cu temperatura maxima de " << maxtemp << "\370" << " sunt: ";

    for (int i = 0; i < 7; i++)
    {
        if (sapt[i].temp == maxtemp)
        {
            cout << sapt[i].nume << " ";
        }
    }

    cout << "\n";
}

class Angajat //ex2
{
private:

    string nume, email;
    float salariu, ore;


public:

    void dateAngajat()
    {
        nume = "Alex";
        email = "itschool2024@gmail.com";
    }

    float getSalariu()
    {
        cout << "\n\nNumar de ore lucrate?\nNr. ore: ";
        cin >> ore;
        salariu = ore * 26; //salariu mediu

        return salariu;
    }

    void display() { cout << "\n\nNume: " << nume << "\nEmail: " << email << "\nSalariu: " << salariu << " RON/ora\n\n"; }
};

int main()
{
    ex1();

    Angajat angajat1;
    angajat1.dateAngajat();
    angajat1.getSalariu();
    angajat1.display();

    return 0;
}