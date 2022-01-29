#include <iostream>
#include "menu.h"

using namespace std;

template<typename T>
void Menu::noLetter(T msg) {
    try {
        if (cin.fail()) {
            throw 0;
        }
    }
    catch (int e) {
        cin.clear();
        cin.ignore(256, '\n');
        msg = e;
    }
}

Menu::Menu()
        : argument("help") {}

void Menu::getArgument(std::string argv) {
    this->argument = argv;
}


int Menu::checking() {
    if (this->argument == "addUser") {
        return 1;
    } else if (this->argument == "login") {
        return 2;
    } else if (this->argument == "help") {
        return -1;
    } else {
        return -1;
    }
}

void Menu::logged(Account *acc1, Savings *acc2, Currency *acc3, User *logged) {
    text();
    int option{0};
    do {
        cout << "Opcja:";
        cin >> option;
        noLetter(option);
        switch (option) {
            case 0:
                text();
                break;
            case 1:
                creating(acc1, acc2, acc3);
                break;
            case 2:
                deposit(acc1, acc2, acc3);
                break;
            case 3:
                withdraw(acc1, acc3);
                break;
            case 4:
                transfer(acc1);
                break;
            case 5:
                cantor(acc1, acc2, acc3);
                break;
            case 6:
                showBalance(acc1, acc2, acc3);
                break;
            case 7:
                closeBill(acc1, acc2, acc3);
                break;
            case 8:
                logged->delete_user();
                break;
            case 9:
                cout << "Do nastepnego razu :)" << endl;
                exit(1);
            default:
                text();
        }
    } while (option != 9);
}

void Menu::text() const {
    cout << "---------MENU----------\n";
    cout << "00. Menu\n";
    cout << "01. Otworz nowy rachunek.\n";
    cout << "02. Wplac pieniadze.\n";
    cout << "03. Wybierz pieniadze\n";
    cout << "04. Zrob przelew\n";
    cout << "05. Kantor\n";
    cout << "06. Wyswietl balans kont\n";
    cout << "07. Zamknij rachunek\n";
    cout << "08. Zamknij konto\n";
    cout << "09. Wyjscie\n";
    cout << "Wybierz opcje (0-9)\n";
}

void Menu::creating(Account *acc1, Savings *acc2, Currency *acc3) {
    acc1->create();
    acc2->create();
    acc3->create();
}

void Menu::deposit(Account *acc1, Savings *acc2, Currency *acc3) {
    int pom;
    cout << "Na jakie konto chcesz wplacic pieniadze?" << endl;
    cout << "01.Konto standardowe." << endl;
    cout << "02.Konto oszczednosciowe." << endl;
    cout << "03.Konto walutowe." << endl;
    cin >> pom;
    noLetter(pom);
    if (pom != 1 && pom != 2 && pom != 3) {
        cout << "Trzeba bylo wybrac opcje 1-3" << endl;
    } else {
        switch (pom) {
            case 1:
                if (acc1->check() == 0) {
                    cout << "Nie masz takiego konta." << endl;
                } else {
                    acc1->addMoney(4);
                }
                break;
            case 2:
                if (acc2->check() == 0) {
                    cout << "Nie masz takiego konta." << endl;
                } else {
                    acc2->addMoney(6);
                }
                break;
            case 3:
                if (acc3->check() == 0) {
                    cout << "Nie masz takiego konta." << endl;
                } else {
                    acc3->addMoney();
                }
                break;
        }
    }
}

void Menu::withdraw(Account *acc1, Currency *acc3) {
    int pom;
    cout << "Z jakiego konta chcesz wybrac pieniadze?" << endl;
    cout << "01.Konto standardowe." << endl;
    cout << "02.Konto oszczednosciowe." << endl;
    cout << "03.Konto walutowe." << endl;
    cin >> pom;
    noLetter(pom);
    if (pom != 1 && pom != 2 && pom != 3) {
        cout << "Trzeba bylo wybrac opcje 1-3" << endl;
    } else {
        switch (pom) {
            case 1:
                if (acc1->check() == 0) {
                    cout << "Nie masz takiego konta." << endl;
                } else {
                    acc1->subMoney(4);
                }
                break;
            case 2:
                cout << "Nie mozna wybierac pieniedzy z konta oszczednosciowego" << endl;
                break;
            case 3:
                if (acc3->check() == 0) {
                    cout << "Nie masz takiego konta." << endl;
                } else {
                    acc3->subMoney();
                }
                break;
        }
    }
}

void Menu::transfer(Account *acc1) {
    User second;
    string secondUser;
    cout << "Przelewy sa realizowane z kont standardowych na standardowe" << endl;
    if (acc1->check() == 0) {
        cout << "Nie masz konta standardowego. Nie mozesz zrobic przelewu :(" << endl;
    } else {
        cout << "Do jakiego uzytkownika chcesz przeslac pieniadze: ";
        cin >> secondUser;
        if (second.compare_with_data(secondUser) == 0) {
            cout << "Nie ma takiego uzytkownika." << endl;
        } else {
            Account *secondAcc = new Normal(second);
            if (secondAcc->check() == 0) {
                cout << "Ten uzytkownik nie ma konta standardowego." << endl;
            } else {
                acc1->transfer(secondAcc);
            }
        }
    }
}

void Menu::showBalance(Account *acc1, Savings *acc2, Currency *acc3) {
    if (acc1->check() == 0) {
        cout << "Nie masz normalnego rachunku" << endl;
    } else {
        cout << "Rachunek standardowy" << endl;
        cout << "Bilans: " << acc1->getBalance() << " PLN" << endl;
    }
    if (acc2->check() == 0) {
        cout << "Nie masz rachunku oszczednosciowego" << endl;
    } else {
        cout << "Rachunek oszczednosciowy" << endl;
        cout << "Bilans: " << acc2->getBalance() << " PLN" << endl;
    }
    if (acc3->check() == 0) {
        cout << "Nie masz rachunku walutwego" << endl;
    } else {
        cout << "Rachunek walutowy" << endl;
        cout << "Bilans: " << acc3->getBalance() << " " << acc3->getSC() << endl;
    }
}

void Menu::cantor(Account *acc1, Savings *acc2, Currency *acc3) {
    acc3->cantor(acc1, acc2);
}

void Menu::closeBill(Account *acc1, Savings *acc2, Currency *acc3) {
    int pom;
    cout << "Jesli usuniesz jakis rachunek wszystkie pieniadze z tego konta znikna.\n\n" << endl;
    cout << "Jaki rachunek chcesz usunac?" << endl;
    cout << "01.Konto standardowe." << endl;
    cout << "02.Konto oszczednosciowe." << endl;
    cout << "03.Konto walutowe." << endl;
    cin >> pom;
    noLetter(pom);
    if (pom != 1 && pom != 2 && pom != 3) {
        cout << "Trzeba bylo wybrac opcje 1-3" << endl;
    } else {
        switch (pom) {
            case 1:
                if (acc1->check() == 0) {
                    cout << "Nie masz takiego konta." << endl;
                } else {
                    acc1->setter(0, 0);
                    acc1->update_base(3, 0);
                    acc1->update_base(4, 0);
                    cout << "Rachunek zostal usuniety" << endl;
                }
                break;
            case 2:
                if (acc2->check() == 0) {
                    cout << "Nie masz takiego konta." << endl;
                } else {
                    acc2->setter(0, 0);
                    acc2->update_base(5, 0);
                    acc2->update_base(6, 0);
                    cout << "Rachunek zostal usuniety" << endl;
                }
                break;
            case 3:
                if (acc3->check() == 0) {
                    cout << "Nie masz takiego konta." << endl;
                } else {
                    acc3->setter(0, 0);
                    acc3->update_base(7, 0);
                    acc3->update_base(8, 0);
                    acc3->update_base(9, "XXX");
                    cout << "Rachunek zostal usuniety" << endl;
                }
                break;
        }
    }
}
