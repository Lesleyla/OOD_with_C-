/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: intmatrix2.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has intmatrix2  class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#pragma once

/*----------------------------------------------------------------
NOTHING CAM BE ADDED except ../util/util.h
-----------------------------------------------------------------*/
#include "../util/util.h"


/*----------------------------------------------------------------
Declaration of intmatrix2 class
-----------------------------------------------------------------*/
class intmatrix2 {
public:
  //WRITE CODE.
  //CANNOT DECLARE ANY GLOBAL VARIABLE
  // Constructor
  intmatrix2();
  intmatrix2(int r, int c);
  intmatrix2(int r, int c, int val);
  intmatrix2(const std::string& str);
  ~intmatrix2(); // Destructor
  intmatrix2(const intmatrix2& rhs); // Copy constructor
  intmatrix2& operator=(const intmatrix2& rhs); // Assignment operator
  operator bool() const;
  bool isEqual(const intmatrix2& other);
  intmatrix2 add(const intmatrix2& other) const;
  intmatrix2 mult(const intmatrix2& other) const;

  //USE this as is. I will explain when I show
  static void makeShowOn() {_show = true;}
  static void makeShowOff() {_show = false;}
  static bool show() {return _show ;} 

private:
  static bool _show ; //MUST USE THIS
  //WRITE CODE BELOW. MUST USE STL
  int rows_;
  int cols_;
  int** mat_;

  friend std::ostream& operator<<(std::ostream& os, const intmatrix2& mat);
  //use xxx_ so that we know all variables are private
};

//EOF

