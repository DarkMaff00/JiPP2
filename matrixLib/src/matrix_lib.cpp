#include <iostream>
#include "matrix.h"

using namespace std;

///
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
/// \return wskaznik do macierzy
int **allocation(int rows, int columns) {
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new int[columns];
    return matrix;
}

///
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
/// \return wskaznik do macierzy
double **allocationD(int rows, int columns) {
    auto **matrix = new double *[rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new double[columns];
    return matrix;
}

///
/// \param matrixA -macierz A
/// \param matrixB - macierz B
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
/// \return wskaznik do macierzy wynikowej
int **addMatrix(int **matrixA, int **matrixB, int rows, int columns) {
    int **matrixR = allocation(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j)
            matrixR[i][j] = matrixA[i][j] + matrixB[i][j];
    }
    return matrixR;
}

///
/// \param matrixA -macierz A
/// \param matrixB - macierz B
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
/// \return wskaznik do macierzy wynikowej
int **subtractMatrix(int **matrixA, int **matrixB, int rows, int columns) {
    int **matrixR = allocation(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j)
            matrixR[i][j] = matrixA[i][j] - matrixB[i][j];
    }
    return matrixR;
}

///
/// \param matrixA -macierz A
/// \param matrixB - macierz B
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
/// \param columnsB - liczba kolumn macierzy B
/// \return wskaznik do przemnozonej macierzy
int **multiplyMatrix(int **matrixA, int **matrixB, int rows, int columns, int columnsB) {
    int **matrixR = allocation(rows, columnsB);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columnsB; ++j) {
            matrixR[i][j] = 0;
            for (int k = 0; k < columns; ++k) {
                matrixR[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return matrixR;
}

///
/// \param matrixA -macierz A
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
/// \return wskaznik do przemnozonej macierzy
int **multiplyByScalar(int **matrix, int rows, int columns, int scalar) {
    int **matrixR = allocation(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrixR[i][j] = scalar * matrix[i][j];
        }
    }
    return matrixR;
}

///
/// \param matrix - macierz
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
/// \return wskaznik do ztransponowanej macierzy
int **transpozeMatrix(int **matrix, int rows, int columns) {
    int **matrixR = allocation(columns, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrixR[j][i] = matrix[i][j];
        }
    }
    return matrixR;
}

///
/// \param matrix - macierz
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
/// \param power - stopien potegi
/// \return wskaznik do macierzy wynikowej
int **powerMatrix(int **matrix, int rows, int columns, unsigned int power) {
    int **matrixR;
    matrixR = matrix;
    for (unsigned int i = 0; i < power - 1; ++i) {
        matrixR = multiplyMatrix(matrix, matrixR, rows, columns, columns);
    }
    return matrixR;
}

///
/// \param matrixA - macierz glowna
/// \param matrixB - macierz pomocnicza
/// \param q - numer wiersza
/// \param n - liczba wierszy
void subMatrix(int **matrixA, int **matrixB, int q, int n) {
    int i = 0, j = 0;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (r != 0 && c != q) {
                matrixB[i][j++] = matrixA[r][c];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

///
/// \param matrix - macierz
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
/// \return wyznacznik
int determinantMatrix(int **matrix, int rows, int columns) {
    int det = 0, sign = 1;
    int **temp = allocation(rows, columns); //towrzymy macierz pomocnicza
    if (rows == 1) {    //jesli macierz jest 1x1
        return matrix[0][0];
    } else if (rows == 2) {  //jesli macierz jest 2x2
        return (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);
    }
    for (int i = 0; i < rows; ++i) {
        subMatrix(matrix, temp, i, rows); //dzielimy na mniejsze macierze
        det += sign * matrix[0][i] * determinantMatrix(temp, rows - 1, columns - 1);
        sign = -sign;
    }
    return det;
}

///
/// \param matrix - macierz
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
/// \return true jesli macierz jest diagonalna
int matrixIsDiagonal(int **matrix, int rows, int columns) {
    bool answer = true;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (i != j) {
                if (matrix[i][j] != 0) {
                    answer = false;
                    break;
                }
            }
        }
    }
    return answer;
}

///
/// \param a - pierwsza liczba do zamiany
/// \param b - druga liczba do zamiany
void swap(int &a, int &b) {
    int tmp;
    tmp = b;
    b = a;
    a = tmp;
}

///
/// \param tab - tablica do sortowania
/// \param columns - liczba kolumn
void sortRow(int *tab, int columns) {
    for (int i = 0; i < columns - 1; ++i) {
        for (int j = 0; j < columns - 1; ++j) {
            if (tab[j] > tab[j + 1])
                swap(tab[j], tab[j + 1]);
        }
    }
}

///
/// \param matrix - macierz do sortowania
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
void sortRowsInMatrix(int **matrix, int rows, int columns) {
    int *tab = new int[columns];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            tab[j] = matrix[i][j];
        }
        sortRow(tab, columns);
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = tab[j];
        }
    }
    delete[]tab;
}

///
/// \param matrixA -macierz A
/// \param matrixB - macierz B
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
/// \return wskaznik do macierzy wynikowej
double **addMatrix(double **matrixA, double **matrixB, int rows, int columns) {
    double **matrixR = allocationD(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j)
            matrixR[i][j] = matrixA[i][j] + matrixB[i][j];
    }
    return matrixR;
}

///
/// \param matrixA -macierz A
/// \param matrixB - macierz B
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
/// \return wskaznik do macierzy wynikowej
double **subtractMatrix(double **matrixA, double **matrixB, int rows, int columns) {
    double **matrixR = allocationD(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j)
            matrixR[i][j] = matrixA[i][j] - matrixB[i][j];
    }
    return matrixR;
}

///
/// \param matrixA -macierz A
/// \param matrixB - macierz B
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
/// \param columnsB - liczba kolumn macierzy B
/// \return wskaznik do przemnozonej macierzy
double **multiplyMatrix(double **matrixA, double **matrixB, int rows, int columns, int columnsB) {
    double **matrixR = allocationD(rows, columnsB);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columnsB; ++j) {
            matrixR[i][j] = 0;
            for (int k = 0; k < columns; ++k) {
                matrixR[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return matrixR;
}

///
/// \param matrix - macierz
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
/// \param scalar - skalar
/// \return wskaznik do przemnozonej macierzy
double **multiplyByScalar(double **matrix, int rows, int columns, double scalar) {
    double **matrixR = allocationD(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrixR[i][j] = scalar * matrix[i][j];
        }
    }
    return matrixR;
}

///
/// \param matrix - macierz
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
/// \return wskaznik do ztransponowanej macierzy
double **transpozeMatrix(double **matrix, int rows, int columns) {
    double **matrixR = allocationD(columns, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrixR[j][i] = matrix[i][j];
        }
    }
    return matrixR;
}

///
/// \param matrix - macierz
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
/// \param power - stopien potegi
/// \return - zwraca wskaznik do macierzy matrixR
double **powerMatrix(double **matrix, int rows, int columns, unsigned int power) {
    double **matrixR;
    matrixR = matrix;
    for (unsigned int i = 0; i < power - 1; ++i) {
        matrixR = multiplyMatrix(matrix, matrixR, rows, columns, columns);
    }
    return matrixR;
}

///
/// \param matrixA - macierz glowna
/// \param matrixB - macierz pomocnicza
/// \param q - numer wiersza
/// \param n - liczba wierszy
void subMatrix(double **matrixA, double **matrixB, int q, int n) {
    int i = 0, j = 0;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (r != 0 && c != q) {
                matrixB[i][j++] = matrixA[r][c];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

///
/// \param matrix - macierz
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
/// \return - zwraca wyznacznik macierzy
double determinantMatrix(double **matrix, int rows, int columns) {
    double det = 0, sign = 1;
    double **temp = allocationD(rows, columns);
    if (rows == 1) {
        return matrix[0][0];
    } else if (rows == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);
    }
    for (int i = 0; i < rows; ++i) {
        subMatrix(matrix, temp, i, rows);
        det += sign * matrix[0][i] * determinantMatrix(temp, rows - 1, columns - 1);
        sign = -sign;
    }
    return det;
}

///
/// \param matrix - macierz
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
/// \return - jesli macierz jest diagonalna zwraca true
double matrixIsDiagonal(double **matrix, int rows, int columns) {
    bool answer = true;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (i != j) {
                if (matrix[i][j] != 0) {
                    answer = false;
                    break;
                }
            }
        }
    }
    return answer;
}

///
/// \param a - pierwsz liczba do zamiany
/// \param b - druga liczba do zamiany
void swap(double &a, double &b) {
    double tmp;
    tmp = b;
    b = a;
    a = tmp;
}

///
/// \param tab - tablica do sortowania
/// \param columns - liczba kolumn
void sortRow(double *tab, int columns) {
    for (int i = 0; i < columns - 1; ++i) {
        for (int j = 0; j < columns - 1; ++j) {
            if (tab[j] > tab[j + 1])
                swap(tab[j], tab[j + 1]);
        }
    }
}

///
/// \param matrix - macierz
/// \param rows - liczba wierszy
/// \param columns - liczba kolumn
void sortRowsInMatrix(double **matrix, int rows, int columns) {
    double *tab = new double[columns];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            tab[j] = matrix[i][j];
        }
        sortRow(tab, columns);
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = tab[j];
        }
    }
    delete[]tab;
}

void help() {
    cout << "Podaj parametr o odpowiedniej nazwie aby uruchomic program!" << endl;

    cout << "Na poczatku podajesz ilosc wierszy i kolumn w macierzy" << endl;
    cout
            << "Nastepnie podajesz jakiego typu ma byc macierz [int/double] (wybierz 1 lub 2 inaczej program wyswietli help"
            << endl;
    cout << "Program tworzy macierz alokowana dynamicznie o podanych rozmiarach i odpowiednim typie" << endl;
    cout << "Na koncu podajesz wartosci do odpowiednich komorek (pierwsze wiersze potem kolumny np. [0][0],[0][1],[1][0],[1][1]) i program dokonuje obliczen" << endl;


    cout << "\n1. addMatrix" << endl;
    cout << "Funkcja sumuje ze soba dwie macierze. Dane wprowadzasz wierszami" << endl;
    cout << "matrixA - pierwsza macierz" << endl;
    cout << "matrixB - druga macierz" << endl;
    cout << "rows - ilosc wierszy" << endl;
    cout << "columns - ilosc kolumn" << endl;

    cout << "\n2. subtractMatrix" << endl;
    cout << "Funkcja odejmuje od siebie macierze. Dane wprowadzasz wierszami" << endl;
    cout << "matrixA - pierwsza macierz" << endl;
    cout << "matrixB - druga macierz" << endl;
    cout << "rows - ilosc wierszy" << endl;
    cout << "columns - ilosc kolumn" << endl;

    cout << "\n3. multiplyMatrix" << endl;
    cout << "Funkcja mnozy ze soba dwie macierze. Dane wprowadzasz wierszami" << endl;
    cout << "matrixA - pierwsza macierz" << endl;
    cout << "matrixB - druga macierz" << endl;
    cout << "rows - ilosc wierszy macierzy A" << endl;
    cout << "columns - ilosc kolumn macierzy A" << endl;
    cout << "rowsB - ilosc wierszy macierzy B" << endl;
    cout << "columnsB - ilosc kolumn macierzy B" << endl;

    cout << "\n4. multiplByScalar" << endl;
    cout << "Funkcja mnozy macierz przez skalar. Dane wprowadzasz wierszami" << endl;
    cout << "matrixA - pierwsza macierz" << endl;
    cout << "scalar - skalar" << endl;
    cout << "rows - ilosc wierszy" << endl;
    cout << "columns - ilosc kolumn" << endl;

    cout << "\n5. transpozeMatrix" << endl;
    cout << "Transponowanie macierzy. Dane wprowadzasz wierszami" << endl;
    cout << "matrixA - pierwsza macierz" << endl;
    cout << "rows - ilosc wierszy" << endl;
    cout << "columns - ilosc kolumn" << endl;

    cout << "\n6. powerMatrix" << endl;
    cout << "Funkcja podnosi macierz do odpowiedniej potegi. Dane wprowadzasz wierszami" << endl;
    cout << "matrixA - pierwsza macierz" << endl;
    cout << "power - stopien potegi" << endl;
    cout << "rows - ilosc wierszy" << endl;
    cout << "columns - ilosc kolumn" << endl;

    cout << "\n7. determinantMatrix" << endl;
    cout << "Funkcja znajduje wyznacznik macierzy. Dane wprowadzasz wierszami" << endl;
    cout << "matrixA - pierwsza macierz" << endl;
    cout << "rows - ilosc wierszy" << endl;
    cout << "columns - ilosc kolumn" << endl;

    cout << "\n8. matrixIsDiagonal" << endl;
    cout << "Funkcja sprawdza czy macierz jest diagonalna. Dane wprowadzasz wierszami" << endl;
    cout << "matrixA - pierwsza macierz" << endl;
    cout << "rows - ilosc wierszy" << endl;
    cout << "columns - ilosc kolumn" << endl;

    cout << "\n9. swap" << endl;
    cout << "Funkcja zmienia dwie wartosci miejscami" << endl;
    cout << "a - pierwsza liczba" << endl;
    cout << "b - druga liczba" << endl;

    cout << "\n10. sortRow" << endl;
    cout << "Funkcja sortuje dane w tablicy" << endl;
    cout << "tab - tablica" << endl;
    cout << "columns - ilosc kolumn" << endl;

    cout << "\n11. sortRowsInMatrix" << endl;
    cout << "Dunkcja sortuje wiersze w macierzy" << endl;
    cout << "matrixA - pierwsza macierz" << endl;
    cout << "rows - ilosc wierszy" << endl;
    cout << "columns - ilosc kolumn" << endl;

    cout << "\n12. help" << endl;
    cout << "Wyswietla help" << endl;
}