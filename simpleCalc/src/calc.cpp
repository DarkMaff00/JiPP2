#include <iostream>
#include <calc.h>

using namespace std;

void add(int a, int b)
{
    cout<<a<< " + "<<b<<" = "<< a+b<<endl;
}

void subtract(int a,int b)
{
    cout<<a<< " - "<<b<<" = "<< a-b<<endl;
}

void volume(int a, int b, int h, int H)
{
    cout<<" Objetosc graniastoslupa o podstawie trapezu a = "<<a<<" b = "<<b<<" h = "<<h<<" oraz wysokosci H="<<H<<" wynosi "<< (float)(((a+b)*h)/2)*H<<endl;
}

void help()
{
    cout<<"Simple calculator"<<endl;
    cout<<"simpleCalc [nazwa dzialania]"<<endl<<endl;
    cout<<"Dzialania:"<<endl;
    cout<<"1. add [a] [b]"<<endl;
    cout<<"\tDodawanie dwoch liczb ([a] i [b]) calkowitych"<<endl<<endl;
    cout<<"2. subtract [a] [b]"<<endl;
    cout<<"\tOdejmowanie dwoch liczb ([a] i [b]) calkowitych"<<endl<<endl;
    cout<<"3. volume [a] [b] [h] [H]"<<endl;
    cout<<"\tObliczanie objetosci graniastoslupa o podstawie trapezu ([a],[b],[h]) i wysokosci [H]. Dane musza być dodatnie."<<endl<<endl;
    cout<<"4. help"<<endl;
    cout<<"\tWyswietla dokumentacje"<<endl<<endl;
}
