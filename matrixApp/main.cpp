#include <iostream>
#include "matrix.h"

using namespace std;

void show(int **, int, int);

void show(double **, int, int);

void clearMatrix(int **, int);

void clearMatrixD(double **, int);

void addData(int **, int, int);

void addData(double **, int, int);

bool letterSecure(int);

bool letterSecure(double);

int main(int argc, char *argv[]) {
    if (argc == 2) {
        int type;
        string task = argv[1];

        if (task == "addMatrix") {
            //Podajemy ilosc wierszy i kolumn
            int rows, columns;
            cout << "Podaj ilosc wierszy:";
            do {
                cin >> rows;
            } while (!letterSecure(rows));
            cout << "Podaj ilosc kolumn:";
            do {
                cin >> columns;
            } while (!letterSecure(columns));
            //Wybieramy typ macierzy
            cout << "Twoja tablica ma byc typu:" << endl;
            cout << "1. int" << endl;
            cout << "2. double" << endl;
            do {
                cin >> type;
            } while (!letterSecure(type));

            if (type == 1) {
                int **matrixA = allocation(rows, columns);
                int **matrixB = allocation(rows, columns);
                int **matrixResult;
                cout << "Podaj wartosci dla macierzy A:" << endl;
                addData(matrixA, rows, columns);
                cout << "Podaj wartosci dla macierzy B:" << endl;
                addData(matrixB, rows, columns);

                cout << "--------------------Dodawanie macierzy---------------" << endl;
                cout << "Macierz A:" << endl;
                show(matrixA, rows, columns);
                cout << "Macierz B:" << endl;
                show(matrixB, rows, columns);
                cout << "Macierz Wynikowa:" << endl;
                matrixResult = addMatrix(matrixA, matrixB, rows, columns);
                show(matrixResult, rows, columns);

                clearMatrix(matrixA, rows);
                clearMatrix(matrixB, rows);
                clearMatrix(matrixResult, rows);
            } else if (type == 2) {
                double **matrixA = allocationD(rows, columns);
                double **matrixB = allocationD(rows, columns);
                double **matrixResult;

                cout << "Podaj wartosci dla macierzy A:" << endl;
                addData(matrixA, rows, columns);

                cout << "Podaj wartosci dla macierzy B:" << endl;
                addData(matrixB, rows, columns);

                cout << "--------------------Dodawanie macierzy---------------" << endl;
                cout << "Macierz A:" << endl;
                show(matrixA, rows, columns);
                cout << "Macierz B:" << endl;
                show(matrixB, rows, columns);
                cout << "Macierz Wynikowa:" << endl;

                matrixResult = addMatrix(matrixA, matrixB, rows, columns);

                show(matrixResult, rows, columns);

                clearMatrixD(matrixA, rows);
                clearMatrixD(matrixB, rows);
                clearMatrixD(matrixResult, rows);
            } else
                help();
        } else if (task == "subtractMatrix") {
            //Podajemy ilosc wierszy i kolumn
            int rows, columns;
            cout << "Podaj ilosc wierszy:";
            do {
                cin >> rows;
            } while (!letterSecure(rows));
            cout << "Podaj ilosc kolumn:";
            do {
                cin >> columns;
            } while (!letterSecure(columns));
            //Wybieramy typ macierzy
            cout << "Twoja tablica ma byc typu:" << endl;
            cout << "1. int" << endl;
            cout << "2. double" << endl;
            do {
                cin >> type;
            } while (!letterSecure(type));

            if (type == 1) {
                int **matrixA = allocation(rows, columns);
                int **matrixB = allocation(rows, columns);
                int **matrixResult;

                cout << "Podaj wartosci dla macierzy A:" << endl;
                addData(matrixA, rows, columns);

                cout << "Podaj wartosci dla macierzy B:" << endl;
                addData(matrixB, rows, columns);

                cout << "--------------------Odejmowanie macierzy---------------" << endl;
                cout << "Macierz A:" << endl;
                show(matrixA, rows, columns);
                cout << "Macierz B:" << endl;
                show(matrixB, rows, columns);
                cout << "Macierz Wynikowa:" << endl;
                matrixResult = subtractMatrix(matrixA, matrixB, rows, columns);
                show(matrixResult, rows, columns);

                clearMatrix(matrixA, rows);
                clearMatrix(matrixB, rows);
                clearMatrix(matrixResult, rows);
            } else if (type == 2) {
                double **matrixA = allocationD(rows, columns);
                double **matrixB = allocationD(rows, columns);
                double **matrixResult;

                cout << "Podaj wartosci dla macierzy A:" << endl;
                addData(matrixA, rows, columns);

                cout << "Podaj wartosci dla macierzy B:" << endl;
                addData(matrixB, rows, columns);

                cout << "--------------------Odejmowanie macierzy---------------" << endl;
                cout << "Macierz A:" << endl;
                show(matrixA, rows, columns);
                cout << "Macierz B:" << endl;
                show(matrixB, rows, columns);
                cout << "Macierz Wynikowa:" << endl;
                matrixResult = subtractMatrix(matrixA, matrixB, rows, columns);
                show(matrixResult, rows, columns);

                clearMatrixD(matrixA, rows);
                clearMatrixD(matrixB, rows);
                clearMatrixD(matrixResult, rows);
            } else
                help();
        } else if (task == "multiplyMatrix") {
            int rows, rowsB, columns, columnsB;
            //Podajemy ilosc wierszy i kolumn dla macierz A
            cout << "Podaj ilosc wierszy dla macierzy A:";
            do {
                cin >> rows;
            } while (!letterSecure(rows));
            cout << "Podaj ilosc kolumn dla macierzy A:";
            do {
                cin >> columns;
            } while (!letterSecure(columns));
            //Podajemy ilosc wierszy i kolumn dla macierzy B
            cout << "Podaj ilosc wierszy dla macierzy B:";
            do {
                cin >> rowsB;
            } while (!letterSecure(rowsB));
            cout << "Podaj ilosc kolumn dla macierzy B:";
            do {
                cin >> columnsB;
            } while (!letterSecure(columnsB));

            if (columns != rowsB) {
                help();
            }
            //Wybieramy typ macierzy
            cout << "Twoja tablica ma byc typu:" << endl;
            cout << "1. int" << endl;
            cout << "2. double" << endl;
            do {
                cin >> type;
            } while (!letterSecure(type));

            if (type == 1) {
                int **matrixA = allocation(rows, columns);
                int **matrixB = allocation(rowsB, columnsB);
                int **matrixResult;

                cout << "Podaj wartosci dla macierzy A:" << endl;
                addData(matrixA, rows, columns);

                cout << "Podaj wartosci dla macierzy B:" << endl;
                addData(matrixB, rowsB, columnsB);

                cout << "--------------------Mnozenie macierzy---------------" << endl;
                cout << "Macierz A:" << endl;
                show(matrixA, rows, columns);
                cout << "Macierz B:" << endl;
                show(matrixB, rowsB, columnsB);
                cout << "Macierz Wynikowa:" << endl;
                matrixResult = multiplyMatrix(matrixA, matrixB, rows, columns, columnsB);
                show(matrixResult, rows, columns);

                clearMatrix(matrixA, rows);
                clearMatrix(matrixB, rows);
                clearMatrix(matrixResult, rows);
            } else if (type == 2) {
                double **matrixA = allocationD(rows, columns);
                double **matrixB = allocationD(rowsB, columnsB);
                double **matrixResult;

                cout << "Podaj wartosci dla macierzy A:" << endl;
                addData(matrixA, rows, columns);

                cout << "Podaj wartosci dla macierzy B:" << endl;
                addData(matrixB, rowsB, columnsB);

                cout << "--------------------Mnozenie macierzy---------------" << endl;
                cout << "Macierz A:" << endl;
                show(matrixA, rows, columns);
                cout << "Macierz B:" << endl;
                show(matrixB, rowsB, columnsB);
                cout << "Macierz Wynikowa:" << endl;
                matrixResult = multiplyMatrix(matrixA, matrixB, rows, columns, columnsB);
                show(matrixResult, rows, columns);

                clearMatrixD(matrixA, rows);
                clearMatrixD(matrixB, rows);
                clearMatrixD(matrixResult, rows);
            } else
                help();
        } else if (task == "multiplyByScalar") {
            //Podajemy ilosc wierszy i kolumn
            int rows, columns;
            cout << "Podaj ilosc wierszy:";
            do {
                cin >> rows;
            } while (!letterSecure(rows));
            cout << "Podaj ilosc kolumn:";
            do {
                cin >> columns;
            } while (!letterSecure(columns));
            //Wybieramy typ macierzy
            cout << "Twoja tablica ma byc typu:" << endl;
            cout << "1. int" << endl;
            cout << "2. double" << endl;
            do {
                cin >> type;
            } while (!letterSecure(type));

            if (type == 1) {
                int scalar;
                int **matrixA = allocation(rows, columns);
                int **matrixResult;

                cout << "Podaj wartosc skalara:";
                cin >> scalar;

                cout << "Podaj wartosci dla macierzy A:" << endl;
                addData(matrixA, rows, columns);


                cout << "--------------------Mnozenie macierzy przez skalar---------------" << endl;
                cout << "Macierz A:" << endl;
                show(matrixA, rows, columns);
                cout << "Macierz Wynikowa:" << endl;
                matrixResult = multiplyByScalar(matrixA, rows, columns, scalar);
                show(matrixResult, rows, columns);

                clearMatrix(matrixA, rows);
                clearMatrix(matrixResult, rows);
            } else if (type == 2) {
                double scalar;
                double **matrixA = allocationD(rows, columns);
                double **matrixResult;

                cout << "Podaj wartosc skalara:";
                cin >> scalar;

                cout << "Podaj wartosci dla macierzy A:" << endl;
                addData(matrixA, rows, columns);


                cout << "--------------------Mnozenie macierzy przez skalar---------------" << endl;
                cout << "Macierz A:" << endl;
                show(matrixA, rows, columns);
                cout << "Macierz Wynikowa:" << endl;
                matrixResult = multiplyByScalar(matrixA, rows, columns, scalar);
                show(matrixResult, rows, columns);

                clearMatrixD(matrixA, rows);
                clearMatrixD(matrixResult, rows);
            } else
                help();
        } else if (task == "transpozeMatrix") {
            //Podajemy ilosc wierszy i kolumn
            int rows, columns;
            cout << "Podaj ilosc wierszy:";
            do {
                cin >> rows;
            } while (!letterSecure(rows));
            cout << "Podaj ilosc kolumn:";
            do {
                cin >> columns;
            } while (!letterSecure(columns));
            //Wybieramy typ macierzy
            cout << "Twoja tablica ma byc typu:" << endl;
            cout << "1. int" << endl;
            cout << "2. double" << endl;
            do {
                cin >> type;
            } while (!letterSecure(type));

            if (type == 1) {
                int **matrixA = allocation(rows, columns);
                int **matrixResult;

                cout << "Podaj wartosci dla macierzy A:" << endl;
                addData(matrixA, rows, columns);


                cout << "--------------------Transponowanie macierzy---------------" << endl;
                cout << "Macierz A:" << endl;
                show(matrixA, rows, columns);
                cout << "Macierz Wynikowa:" << endl;
                matrixResult = transpozeMatrix(matrixA, rows, columns);
                show(matrixResult, columns, rows);

                clearMatrix(matrixA, rows);
                clearMatrix(matrixResult, columns);
            } else if (type == 2) {
                double **matrixA = allocationD(rows, columns);
                double **matrixResult;

                cout << "Podaj wartosci dla macierzy A:" << endl;
                addData(matrixA, rows, columns);


                cout << "--------------------Transponowanie macierzy---------------" << endl;
                cout << "Macierz A:" << endl;
                show(matrixA, rows, columns);
                cout << "Macierz Wynikowa:" << endl;
                matrixResult = transpozeMatrix(matrixA, rows, columns);
                show(matrixResult, columns, rows);

                clearMatrixD(matrixA, rows);
                clearMatrixD(matrixResult, columns);
            } else
                help();
        } else if (task == "powerMatrix") {
            int rows, columns;
            unsigned int power;
            cout << " Podaj wartosc potegi macierzy:";
            cin >> power;
            //Podajemy ilosc wierszy i kolumn
            cout << "Podaj ilosc wierszy:";
            do {
                cin >> rows;
            } while (!letterSecure(rows));
            cout << "Podaj ilosc kolumn:";
            do {
                cin >> columns;
            } while (!letterSecure(columns));
            //Wybieramy typ macierzy
            cout << "Twoja tablica ma byc typu:" << endl;
            cout << "1. int" << endl;
            cout << "2. double" << endl;
            do {
                cin >> type;
            } while (!letterSecure(type));

            if (type == 1) {
                int **matrixA = allocation(rows, columns);
                int **matrixResult;

                cout << "Podaj wartosci dla macierzy A:" << endl;
                addData(matrixA, rows, columns);


                cout << "--------------------Potegowanie macierzy---------------" << endl;
                cout << "Macierz A:" << endl;
                show(matrixA, rows, columns);
                cout << "Macierz Wynikowa:" << endl;
                matrixResult = powerMatrix(matrixA, rows, columns, power);
                show(matrixResult, columns, rows);

                clearMatrix(matrixA, rows);
                clearMatrix(matrixResult, rows);
            } else if (type == 2) {
                double **matrixA = allocationD(rows, columns);
                double **matrixResult;

                cout << "Podaj wartosci dla macierzy A:" << endl;
                addData(matrixA, rows, columns);


                cout << "--------------------Potegowanie macierzy---------------" << endl;
                cout << "Macierz A:" << endl;
                show(matrixA, rows, columns);
                cout << "Macierz Wynikowa:" << endl;
                matrixResult = powerMatrix(matrixA, rows, columns, power);
                show(matrixResult, columns, rows);

                clearMatrixD(matrixA, rows);
                clearMatrixD(matrixResult, rows);
            } else
                help();
        } else if (task == "determinantMatrix") {
            //Podajemy ilosc wierszy i kolumn
            int rows, columns;
            cout << "Podaj ilosc wierszy:";
            do {
                cin >> rows;
            } while (!letterSecure(rows));
            cout << "Podaj ilosc kolumn:";
            do {
                cin >> columns;
            } while (!letterSecure(columns));
            //Wybieramy typ macierzy
            cout << "Twoja tablica ma byc typu:" << endl;
            cout << "1. int" << endl;
            cout << "2. double" << endl;
            do {
                cin >> type;
            } while (!letterSecure(type));

            if (type == 1) {
                int **matrixA = allocation(rows, columns);

                cout << "Podaj wartosci dla macierzy A:" << endl;
                addData(matrixA, rows, columns);

                cout << "--------------------Wyznacznik macierzy---------------" << endl;
                cout << "Macierz A:" << endl;
                show(matrixA, rows, columns);
                cout << "Wyznacznik: " << determinantMatrix(matrixA, rows, columns) << endl;

                clearMatrix(matrixA, rows);
            } else if (type == 2) {
                double **matrixA = allocationD(rows, columns);

                cout << "Podaj wartosci dla macierzy A:" << endl;
                addData(matrixA, rows, columns);

                cout << "--------------------Wyznacznik macierzy---------------" << endl;
                cout << "Macierz A:" << endl;
                show(matrixA, rows, columns);
                cout << "Wyznacznik: " << determinantMatrix(matrixA, rows, columns) << endl;

                clearMatrixD(matrixA, rows);
            } else
                help();
        } else if (task == "matrixIsDiagonal") {
            //Podajemy ilosc wierszy i kolumn
            int rows, columns;
            cout << "Podaj ilosc wierszy:";
            do {
                cin >> rows;
            } while (!letterSecure(rows));
            cout << "Podaj ilosc kolumn:";
            do {
                cin >> columns;
            } while (!letterSecure(columns));
            //Wybieramy typ macierzy
            cout << "Twoja tablica ma byc typu:" << endl;
            cout << "1. int" << endl;
            cout << "2. double" << endl;
            do {
                cin >> type;
            } while (!letterSecure(type));

            if (type == 1) {
                int **matrixA = allocation(rows, columns);

                cout << "Podaj wartosci dla macierzy A:" << endl;
                addData(matrixA, rows, columns);

                cout << "--------------------Czy macierz jest diagonalna?---------------" << endl;
                cout << "Macierz A:" << endl;
                show(matrixA, rows, columns);
                if (matrixIsDiagonal(matrixA, rows, columns)) {
                    cout << "Macierz A jest diagonalna" << endl;
                } else {
                    cout << "Macierz A nie jest diagonalna" << endl;
                }

                clearMatrix(matrixA, rows);
            } else if (type == 2) {
                double **matrixA = allocationD(rows, columns);

                cout << "Podaj wartosci dla macierzy A:" << endl;
                addData(matrixA, rows, columns);

                cout << "--------------------Czy macierz jest diagonalna?---------------" << endl;
                cout << "Macierz A:" << endl;
                show(matrixA, rows, columns);
                if (matrixIsDiagonal(matrixA, rows, columns)) {
                    cout << "Macierz A jest diagonalna" << endl;
                } else {
                    cout << "Macierz A nie jest diagonalna" << endl;
                }

                clearMatrixD(matrixA, rows);
            } else
                help();
        } else if (task == "swap") {
            cout << "Jakiego typu dane chcesz zamieniac:" << endl;
            cout << "1. int" << endl;
            cout << "2. double" << endl;
            do {
                cin >> type;
            } while (!letterSecure(type));

            if (type == 1) {
                int a, b;
                cout << "Podaj liczbe a: ";
                do {
                    cin >> a;
                } while (!letterSecure(a));
                cout << "Podaj liczbe b: ";
                do {
                    cin >> b;
                } while (!letterSecure(b));
                cout << "Przed sortowaniem:" << endl;
                cout << "a:" << a << " b:" << b << endl;
                swap(a, b);
                cout << "Po sortowaniu:" << endl;
                cout << "a:" << a << " b:" << b << endl;
            } else if (type == 2) {
                double a, b;
                cout << "Podaj liczbe a: ";
                do {
                    cin >> a;
                } while (!letterSecure(a));
                cout << "Podaj liczbe b: ";
                do {
                    cin >> b;
                } while (!letterSecure(b));
                cout << "Przed sortowaniem:" << endl;
                cout << "a:" << a << " b:" << b << endl;
                swap(a, b);
                cout << "Po sortowaniu:" << endl;
                cout << "a:" << a << " b:" << b << endl;
            } else
                help();
        } else if (task == "sortRow") {
            int columns;
            cout << "Podaj liczbe kolumn:";
            do {
                cin >> columns;
            } while (!letterSecure(columns));

            cout << "Jakiego typu ma byc tablica:" << endl;
            cout << "1. int" << endl;
            cout << "2. double" << endl;
            do {
                cin >> type;
            } while (!letterSecure(type));

            if (type == 1) {
                int *tab = new int[columns];

                cout << "Wprowadz dane do tablicy:";
                for (int i = 0; i < columns; ++i) {
                    do {
                        cin >> tab[i];
                    } while (!letterSecure(tab[i]));
                }

                cout << "Tablica przed sortowaniem :" << endl;
                for (int i = 0; i < columns; ++i) {
                    cout << tab[i] << " ";
                }
                sortRow(tab, columns);
                cout << "\nTablica po sortowaniu :" << endl;
                for (int i = 0; i < columns; ++i) {
                    cout << tab[i] << " ";
                }
                delete[]tab;
            } else if (type == 2) {
                double *tab = new double[columns];

                cout << "Wprowadz dane do tablicy:";
                for (int i = 0; i < columns; ++i) {
                    do {
                        cin >> tab[i];
                    } while (!letterSecure(tab[i]));
                }

                cout << "Tablica przed sortowaniem :" << endl;
                for (int i = 0; i < columns; ++i) {
                    cout << tab[i] << " ";
                }
                sortRow(tab, columns);
                cout << "\nTablica po sortowaniu :" << endl;
                for (int i = 0; i < columns; ++i) {
                    cout << tab[i] << " ";
                }
                delete[]tab;
            } else
                help();
        } else if (task == "sortRowsInMatrix") {
            //Podajemy ilosc wierszy i kolumn
            int rows, columns;
            cout << "Podaj ilosc wierszy:";
            do {
                cin >> rows;
            } while (!letterSecure(rows));
            cout << "Podaj ilosc kolumn:";
            do {
                cin >> columns;
            } while (!letterSecure(columns));
            //Wybieramy typ macierzy
            cout << "Twoja tablica ma byc typu:" << endl;
            cout << "1. int" << endl;
            cout << "2. double" << endl;
            do {
                cin >> type;
            } while (!letterSecure(type));

            if (type == 1) {
                int **matrixA = allocation(rows, columns);

                cout << "Podaj wartosci dla macierzy A:" << endl;
                addData(matrixA, rows, columns);

                cout << "--------------------Sortowanie wierszy macierzy---------------" << endl;
                cout << "Macierz A:" << endl;
                show(matrixA, rows, columns);
                sortRowsInMatrix(matrixA, rows, columns);
                cout << "Macierz po sortowaniu:" << endl;
                show(matrixA, rows, columns);

                clearMatrix(matrixA, rows);
            } else if (type == 2) {
                double **matrixA = allocationD(rows, columns);

                cout << "Podaj wartosci dla macierzy A:" << endl;
                addData(matrixA, rows, columns);

                cout << "--------------------Sortowanie wierszy macierzy---------------" << endl;
                cout << "Macierz A:" << endl;
                show(matrixA, rows, columns);
                sortRowsInMatrix(matrixA, rows, columns);
                cout << "Macierz po sortowaniu:" << endl;
                show(matrixA, rows, columns);

                clearMatrixD(matrixA, rows);
            } else
                help();
        }
        else if (task == "help"){
            help();
        }
        else {
            help();
        }
    } else
        help();
    return 0;
}
///
/// \param matrix - macierz
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
void addData(int **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            do {
                cin >> matrix[i][j];
            } while (!letterSecure(matrix[i][j]));
        }
    }
}
///
/// \param matrix - macierz
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
void addData(double **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            do {
                cin >> matrix[i][j];
            } while (!letterSecure(matrix[i][j]));
        }
    }
}
///
/// \param matrix - macierz
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
void show(int **matrix, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
///
/// \param matrix - macierz
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
void show(double **matrix, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
///
/// \param matrix - macierz
/// \param rows - liczba wierszy
void clearMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;
}
///
/// \param matrix - macierz
/// \param rows - liczba wierszy
void clearMatrixD(double **matrix, int rows) {
    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;
}
///
/// \param x - liczba wprowadzona
/// \return - zwraca prawde jesli x jest liczba
bool letterSecure(double x) {
    while (cin.fail()) {
        cout << "Podaj liczbe:" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        return false;
    }
    return true;
}
bool letterSecure(int x) {
    while (cin.fail()) {
        cout << "Podaj liczbe:" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        return false;
    }
    return true;
}


