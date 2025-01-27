#include <iostream>;
#include <string>;
using namespace std;

int my_func_rezolvare_ex123(int myNumber, float myNumber1)
{
	cout << myNumber << endl << myNumber1 << endl;

	myNumber++; //ex 3
	myNumber1--;

	cout << endl << myNumber << endl << myNumber1 << "\n\n----------------------------------------";

	return myNumber;
}

float my_func_rezolvare_ex45(int myNumber, float myNumber1)
{
	int suma = myNumber + myNumber1; //ex 4
	float sumareal = myNumber + myNumber1;

	cout << suma << endl << sumareal << "\n";

	suma = (suma * 5) / 12; //ex 5
	sumareal = (sumareal * 5) / 12;

	int rest1 = suma + sumareal;
	float rest = suma + sumareal;

	cout << endl << rest; //suma totala
	rest = (suma + sumareal) - rest1;
	cout << endl << rest << "\n\n----------------------------------------"; //partea fractionala

	return rest;
}

string my_func_rezolvare_ex6789(string nume, string prenume)
{
	string nume_complet = nume + " " + prenume; //ex 8

	cout << nume_complet;

	string sirul_meu = "\n\nAcesta este continutul initial al sirului\n\n----------------------------------------"; //ex 9

	cout << sirul_meu;

	return sirul_meu;
}

void my_func_rezolvare_ex10_12_13()
{
	unsigned int a = 7, b = 9, c = 3;
	unsigned int a1 = 72.3, b1 = 1387.12344, c1 = 6; //nu pot sa declar o variabila de tip "float" sau "double" fara semn

	unsigned int mic = (a < b && a < c) * a + (b < a && b < c) * b + (c < a && c < b) * c; //ex 10a

	cout << "Numarul cel mai mic este: " << mic << "\n\n";

	unsigned int mare = (a1 > b1 && a1 > c1) * a1 + (b1 > a1 && b1 > c1) * b1 + (c1 > a1 && c1 > b1) * c1;

	cout << "Numarul cel mai mare este: " << mare << "\n\n"; //ex 10b

	const float a2 = 23.6;
	//a2 *= 72  este constanta si nu se poate modifica
	float mare1 = (a2 > 1500.3) * a2 + (1500.3 > a2) * 1500.3;

	cout << "Numarul cel mai mare este: " << mare1 << "\n\n"; //ex 12

	unsigned int y = 2379.8909, z = 11.4, k; //nu pot sa declar o variabila de tip "float" sau "double" fara semn
	k = y / z;

	cout << k << "\n\n----------------------------------------";
}

int main()
{
	int myNumber = 50; //ex 1
	float myNumber1 = 75.5; // ex 2

	string nume = "Stoian", prenume = "Alex"; //ex 6, 7

	cout << "Ex 1, 2, 3:\n\n";
	my_func_rezolvare_ex123(myNumber, myNumber1);

	cout << "\n\nEx 4, 5:\n\n";
	my_func_rezolvare_ex45(myNumber, myNumber1);

	cout << "\n\nEx 6, 7, 8, 9:\n\n";
	my_func_rezolvare_ex6789(nume, prenume);

	cout << "\n\nEx 10a-b, 12, 13:\n\n";
	my_func_rezolvare_ex10_12_13();

	cout << "\n\nEx 14: Varianta corecta este -varianta 2- deoarece semnul '!' transforma expresia (a<=3 || a>=15) in (a>=3 || a<=15), echivalent cu expresia data de sus.\n\n";

	//Ex 15 nu am stiut sa il fac

	return 0;
}
