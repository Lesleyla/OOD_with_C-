/*----------------------------------------------------------------
Copyright (c) 2024 Author: Jagadeesh Vasudevamurthy
file: exam.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has exam class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "exam.h"

/*----------------------------------------------------------------
Definition of all routines
-----------------------------------------------------------------*/
int exam::getDigitCount(long long int number) {
    int count = 0;
    while (number != 0) {
        count++;
        number /= 10;
    }
    return count;
}
int exam::getSumOfDigits(long long int number) {
    int sum = 0;
    bool alternate = false;
    int digits = getDigitCount(number);

    for (int i = 0; i < digits; ++i) {
        int digit = number % 10;
        if (alternate) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }
        sum += digit;
        alternate = !alternate;
        number /= 10;
    }
    return sum;
}

bool exam::isValid(long long int cardNumber) {
    int digitCount = getDigitCount(cardNumber);
    if (digitCount != 16) {
        return false;
    }

    int sum = getSumOfDigits(cardNumber);
    return sum % 10 == 0;
}

//EOF


