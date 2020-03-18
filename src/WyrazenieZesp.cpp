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
void wyswietl(LZespolona z1)
{
    cout << noshowpos<< "(" << z1.re;
    cout << showpos << z1.im << "i)";
    cout << noshowpos;
}

int pytanie(WyrazenieZesp dane){
    LZespolona z1 = dane.Arg1;
    LZespolona z2 = dane.Arg2;
    LZespolona odp;
    int placeholder;

    switch (dane.Op){
        case 0:
            cout << "Dodaj ";
        break;
        case 1:
            cout << "Odejmij ";
        break;
        case 2:
            cout << "Pomnoz ";
        break;
        case 3:
            cout << "Podziel ";
        break;
    }
    cout << "nastepujace liczby zespolone: ";
    wyswietl(z1);
    cout << " oraz ";
    wyswietl(z2);
    cout << endl << "Twoja odpowiedz: ";
    cin >> placeholder;
    if(placeholder >0){
        cout << "Prawidlowa odpowiedz!" << endl;
        cout << endl << endl;
        return 1;
    }else{
        cout << "Bledna odpowiedz!" << endl << "Prawidlowa odpowiedz to: ";
        switch (dane.Op){
        case 0:
            wyswietl(z1 + z2);
        break;
        case 1:
            wyswietl(z1 - z2);
        break;
        case 2:
            wyswietl(z1 * z2);
        break;
        case 3:
            wyswietl(z1 / z2);
        break;
    }
        cout << endl << endl << endl;
        return 0;
    }
    
}