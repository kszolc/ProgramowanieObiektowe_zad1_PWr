#include "LZespolona.hh"



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}
/*!
 * Realizuje mnożenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnożenia,
 *    Skl2 - drugi skladnik mnożenia.
 * Zwraca:
 *    iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = (Skl1.re * Skl2.re) - (Skl1.im *Skl2.im);
  Wynik.im = (Skl1.re * Skl2.im) + (Skl1.im * Skl2.re);
  return Wynik;
}
/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  if(KwMod(Skl2)!= 0){
   Wynik.re = ((Skl1.re * Skl2.re) + (Skl1.im *Skl2.im))/(Skl2.re*Skl2.re + Skl2.im*Skl2.im);
   Wynik.im = ((Skl1.im * Skl2.re) - (Skl1.re *Skl2.im))/(Skl2.re*Skl2.re + Skl2.im*Skl2.im);
   
  }
  return Wynik;
}
bool  operator == (LZespolona  Skl1,  LZespolona  Skl2)
{
  return(KwMod(Skl1-Skl2)<0.001);
}
/*!
 * Zwraca wynik sprzężenia danej liczby zespolonej
 */
LZespolona Sprz(LZespolona  LZ){
  LZespolona wynik;
  wynik.re = LZ.re;
  wynik.im = (-1) * LZ.im;
  return wynik;
}
/*!
 * Zwraca kwadrat modułu danej loczby zespolonej
 */
int KwMod(LZespolona  LZ){
  return (LZ.re*LZ.re) + (LZ.im*LZ.im); 
}


