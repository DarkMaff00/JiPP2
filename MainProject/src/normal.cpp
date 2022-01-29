#include <iostream>
#include "normal.h"
#include "account.h"

using namespace std;

Normal::Normal(User logged) : Account(logged) {
    this->status = logged.normalAcc;
    this->balance = logged.balance[0];
}

void Normal::create() {
    if (check() == 1) {
        cout << "Masz juz zwykl konto." << endl;
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
