#include <iostream>
#include <string>
#include <random>
#include <iomanip>
using namespace std;


int main()
{
    srand(time(NULL));

    int cdt[5] = { 0 }, vot, rd;
    double procent;

    cout << "Introduceti nr. de voturi: ";
    cin >> vot;

    for (int i = 0; i < vot; i++)
    {
        rd = rand() % 5;
        cdt[rd]++;
    }

    cout << fixed << setprecision(2);

    for (int i = 0; i < 5; i++)
    {
        procent = (static_cast<double>(cdt[i]) / vot) * 100;
        cout << "candidatul " << i + 1 << ": " << cdt[i] << " voturi | " << procent << "%" << endl;
    }


    return 0;
}

//ex 2 din pacate n am stiut sa il fac