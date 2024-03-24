/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
Filename: complextest.cpp
compile: g++ complextest.cpp
Memory leaked: 0 bytes
-----------------------------------------------------------------*/
#include "complex.h"

/*----------------------------------------------------------------
main
NOTHING CAN BE CHANGED BELOW
-----------------------------------------------------------------*/
int main() { //mainComplex
#ifdef _WIN32
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  cout << "Display is set to " << complex::display() << endl;
  complex::set_display(true);
  cout << "Display is set to " << complex::display() << endl;
  complex c1(2, 3);
  cout << c1 << endl;
  complex c2(27, -200);
  cout << c2 << endl;
  complex c3(-20, 4);
  cout << c3 << endl;
  complex c4(-18, -99);
  cout << c4 << endl;
  c2.setxy(2, 3);
  cout << c2 << endl;
  if (c1 == c2) {
    cout << "c1 is equal to c2" << endl;
  } else {
    cout << "c1 is NOT equal to c2" << endl;
  }
  if (c1 != c3) {
    cout << "c1 is NOT equal to c3" << endl;
  } else {
    cout << "c1 is equal to c3" << endl;
  }

  complex* c5 = new complex(-200, -800);
  cout << *c5 << endl;
  delete c5;
  c1 = c2 = c3 = c4;
  cout << c3 << endl;
  return 0;
}

// Display is set to 0
// Display is set to 1
// in complex constructor: x = 2 y = 3
// 2+i3
// in complex constructor: x = 27 y = -200
// 27-i200
// in complex constructor: x = -20 y = 4
// -20+i4
// in complex constructor: x = -18 y = -99
// -18-i99
// 2+i3
// in complex == operator
// c1 is equal to c2
// in complex != operator
// in complex == operator
// c1 is NOT equal to c3
// in complex constructor: x = -200 y = -800
// -200-i800
// In complex Destructor -200-i800
// In complex equal operator -18-i99
// In complex equal operator -18-i99
// In complex equal operator -18-i99
// -18-i99
// In complex Destructor -18-i99
// In complex Destructor -18-i99
// In complex Destructor -18-i99
// In complex Destructor -18-i99