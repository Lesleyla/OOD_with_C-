/*----------------------------------------------------------------
Copyright (c) 2022 Author: Jagadeesh Vasudevamurthy
Filename: complex.cpp
compile: g++ complex.cpp
Memory leaked: 0 bytes
-----------------------------------------------------------------*/
#include "complex.h"

/*--------------------------------------------------------
static definition - only once at the start
Change to false, if you don't need verbose
----------------------------------------------------------*/
bool complex::_display = false;


/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/
//constructor
complex::complex(int x, int y) : _x(x), _y(y), _string(nullptr) {
  updateString();
  if (_display) {
    cout << "in complex constructor: x = " << _x << " y = " << _y << endl;
  }
}

//destructor
complex::~complex() {
  if (_display) {
    cout << "In complex Destructor " << *_string << endl;
  }
#ifdef RAWPOINTER
  delete _string;
#endif
}
complex::complex(const complex& other) : _x(other._x), _y(other._y), _string(nullptr) {
  updateString();
}

//equal operator
complex& complex::operator=(const complex& other) {
  if (this != &other) {
    _x = other._x;
    _y = other._y;
    updateString();
    if (_display) {
      cout << "In complex equal operator " << *_string << endl;
    }
  }
  return *this;
}

//== operator
bool complex::operator==(const complex& other) const {
  if (_display) {
    cout << "in complex == operator" << endl;
  }
  return _x == other._x && _y == other._y;
}

bool complex::operator!=(const complex& other) const {
  cout << "in complex != operator" << endl;
  return !(*this == other);
}

void complex::setxy(int x, int y) {
  _x = x;
  _y = y;
  updateString();
}

//print object c
ostream& operator<<(ostream& os, const complex& c) {
  os << *c._string;
  return os;
}

void complex::updateString() {
#ifdef RAWPOINTER
  if (_string != nullptr) {
    delete _string;
  }
  _string = new string(to_string(_x) + (_y >= 0 ? "+i" : "-i") + to_string(abs(_y)));
#else
  _string = make_unique<string>(to_string(_x) + (_y >= 0 ? "+i" : "-i") + to_string(abs(_y)));
#endif
}
