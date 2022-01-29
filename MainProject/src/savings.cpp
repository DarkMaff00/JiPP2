#include <iostream>
#include "savings.h"
#include "user.h"

using namespace std;

Savings::Savings(User logged) : Account(logged) {
    this->status = logged.saving;
    this->balance = logged.balance[1];
    this->ratio = 1.2;
}

void Savings::create() {
    if (check() == 1) {
        cout << "Masz juz rachunek oszczednosciowy." << endl;
    } else {
        string answer;
        cout << "Nie masz jeszcze rachunku oszczednosciowego" << endl;
        cout << "Chcesz go zalozyc? (y/n)" << endl;
        cin >> answer;
        if (answer == "y" || answer == "Y") {
            status = 1;
            update_base(5, 1);
            cout << "Twoj rachunek oszczednosciowy zostal utworzony :)" << endl;
        } else {
            cout << "Rachunek nie zostal zalozony" << endl;
        }
    }
}

void Savings::addBalance(double amount) {
    this->balance += ratio * amount;
}