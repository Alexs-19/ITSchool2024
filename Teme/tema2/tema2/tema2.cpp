#include <iostream>
using namespace std;

bool ex1()
{
	int n;
	bool prim = 1;

	cout << "Ex. 1\n\n" << "Introduce un numar: ";

	while (prim)
	{
		cin >> n;

		if (n == 0 || n == 1) cout << "Numarul 0 si 1 nu poate fi prim\n";
		else if (n > 1) prim = 0;
	}

	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			prim = 0;
		}
	}

	if (prim) cout << "Numarul este prim";
	else cout << "Numarul nu este prim";

	return prim;
}

void ex2()
{
	int a, b, rest;

	cout << "Ex. 2\n\n" << "Introduce doua numere:\n";

	cin >> a >> b;

	while (b != 0)
	{
		rest = a % b;
		a = b;
		b = rest;
	}

	cout << "Cel mai mare divizor comun este " << a;
}

void ex3()
{
	int in;
	double tot = 0, plata;
	bool magazin = 1;

	cout << "Ex. 3\n\n" << "Alege produsele dorite, 'apasa 0 pentru a plati'\n\n";

	cout << "1. Lapte\n" << "2. Paine\n" << "3. Oua\n" << "4. Zahar\n" << "5. Faina\n";
	cout << "6. Cafea\n" << "7. Ulei\n" << "8. Paste\n" << "9. Orez\n" << "10. Suc\n";
	cout << "11. Cereale\n" << "12. Branza\n" << "13. Iaurt\n" << "14. Ciocolata\n" << "15. Mere\n";
	cout << "16. Ananas\n" << "17. Bere\n" << "18. Hartie\n" << "19. Unt\n" << "20. Miere\n\n";

	while (magazin)
	{
		cin >> in;

		switch (in)
		{
		case 1: tot += 5.99; break;
		case 2: tot += 2.99; break;
		case 3: tot += 11.99; break;
		case 4: tot += 4.99; break;
		case 5: tot += 3.99; break;
		case 6: tot += 19.99; break;
		case 7: tot += 8.99; break;
		case 8: tot += 5.99; break;
		case 9: tot += 6.99; break;
		case 10: tot += 7.99; break;
		case 11: tot += 14.99; break;
		case 12: tot += 24.99; break;
		case 13: tot += 1.99; break;
		case 14: tot += 6.99;
		case 15: tot += 3.99; break;
		case 16: tot += 2.99; break;
		case 17: tot += 7.99; break;
		case 18: tot += 1.99; break;
		case 19: tot += 9.99; break;
		case 20: tot += 13.99; break;
		default: if (in == 0) break;
		}

		if (in > 20) cout << "Nu mai avem in stock\n";
		else if (in == 0) magazin = 0;
	}

	cout << "\nSuma totala este: " << tot << "\n" << "";

	do
	{
		cin >> plata;
		if (plata < tot) cout << "Nu este destul\n\n";

	} while (plata < tot);

	cout << "\nRestul: " << plata - tot << "\n\n";
}


int main()
{
	ex1();
	cout << "\n\n------------------------\n\n";
	ex2();
	cout << "\n\n------------------------\n\n";
	ex3();


	return 0;
}