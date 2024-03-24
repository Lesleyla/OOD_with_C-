/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
Filename: complex.h
-----------------------------------------------------------------*/
#ifndef complex_h
#define complex_h

#include "../util/util.h"

/*----------------------------------------------------------------
Comment on of the two
-----------------------------------------------------------------*/
#define RAWPOINTER
//#define UNIQUEPOINTER

/*----------------------------------------------------------------
complex class
-----------------------------------------------------------------*/
class complex {
public:
  complex(int x = 0, int y = 0);
  ~complex();
  complex(const complex& other);
  complex& operator=(const complex& other);
  bool operator==(const complex& other) const;
  bool operator!=(const complex& other) const;
  void setxy(int x, int y);
  friend ostream& operator<<(ostream& os, const complex& c);

  //WRITE ALL PUBLIC FUNCTION
  static bool display() { return _display; }
  static void set_display(bool x) { _display = x; }

private:
  int _x;
  int _y;
#ifdef RAWPOINTER
  string* _string;
#endif
#ifdef UNIQUEPOINTER   
  unique_ptr<string> _string;
#endif
  static bool _display; /* ONLY ONCE for all object */
  void updateString();
};

#endif

