/*----------------------------------------------------------------
Copyright (c) 2024 Author: Jagadeesh Vasudevamurthy
file: examtest.cpp

On linux:
g++ exam.cpp examtest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test exam object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "exam.h"

/*----------------------------------------------------------------
YOUR TEST MUST WORK FOR ALL DATA

    378282246310005,
    371449635398431,
    378734493671000,
    5610591081018250,
    30569309025904,
    38520000023237,
    6011111111111117,
    6011000990139424,
    3530111333300000,
    5105105105105100,
    4111111111111111,
    4012888888881881,
    4222222222222,
    4012888888881880,
    1234567890123456,
-----------------------------------------------------------------*/
static void test() {
  //NOTE YOU CANNOT USE 
  // "378282246310005"  <------- THIS IS STRING 
  //MUST USE AS 378282246310005
  long long int cardNumbers[] = {
      378282246310005LL,
      371449635398431LL,
      378734493671000LL,
      5610591081018250LL,
      30569309025904LL,
      38520000023237LL,
      6011111111111117LL,
      6011000990139424LL,
      3530111333300000LL,
      5105105105105100LL,
      4111111111111111LL,
      4012888888881881LL,
      4222222222222LL,
      4012888888881880LL,
      1234567890123456LL
    };

    for (long long int cardNumber : cardNumbers) {
      int digitCount = exam::getDigitCount(cardNumber);
      int sum = exam::getSumOfDigits(cardNumber);
      bool isvalid = exam::isValid(cardNumber);
      printf("CARD NUMBER = %lld Num digits = %d Sum = %d %s\n",
          cardNumber, digitCount, sum, isvalid ? "Valid" : "Invalid");
    }
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() { //mainexam
#ifdef _WIN32
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  test();
  return 0;
}

//EOF

