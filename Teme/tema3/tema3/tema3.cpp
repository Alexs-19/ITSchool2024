#include <iostream>
#include <string>
using namespace std;


void ex1() //ex1, array
{
    int ar[] = { 2, 5, 8, 12 };
    int* pAr = ar;

    for (int i = 0; i < 4; i++)
    {
        cout << *(pAr + i) << endl;
    }
}

void ex2() //ex2, factorial
{
    long long int n, tot = 1;
    long long int* pTot = &tot;

    cout << "Alege un numar: ";

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        *pTot *= i;
    }

    cout << "Factorialul numarului este: " << *pTot;
}

void ex3() //ex3, nr vocale-consoane
{
    int voc = 0, cons = 0;

    int* pVoc = &voc;
    int* pCons = &cons;

    string sir;

    cout << "Introdu diferite litere\n\n";

    cin.ignore();
    getline(cin, sir);

    for (int i = 0; i < sir.length(); i++)
    {
        if (sir[i] == 'a' || sir[i] == 'e' || sir[i] == 'i' || sir[i] == 'o' || sir[i] == 'u' || sir[i] == 'A' || sir[i] == 'E' || sir[i] == 'I' || sir[i] == 'O' || sir[i] == 'U')
        {
            (*pVoc)++;
        }
        else (*pCons)++;
    }

    cout << "\nvocale: " << *pVoc << endl;
    cout << "consoane: " << *pCons << endl;
}

void ex4() //ex4 array sort
{
    int a, temp;

    cout << "Introdu nr de elemente: ";

    cin >> a;

    int* arr = new int[a];

    cout << "Introdu elementele:\n\n";

    for (int i = 0; i < a; i++)
    {
        cin >> arr[i];
    }

    cout << endl;

    for (int i = 0; i < a - 1; i++)
    {
        for (int j = 0; j < a - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }
        }
    }

    cout << "Acestea sunt elementele in ordine:\n\n";

    for (int i = 0; i < a; i++) cout << arr[i] << endl;
}

int main()
{
    cout << "Ex 1:\n\n";
    ex1();
    cout << "\n---------------------\n\nEx 2:\n\n";
    ex2();
    cout << "\n\n---------------------\n\nEx 3:\n\n";
    ex3();
    cout << "\n---------------------\n\nEx 4:\n\n";
    ex4();

    return 0;
}