#include <iostream>
#include <string>
#include <vector>
using namespace std;
//EX. 1
class cutie {
    int lung;
    int lat;
    int inal;
public:
    cutie(int L, int l, int h) : lung(L), lat(l), inal(h) {}

    void print() {
        cout << "lungimea: " << lung << ", latimea: " << lat << ", inaltimea: " << inal << "\n\n";
    }
    friend class calcul;
};

class calcul {
public:
    int volum(cutie c) {
        return c.lung * c.lat * c.inal;
    }

    void modificare(cutie &c, int L, int l, int h) {
        c.lung = L;
        c.lat = l;
        c.inal = h;
    }
};

//EX. 2
class persoana {
    string nume;
    int varsta;
public:
    persoana(string n, int v) : nume(n), varsta(v) {}

    void print() {
        cout << "nume: " << nume << ", varsta: " << varsta << "\n\n";
    }
};

class angajat : public persoana {
    string job;
public:
    angajat(string n, int v, string j) : persoana(n, v), job(j) {}

    void printjob() {
        cout << "job: " << job << endl;
    }
};

int main()
{
    //EX. 1
    cutie cutiamica(2, 5, 6);
    cutiamica.print();

    calcul calc;
    cout << "volumul initial: " << calc.volum(cutiamica) << endl;

    calc.modificare(cutiamica, 12, 9, 2);
    cout << "\ndimensiuni dupa modificare: ";
    cutiamica.print();

    cout << "volum nou: " << calc.volum(cutiamica) << "\n\n-------------------------\n\n";

    //EX. 2

    angajat ang("Stoian Alex", 18, "programator");

    ang.print();

    ang.printjob();


    return 0;
}