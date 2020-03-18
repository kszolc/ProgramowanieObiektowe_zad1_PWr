#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};



/* 
 * Przeciążenie operatora plus
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
/* 
 * Przeciążenie operatora minus
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
/* 
 * Przeciążenie operatora podziel
 */
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
/* 
 * Przeciążenie operatora pomnóż
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona Sprz(LZespolona  LZ);
int KwMod(LZespolona  LZ);
#endif
