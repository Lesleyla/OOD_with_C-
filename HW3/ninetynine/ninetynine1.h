/*----------------------------------------------------------------
Copyright (c) 2020 Author: Jagadeesh Vasudevamurthy
file: ninetynine1.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ninetynine1 class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#pragma once
#include "../util/util.h"

/*----------------------------------------------------------------
Declaration of ninetynine1 class
-----------------------------------------------------------------*/
class ninetynine1 {
  private:
    const int MAX = 99;

    const char* ones[10] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    const char* tens[10] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    const char* teens[10] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

    const char* bottle[2] = {"bottles", "bottle"};
    void _print(const char* a, const char* b, bool b1, const char* c, const char* d, bool b2);
    bool _compute_string(int n, const char*& tensPlace, const char*& onesPlace);
    bool _compute_string(int n, const char** tensPlace, const char** onesPlace);
    void _stanzaReference(int n);
    void _stanzaPointer(int n);

  public:
    void run();
};


