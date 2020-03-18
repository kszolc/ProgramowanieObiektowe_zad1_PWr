#include <iostream>
#include "BazaTestu.hh"

using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej o poziomie: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  float wynik = 0;
  float ilosc = 0;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    wynik += pytanie(WyrZ_PytanieTestowe);
    ilosc++;
  }

  
  cout << endl << endl;
  cout << noshowpos << " Koniec testu, uzyskany wynik to " << wynik;
  cout << " na " << ilosc << " punkt(y/ów) (" << wynik/ilosc*100 << "%)." << endl;
  cout << endl;

}
