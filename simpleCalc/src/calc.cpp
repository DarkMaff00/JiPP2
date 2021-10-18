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

void help(int x)
{
    cout<<"Simple calculator"<<endl;
    if (x==1)
    {
        cout<<"simpleCalc [add]"<<endl<<endl;
        cout<<"Dzialania:"<<endl;
        cout<<"1. add [a] [b]"<<endl;
        cout<<"\tDodawanie dwoch liczb ([a] i [b]) calkowitych"<<endl<<endl;
        cout<<"Wprowadz do argumentow odpowiednia ich liczbe (3)"<<endl;
    }
    else if (x==2)
    {
        cout<<"simpleCalc [subtract]"<<endl<<endl;
        cout<<"Dzialania:"<<endl;
        cout<<"2. subtract [a] [b]"<<endl;
        cout<<"\tOdejmowanie dwoch liczb ([a] i [b]) calkowitych"<<endl<<endl;
        cout<<"Wprowadz do argumentow odpowiednia ich liczbe(3)"<<endl;
    }
    else if(x==3)
    {
        cout<<"simpleCalc [volume]"<<endl<<endl;
        cout<<"Dzialania:"<<endl;
        cout<<"3. volume [a] [b] [h] [H]"<<endl;
        cout<<"\tObliczanie objetosci graniastoslupa o podstawie trapezu ([a],[b],[h]) i wysokosci [H]. Dane musza być dodatnie."<<endl<<endl;
        cout<<"Wprowadz do argumentow odpowiednia ich liczbe lub dodatnie wartosci(5)"<<endl;
    }
    else
    {
        cout<<"Wprowadz do argumentow odpowiednia ich liczbe"<<endl;
    }
}
