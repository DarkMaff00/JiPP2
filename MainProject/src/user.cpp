#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "user.h"


using namespace std;

User::User()
        : userID(0), normalAcc(0), saving(0), currency(0) {}

void User::log_in() {
    string name, pass;
    int pom = 0;
    cout << "Witamy w Trybie Logowania :)" << endl;
    cout << "Login:";
    cin >> name;
    if (compare_with_data(name) == 0) {
        cout << "Nie ma tekiego uzytkownika." << endl;
        cout << "Jesli chcesz zalozyc konto przejdz do trybu tworzenia." << endl;
        exit(1);
    }
    do {
        if (pom == 1 || pom == 2) {
            cout << "Podales zle haslo. Sproboj jescze raz" << endl;
        }
        if (pom == 3) {
            cout << "Podales haslo 3 razy zle. Wychodze z trybu logowania." << endl;
            exit(1);
        }
        cout << "Haslo:";
        cin >> pass;
        pom++;
    } while (password != pass);
    cout << "\n\nWitaj " << login << "\n\n" << endl;
}

void User::create_user() {
    string rules;
    string password1, password2;
    int i{0};
    cout << "Witamy w kreatorze uzytkownika naszego banku :)" << endl;
    cout << "Chcesz poznac zasady towrzenia konta?(y)" << endl;
    cin >> rules;
    if (rules == "y" || rules == "Y") {
        cout << "1. Nazwa uzytkownika musi sie skladac  przynjamniej z "
                "czterech znakow, a maksymalnie osmiu." << endl;
        cout << "2. Haslo musi sie skladac minimalnie z szeciu znakow, a "
                "maksymalnie dwudziestu." << endl;
        cout << "3. Nie stosujemy przecinkow w nazwie ani hasle." << endl;
    }
    cout << "Podaj nazwe uzytkownika (login): ";
    try {
        cin >> login;
        if (login.size() > 8 || login.size() < 4) {
            throw "Nazwa uzytkownika musi zawierac pomiedzy 4, a 8 znakow";
        }
        if (login.find(',') != string::npos) {
            throw "Nie uzywaj przecinka w nazwie uzytkownika";
        }
    }
    catch (const char *msg) {
        cout << msg << endl;
        exit(-1);
    }

    do {
        if (i != 0) {
            cout << "Hasla nie sa takie same. Prosze wpisac je ponownie." << endl;
        }
        cout << "Podaj haslo: ";
        try {
            cin >> password1;
            if (password1.size() > 20 || password1.size() < 6) {
                throw "Haslo musi zawierac pomiedzy 6, a 20 znakow";
            }
            if (password1.find(',') != string::npos) {
                throw "Nie uzywaj przecinka w hasle";
            }
        }
        catch (const char *msg) {
            cout << msg << endl;
            exit(-1);
        }
        cout << "Podaj ponownie haslo: ";
        cin >> password2;
        i = 1;
    } while (password1 != password2);
    password = password1;
    cout << "Akceptujesz regulamin banku?(y)" << endl;
    cin >> rules;
    if (rules != "y" && rules != "Y") {
        cout << "W takim razie dziekujemy i mamy nadzieje do zobaczania :)" << endl;
        exit(0);
    }
    srand(time(NULL));
    do {
        userID = (rand() % 9000) + 1000;
    } while (checkID(userID) == 1);
    save_in_database();
    show_user();
    cout << "\n\nJesli chcesz sie zalogowac prosimy o zmiane trybu pracy na login :)" << endl;
}

void User::show_user() {
    cout << "Twoje dane bankowe" << endl;
    cout << "ID: " << userID << endl;
    cout << "Login: " << login << endl;
}

void User::save_in_database() {
    ofstream base;
    base.open("../database.txt", ios::out | ios::app);
    if (base.is_open()) {
        base << login << "," << userID << "," << password << "," << normalAcc << "," << 0 << "," << saving << "," << 0
             << "," << currency << "," << 0 << "," << "XXX" << "\n";
    } else {
        cout << "Blad przy otwieraniu pliku." << endl;
        exit(1);
    }
}

int User::compare_with_data(string word) {
    ifstream input("../database.txt");
    int numerator = 0;
    if (input.is_open()) {
        string line;
        while (!input.eof()) {
            getline(input, line, ',');
            if (line == word) {
                numerator = 1;
                login = line;
                getline(input, line, ',');
                userID = strtol(line.c_str(), NULL, 10);
                getline(input, line, ',');
                password = line;
                getline(input, line, ',');
                normalAcc = strtol(line.c_str(), NULL, 10);
                getline(input, line, ',');
                balance[0] = stod(line);
                getline(input, line, ',');
                saving = strtol(line.c_str(), NULL, 10);
                getline(input, line, ',');
                balance[1] = stod(line);
                getline(input, line, ',');
                currency = strtol(line.c_str(), NULL, 10);
                getline(input, line, ',');
                balance[2] = stod(line);
                getline(input, line, '\n');
                currSC = line;
                break;
            }
            getline(input, line, ',');
            getline(input, line, ',');
            getline(input, line, ',');
            getline(input, line, ',');
            getline(input, line, ',');
            getline(input, line, ',');
            getline(input, line, ',');
            getline(input, line, '\n');
        }
        input.close();
    } else {
        cout << "Error on opening file" << endl;
        exit(1);
    }
    return numerator;
}

int User::checkID(int id) {
    ifstream input("../database.txt");
    int checkID;
    int numerator = 0;
    if (input.is_open()) {
        string line;
        while (!input.eof()) {
            getline(input, line, ',');
            getline(input, line, ',');
            checkID = strtol(line.c_str(), NULL, 10);
            if (id == checkID) {
                numerator = 1;
                break;
            }
            getline(input, line, ',');
            getline(input, line, ',');
            getline(input, line, ',');
            getline(input, line, ',');
            getline(input, line, ',');
            getline(input, line, ',');
            getline(input, line, '\n');
        }
        input.close();
    } else {
        cout << "Error on opening file" << endl;
        exit(1);
    }
    return numerator;
}

void User::clear_file() {
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

        if (roll != userID) {
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

void User::delete_user() {
    string pom;
    cout << "Wszystkie twoje pieniadze zostana utracone." << endl;
    cout << "Czy jestes pewien ze chcesz zamknac konto?(y)" << endl;
    cin >> pom;
    if (pom == "y" || pom == "Y") {
        clear_file();
        cout << "Dziekujemy za korzystanie z naszych uslug." << endl;
        cout << "Mamy nadzieje do zobaczenia :)" << endl;
        exit(1);
    } else {
        cout << "Twoje konto nadal pozostaje z nami :)" << endl;
    }
}
