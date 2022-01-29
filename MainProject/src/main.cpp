#include <iostream>
#include "user.h"
#include "account.h"
#include "savings.h"
#include "currency.h"
#include "normal.h"
#include "menu.h"

using namespace std;

int main(int argc, char *argv[]) {
    Menu mainMenu;
    if (argc == 2) {
        mainMenu.getArgument(argv[1]);
    }
    if (mainMenu.checking() == 1) {
        cout << "---------- Big Bank ----------" << endl;
        User newUser;
        newUser.create_user();
    } else if (mainMenu.checking() == 2) {
        cout << "---------- Big Bank ----------" << endl;
        User logged, second;
        logged.log_in();
        Account *acc1 = new Normal(logged);
        Savings acc2(logged);
        Currency acc3(logged);
        mainMenu.logged(acc1, &acc2, &acc3, &logged);
    } else if (mainMenu.checking() == -1) {
        cout << "----------HELP---------------" << endl;
        cout << "Musisz podac parametr wywyolania programu aby dzialal prawidlowo" << endl;
        cout << "1. addUser - wchodzisz do trybu tworzenia uzytkownika (podajesz login, i haslo) "
                "i twoje konto zostaje stworzone i dodane do bazy." << endl;
        cout << "Musisz jeszcze zaakceptowac regulamin :)" << endl;
        cout << "2. login - mozesz zalogowac sie na swojego uzytkownika i zarzadzac kontem, opce sa opisane w tym trybie" << endl;
        cout << "3. help - wyswietla ta informacje, jest rowniesz wywolywany jesli podasz zly parametr lub zla ich ilosc." << endl;
    }
    return 0;
}

