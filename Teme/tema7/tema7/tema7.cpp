#include <iostream>
#include <string>
#include <vector>
using namespace std;

//EX. 1
class myclass {
private:
	string name;
	vector<int> data;
public:
	myclass(const string& n, int size) : name(n), data(size, 0) {
		cout << "constructor standard apelat\n";
	}

	myclass(const string& n) : myclass(n, 10) {
		cout << "constructor delegant apelat\n";
	}

	myclass(myclass&& source) : name(source.name), data(source.data) {
		cout << "move constructor apelat\n";
	}

	void print() {
		cout << "name: " << name << "\ndata: ";
		for (int i = 0; i < data.size(); i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
};

//EX. 2
class point {
private:
	int x;
	int y;
public:
	point(int x = 0, int y = 0) : x(x), y(y){}

	point operator+(const point& source) const {
		return point(x + source.x, y + source.y);
	}

	void print() {
		cout << "(" << x << ", " << y << ")\n";
	}
};

//EX. 3
class myclass2 {
private:
	int* value;
public:
	myclass2(int v) : value(new int(v)) {
		cout << "constructor default apelat\n";
	}

	myclass2(const myclass2& source) : value(new int(*source.value)) {
		cout << "constructor de copiere apelat\n";
	}

	void print2() {
		cout << "value: " << *value << endl;
	}
};

int main()
{
	//EX. 1
	myclass obj1("Test", 5); //constructor standard
	obj1.print();

	myclass obj2("Another test"); //constructor delegant
	obj2.print();

	myclass obj3 = move(obj1); //move constructor
	obj3.print();

	cout << "\n---------------------\n\n";

	//EX. 2
	point p1(2, 4);
	point p2(1, 5);

	point p3 = p1 + p2;

	cout << "punctul 1: ";
	p1.print();

	cout << "punctul 2: ";
	p2.print();

	cout << "punctul 3: ";
	p3.print();

	cout << "\n---------------------\n\n";

	//EX. 3
	myclass2 ob1(10);
	ob1.print2();

	myclass2 ob2 = ob1;
	ob2.print2();

	return 0;
}