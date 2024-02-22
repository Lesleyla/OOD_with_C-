/*----------------------------------------------------------------
Copyright (c) 2020 Author: Jagadeesh Vasudevamurthy
file: ninetynine1.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ninetynine1 class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ninetynine1.h"
/*----------------------------------------------------------------
Ninety nine bottles of beer on the wall,
Ninety nine bottles of beer,
Take one down, pass it around,
Ninety eight bottles of beer on the wall.

Two bottles of beer on the wall,
Two bottles of beer,
Take one down, pass it around,
One bottle of beer on the wall.

One bottle of beer on the wall,
One bottle of beer,
Take one down, pass it around,
Zero bottle of beer on the wall.
(91)
a = Ninety
b = one
(90)
c = Ninety
d = ""
*----------------------------------------------------------------*/
void ninetynine1::_print(const char* a, const char* b, bool b1, const char*  c, const char* d, bool b2) {
  //NOTHING CAN BE CHANGED
  const char* bot = bottle[b1];
  cout << a << " " << b << " " << bot << " of beer on the wall," << endl;
  cout << a << " " << b << " " << bot << " of beer," << endl;
  cout << "Take one down, pass it around," << endl;
  bot = bottle[b2];
  cout << c << " " << d << " " << bot << " of beer on the wall," << endl;
  cout << endl;
}

/*----------------------------------------------------------------
compute string method implementation
*----------------------------------------------------------------*/
bool ninetynine1::_compute_string(int n, const char*& tensPlace, const char*& onesPlace) {
  bool isSingular = (n <= 1);
  if (n < 10) onesPlace = ones[n];
  else if (n < 20) onesPlace = teens[n - 10];
  else {
    if (n % 10 == 0) tensPlace = tens[n / 10];
    else {
      tensPlace = tens[n / 10];
      onesPlace = ones[n % 10];
    }
  }
  return isSingular;
}

bool ninetynine1::_compute_string(int n, const char** tensPlace, const char** onesPlace) {
  bool isSingular = (n <= 1);
  if (n < 10) *onesPlace = ones[n];
  else if (n < 20) *onesPlace = teens[n - 10];
  else {
    if (n % 10 == 0) *tensPlace = tens[n / 10];
    else {
      *tensPlace = tens[n / 10];
      *onesPlace = ones[n % 10];
    }
  }
  return isSingular;
}

/*----------------------------------------------------------------
compute strings using Reference
*----------------------------------------------------------------*/
void ninetynine1::_stanzaReference(int n) {
  const char* a = "";
  const char* b = "";
  const char* c = "";
  const char* d = "";

  bool b1 = _compute_string(n, a, b);
  bool b2 = _compute_string(n - 1, c, d);
  _print(a, b, b1, c, d, b2);
}

/*----------------------------------------------------------------
compute strings using Pointers
*----------------------------------------------------------------*/
void ninetynine1::_stanzaPointer(int n) {
  const char* a = "";
  const char* b = "";
  const char* c = "";
  const char* d = "";

  bool b1 = _compute_string(n, &a, &b);
  bool b2 = _compute_string(n - 1, &c, &d);
 
  _print(a, b, b1, c, d, b2);
}

/*----------------------------------------------------------------
NOTHING CAN BE CHANGED BELOW
*----------------------------------------------------------------*/
void ninetynine1::run() {
  cout << "Reference based song\n";
  for (int i = MAX; i > 0; --i) {
    _stanzaReference(i);
  }
  cout << "Pointer based song\n";
  for (int i = MAX; i > 0; --i) {
    _stanzaPointer(i);
  }
}

//EOF

