#include <iostream>
#include <calc.h>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc>1) {                                                //Sprawdzenie czy program ma podane arguemnty
        int program = atoi(argv[1]);                       // Przypisanie pierwszego argumentu do programu i zamiana na int
        if (program == 1) {
            if (argc>=4) {                                      //Sprawdzenie czy nie ma za moło argumentow dla teog dzialania
                add(atoi(argv[2]), atoi(argv[3])); // Funkacja dodwania
            } else {
                cout << "Blad! Wprowadzono za malo wartosci" << endl;
                help(1);
            }
        } else if (program == 2) {
            if (argc >= 3) {                                        //Sprawdzenie czy nie ma za moło argumentow dla teog dzialania
                subtract(atoi(argv[2]), atoi(argv[3]));     //Funkcja odejmowania
            } else {
                cout << "Blad! Wprowadzono za malo wartosci" << endl;
                help(2);
            }
        } else if (program == 3) {
            if (argc >= 6) {                                                        //Sprawdzenie czy nie ma za moło argumentow dla teog dzialania
                if(atoi(argv[2]) >0 && atoi(argv[3])>0 && atoi(argv[4])>0 && atoi(argv[5])>0)   //Sprawdzenie czy nie ma liczb ujemnych
                    volume(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5])); //Funkcja oblicznia objetosci graniastoslupa
                else
                {
                    cout<<"Wartosci musza byc dodatnie!"<<endl;
                    help(3);                                         // Wyswietlanie dokumentacji
                }
            } else {
                cout << "Blad! Wprowadzono za malo wartosci" << endl;
                help(3);
            }
        } else if (program == 4) {
            help(4);
        } else {
            cout << "Blad! Wprowadzono za malo wartosci" << endl;
            help(4);
        }
    }
    else
    {
        cout <<"Blad nie masz podanych zadnych argumentow!"<<endl;
        help(4);
    }
    return 0;
}
