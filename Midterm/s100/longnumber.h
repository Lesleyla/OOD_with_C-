/*----------------------------------------------------------------
Copyright (c) 2024 Author: Jagadeesh Vasudevamurthy
file: longnumber.h
-----------------------------------------------------------------*/

#pragma once

/*----------------------------------------------------------------
Basic include files.
CANNOT CHANGE OR ADD ANY LIBRARY
-----------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>      // std::setprecision
using namespace std;

#ifdef _WIN32
#include <cassert>
#include <ctime>
#else
#include <assert.h>
#include <time.h>
#include <string.h> //for strlen,strcat and strcpy on linux
#endif

/*--------------------------------------------------------
long number class
----------------------------------------------------------*/
class longnumber {
public:
	longnumber(int n = 0);
	//Write remaining

	longnumber(const char* n);
    longnumber(const longnumber& other);
    ~longnumber();

	//I have implemented this function
	//longnumber l(1986)
	// char c = l[0] //gives 1
	char& operator[](int i) const {
		string& s = *(s_);
		return s[i];
	}
	// Operator
	longnumber& operator=(const longnumber& other);
    bool operator==(const longnumber& other) const;
    bool operator!=(const longnumber& other) const;
    longnumber operator+(const longnumber& other) const;
    longnumber operator*(int value) const;

	bool is_positive() const;
	bool is_negative() const;
	int num_digits() const;
	static longnumber fact(int n);
	static unsigned long long num_allocated;
	static unsigned long long num_released;

    friend std::ostream& operator<<(std::ostream& os, const longnumber& num);

private:
	string* s_ = nullptr; //MUST USE ONLY THIS
	//You can have any number of C++ primitives you want
    bool isNegative;
	
	friend std::string addStringNumbers(const std::string &num1, const std::string &num2);
    friend std::string multiplyStringWithDigit(const std::string &num, int digit);
};

//EOF


