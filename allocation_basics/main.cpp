#include <iostream>

using namespace std;

int main(int argc,char *argv[])
{
    for(int i=0;i<5;++i)        //Pętla
    cout<< "JiPP2 " <<endl;

    int rozmiar;                        //Tablica 2D
    cout<< "Podaj rozmiar tablicy:";
    cin>>rozmiar;
    int **tablica = new int *[rozmiar];
    for(int i=0;i<rozmiar;++i)
    {
        tablica[i]= new int [rozmiar];
        for(int j=0;j<rozmiar;++j)
        {
          tablica[i][j]=i+j;
        }
        delete tablica[i];
    }
    delete tablica;

    int ***tab3D = new int **[rozmiar];         //Tablica 3D
    for(int i=0;i<rozmiar;++i)
    {
        tab3D[i]= new int*[rozmiar];
    }
    for(int j=0;j<rozmiar;++j)
    {
        for(int i=0;i<rozmiar;++i)
        {
            tab3D[i][j] = new int[rozmiar];
            delete tab3D[i][j];
        }
    }
    delete tab3D;

    for(int i = 0; i < argc ; ++i) {        //Przekazanie argumentu przykład test
        cout << argv[i] <<endl;
    }



    return 0;

}
