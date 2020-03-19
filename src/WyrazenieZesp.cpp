#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */


#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;
/*!
 * Funkcja wyswietlająca daną liczbę zespoloną 
 */
std::ostream & operator << (std::ostream &out, const LZespolona &z1)
{
    cout << noshowpos<< "(" << z1.re;
    cout << showpos << z1.im << "i)";
    cout << noshowpos;
    return out;
}

/*!
 * Funkcja wczytująca daną liczbę zespoloną
 */
std::istream & operator >> (std::istream &in, LZespolona &z1)
{
    char a;
    char b;
    char c;
    do{
     cin >> a >> z1.re >> z1.im >> b >> c;
    }while(a == '(' && b == 'i' && c == ')');
    return in;
}

int pytanie(WyrazenieZesp dane){
    LZespolona z1 = dane.Arg1;
    LZespolona z2 = dane.Arg2;
    LZespolona odp;
    LZespolona prOdp;
    

    switch (dane.Op){
        case 0:
            cout << "Dodaj ";
            prOdp = z1 + z2;
        break;
        case 1:
            cout << "Odejmij ";
            prOdp = z1 - z2;
        break;
        case 2:
            cout << "Pomnoz ";
            prOdp = z1 * z2;
        break;
        case 3:
            cout << "Podziel ";
            prOdp = z1 / z2;
        break;
    }
    cout << "nastepujace liczby zespolone: " << z1 << " oraz " << z2 << endl << "Twoja odpowiedz: ";
      cin >> odp;
    if(odp == prOdp){
        cout << "Prawidlowa odpowiedz!" << endl;
        cout << endl << endl;
        return 1;
    }else{
        cout << "Bledna odpowiedz!" << endl << "Prawidlowa odpowiedz to: " << prOdp;
        cout << endl << endl << endl;
    }
    return 0;
    
    
}