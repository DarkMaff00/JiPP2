#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "account.h"


using namespace std;

Account::Account() {}

Account::Account(User logged) {
    this->owner = logged.userID;
}

int Account::check() {
    if (status == 1) {
        return 1;
    } else {
        return 0;
    }
}

void Account::create() {
    if (check() == 1) {
        cout << "Masz juz konto standardowe." << endl;
    } else {
        string answer;
        cout << "Nie masz jeszcze normalnego rachunku" << endl;
        cout << "Chcesz go zalozyc? (y/n)" << endl;
        cin >> answer;
        if (answer == "y" || answer == "Y") {
            status = 1;
            update_base(3, status);
            cout << "Twoj normalny rachunek zostal utworzony :)" << endl;
        } else {
            cout << "Rachunek nie zostal zalozony" << endl;
        }
    }
}

void Account::update_base(int index, int data) {
    fstream input, output;

    input.open("../database.txt", ios::in);
    output.open("../databaseNew.txt", ios::out);

    string line, word;
    int roll;
    vector<string> row;

    while (!input.eof()) {
        row.clear();
        getline(input, line);
        stringstream s(line);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, '\n');
        row.push_back(word);
        int row_size = row.size();
        roll = strtol(row[1].c_str(), NULL, 10);

        if (roll == owner) {
            stringstream convert;
            convert << data;
            row[index] = convert.str();

            if (!input.eof()) {
                for (int i = 0; i < row_size - 1; i++) {
                    output << row[i] << ",";
                }
                output << row[row_size - 1] << "\n";
            }
        } else {
            if (!input.eof()) {
                for (int i = 0; i < row_size - 1; i++) {
                    output << row[i] << ",";
                }
                output << row[row_size - 1] << "\n";
            }
        }
        if (input.eof()) {
            break;
        }
    }
    input.close();
    output.close();
    remove("../database.txt");
    rename("../databaseNew.txt", "../database.txt");
}

void Account::update_base(int index, double data) {
    fstream input, output;

    input.open("../database.txt", ios::in);
    output.open("../databaseNew.txt", ios::out);

    string line, word;
    int roll;
    vector<string> row;

    while (!input.eof()) {
        row.clear();
        getline(input, line);
        stringstream s(line);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, '\n');
        row.push_back(word);
        int row_size = row.size();
        roll = strtol(row[1].c_str(), NULL, 10);

        if (roll == owner) {
            stringstream convert;
            convert << data;
            row[index] = convert.str();

            if (!input.eof()) {
                for (int i = 0; i < row_size - 1; i++) {
                    output << row[i] << ",";
                }
                output << row[row_size - 1] << "\n";
            }
        } else {
            if (!input.eof()) {
                for (int i = 0; i < row_size - 1; i++) {
                    output << row[i] << ",";
                }
                output << row[row_size - 1] << "\n";
            }
        }
        if (input.eof()) {
            break;
        }
    }
    input.close();
    output.close();
    remove("../database.txt");
    rename("../databaseNew.txt", "../database.txt");
}

void Account::update_base(int index, string data) {
    fstream input, output;

    input.open("../database.txt", ios::in);
    output.open("../databaseNew.txt", ios::out);

    string line, word;
    int roll;
    vector<string> row;

    while (!input.eof()) {
        row.clear();
        getline(input, line);
        stringstream s(line);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, ',');
        row.push_back(word);
        getline(s, word, '\n');
        row.push_back(word);
        int row_size = row.size();
        roll = strtol(row[1].c_str(), NULL, 10);

        if (roll == owner) {
            row[index] = data;

            if (!input.eof()) {
                for (int i = 0; i < row_size - 1; i++) {
                    output << row[i] << ",";
                }
                output << row[row_size - 1] << "\n";
            }
        } else {
            if (!input.eof()) {
                for (int i = 0; i < row_size - 1; i++) {
                    output << row[i] << ",";
                }
                output << row[row_size - 1] << "\n";
            }
        }
        if (input.eof()) {
            break;
        }
    }
    input.close();
    output.close();
    remove("../database.txt");
    rename("../databaseNew.txt", "../database.txt");
}

void Account::setter(int change, double data) {
    this->status = change;
    this->balance = data;
}

double Account::getBalance() {
    return balance;
}

void Account::addBalance(double money) {
    this->balance += money;
}

void Account::subBalance(double money) {
    if (this->balance - money >= 0) {
        this->balance -= money;
    } else {
        cout << "Masz za malo pieniedzy na koncie!" << endl;
    }
}

void Account::transfer(Account *transferTo) {
    cout << "Ile chcesz przelac: ";
    double amount;
    cin >> amount;
    check_for_error<double>(amount);
    amount = round(amount * 100.0) / 100.0;
    if (this->balance - amount >= 0) {
        this->balance -= amount;
        update_base(4, this->balance);
        transferTo = &transferTo->operator+(amount);
        transferTo->update_base(4, transferTo->balance);
        cout << "Przelano " << amount << " PLN." << endl;
    } else {
        cout << "Masz za malo pieniedzy na koncie" << endl;
    }
}

void Account::addMoney(int index) {
    cout << "Ile chcesz wplacic:";
    double amount;
    cin >> amount;
    check_for_error<double>(amount);
    amount = round(amount * 100.0) / 100.0;
    addBalance(amount);
    if (getBalance() > 1000000) {
        cout << "Na jednym koncie mozesz miec maksymlanie 1 000 000." << endl;
        exit(1);
    }
    update_base(index, getBalance());
    cout << "Dodano do konta " << amount << " PLN" << endl;
    cout << "Twoj bilans wynosi: " << getBalance() << " PLN" << endl;
}

void Account::subMoney(int index) {
    cout << "Ile chcesz wyplacic:";
    double amount;
    cin >> amount;
    check_for_error<double>(amount);
    amount = round(amount * 100.0) / 100.0;
    subBalance(amount);
    update_base(index, getBalance());
    cout << "Twoj bilans wynosi: " << getBalance() << " PLN" << endl;
}


