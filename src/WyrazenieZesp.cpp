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
std::ostream & operator << (std::ostream &out, const LZespolona &z1){
    out << noshowpos<< "(" << z1.re;
    out << showpos << z1.im << "i)";
    out << noshowpos;
    return out;
}

/*!
 * Funkcja wczytująca daną liczbę zespoloną
 */
std::istream & operator >> (std::istream &in, LZespolona &z1)
{
    string inString; 
    string real;
    string imaginated;
    string com = "Niepoprawny format liczby zespolonej. Spróbuj jeszcze raz.\n\n";
    size_t letI, plus, minus;
    int pos;
    bool push = 0;
    
    while(!push){
      in >> inString;
      size_t first = inString.find("(",0,1);
      size_t last = inString.find(")");
      
        // sprawdzanie czy są nawiasy
      if (first != string::npos && last != string::npos){
         //sprawdzanie gdzie jest "środek" naszej liczby zespolonej
          plus = inString.find("+");
          minus = inString.find("-");

         if (plus != string::npos || minus != string::npos){
            //szukanie litery i
            if(plus != string::npos){

             letI = inString.find("i",plus); 
             pos = plus;
            }else{
             letI = inString.find("i",minus); 
             pos = minus;
            }
         }else cout << com;
         if(letI != string::npos){
             z1.re = stod(inString.substr(first+1,pos-1));
             z1.im = stod(inString.substr(pos,last-3));
             push = !push;
         }else cout << com;
      }else cout << com;
    }
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