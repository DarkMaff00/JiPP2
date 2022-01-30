#include <iostream>
#include "currency.h"


using namespace std;
string scTab[] = {"EUR", "USD", "GBP", "CHF"};

Currency::Currency(User logged) : Account(logged) {
    this->status = logged.currency;
    this->balance = logged.balance[2];
    this->sc = logged.currSC;
}

void Currency::create() {
    if (check() == 1) {
        cout << "Masz juz rachunek walutowy." << endl;
    } else {
        string answer;
        cout << "Nie masz jeszcze rachunku walutowego" << endl;
        cout << "Chcesz go zalozyc? (y/n)" << endl;
        cin >> answer;
        if (answer == "y" || answer == "Y") {
            int pom;
            cout << "Wybierz walute:" << endl;
            cout << "01.EUR" << endl;
            cout << "02.USD" << endl;
            cout << "03.GBP" << endl;
            cout << "04.CHF" << endl;
            do {
                cin >> pom;
                check_for_error<int>(pom);
                switch (pom) {
                    case 1:
                        this->sc = scTab[0];
                        break;
                    case 2:
                        this->sc = scTab[1];
                        break;
                    case 3:
                        this->sc = scTab[2];
                        break;
                    case 4:
                        this->sc = scTab[3];
                        break;
                    default:
                        cout << "Wybierz walute z listy!" << endl;
                }
            } while (sc == "");
            update_base(9, this->sc);
            this->status = 1;
            update_base(7, 1);
            cout << "Twoj rachunek walutowy zostal utworzony :)" << endl;
        } else {
            cout << "Rachunek nie zostal zalozony" << endl;
        }
    }
}

string Currency::getSC() {
    return sc;
}

double Currency::transfer(double amount) {
    double rate{0};
    if (this->balance - amount >= 0) {
        this->balance -= amount;
        update_base(8, this->balance);
        if (this->sc == "EUR") {
            rate = 4.53;
        }
        if (this->sc == "USD") {
            rate = 3.99;
        }
        if (this->sc == "GBP") {
            rate = 5.41;
        }
        if (this->sc == "CHF") {
            rate = 4.38;
        }
        return round((rate * amount) * 100.0) / 100.0;
    } else {
        return rate;
    }
}

void Currency::addMoney() {
    cout << "Ile chcesz wplacic:";
    double amount;
    cin >> amount;
    check_for_error<double>(amount);
    amount = round(amount * 100.0) / 100.0;
    addBalance(amount);
    update_base(8, getBalance());
    cout << "Dodano do konta " << amount << " " << this->sc << endl;
    cout << "Twoj bilans wynosi: " << getBalance() << " " << this->sc << endl;
}

void Currency::subMoney() {
    cout << "Ile chcesz wyplacic:";
    double amount;
    cin >> amount;
    check_for_error<double>(amount);
    amount = round(amount * 100.0) / 100.0;
    subBalance(amount);
    update_base(8, getBalance());
    cout << "Twoj bilans wynosi: " << getBalance() << " " << this->sc << endl;
}

void Currency::cantor(Account *acc1, Savings *acc2) {
    int pom{0};
    double amount{0.0}, cantor;
    if (check() == 0) {
        cout << "Nie masz konta walutowego wiec nie mozesz korzystac z kantoru." << endl;
    } else {
        if (acc1->check() == 0 && acc2->check() == 0) {
            cout << "Nie masz konta na ktore moglbys przeslac pieniadze" << endl;
        } else {
            cout << "Witamy w Kantorze" << endl;
            cout << "Wybierz konto na ktore chcesz zrobic transfer" << endl;
            cout << "01.Standardowe" << endl;
            cout << "02.Oszczednosciowe" << endl;
            cin >> pom;
            check_for_error<int>(pom);
            if (pom != 1 && pom != 2) {
                cout << "Trzeba bylo wybrac opcje 1 lub 2" << endl;
            } else {
                switch (pom) {
                    case 1:
                        if (acc1->check() == 0) {
                            cout << "Nie masz standardowego konta" << endl;
                        } else {
                            cout << "Jaka kwote chcesz przetransferwac:";
                            double amount;
                            cin >> amount;
                            check_for_error<double>(amount);
                            amount = round(amount * 100.0) / 100.0;
                            cantor = transfer(amount);
                            if (cantor == 0) {
                                cout << "Masz za malo pieniedzy na koncie walutowym" << endl;
                            } else {
                                acc1->addBalance(cantor);
                                acc1->update_base(4, acc1->getBalance());
                                cout << "Operacja zakonczona powodzeniem." << endl;
                                cout << "Wybierze opcje 6,aby zobaczyc balans kont." << endl;
                            }
                        }
                        break;
                    case 2:
                        if (acc2->check() == 0) {
                            cout << "Nie masz oszczednosciowego konta" << endl;
                        } else {
                            cout << "Jaka kwote chcesz przetransferwac:";
                            cin >> amount;
                            check_for_error<double>(amount);
                            amount = round(amount * 100.0) / 100.0;
                            cantor = transfer(amount);
                            if (cantor == 0) {
                                cout << "Masz za malo pieniedzy na koncie walutowym" << endl;
                            } else {
                                acc2->addBalance(cantor);
                                acc2->update_base(6, acc2->getBalance());
                                cout << "Operacja zakonczona powodzeniem." << endl;
                                cout << "Wybierze opcje 6,aby zobaczyc balans kont." << endl;
                            }
                        }
                        break;
                }
            }
        }
    }
}

