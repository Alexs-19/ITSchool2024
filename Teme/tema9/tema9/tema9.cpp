#include <iostream>
#include <string>
using namespace std;

class account {
    double balance;
    double saving;
public:
    account(double initialbalance) : balance(initialbalance), saving(0) {
        if (balance > 1000) savings();
    }

    void deposit(double amount) {
        balance += amount;
        if (balance > 1000) savings();
    }

    void withdraw(double amount) {
        if (amount <= balance) balance -= amount;
        else cout << "Insufficient funds" << endl;
    }

    void savings() {
        double temp = balance - 1000;
        saving += temp;
        balance = 1000;
    }

    void print() {
        cout << " | Balance: " << balance << " | Savings: " << saving << "\n\n";
    }
};

class person {
    string name;
    account account;
public:
    person(string name, double initialbalance) : name(name), account(initialbalance) {}

    void deposit(double amount) {
        cout << "Deposting " << amount << " to " << name << " account...\n\n";
        account.deposit(amount);
    }

    void withdraw(double amount) {
        cout << "Withdrawing " << amount << " to " << name << " account...\n\n";
        account.withdraw(amount);
    }

    void accountDetail() {
        cout << "Name: " << name;
        account.print();
    }
};

class employee : public person {
public:
    employee(string name, double initialbalance) : person(name, initialbalance) {}
};

class student : public person {
public:
    student(string name, double initialbalance) : person(name, initialbalance) {}
};

int main()
{
    employee emp("Francesco Totti", 900);
    student stud("Stoian Alex", 1100);

    emp.accountDetail();
    stud.accountDetail();

    emp.deposit(200);
    stud.withdraw(500);

    emp.accountDetail();
    stud.accountDetail();


    return 0;
}