/*----------------------------------------------------------------
Copyright (c) 2024 Author: Jagadeesh Vasudevamurthy
file: longnumber.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
ONLY INCLUDE HERE. YOU CANNOT ADD ANYTHING HERE
-----------------------------------------------------------------*/
#include "longnumber.h"

/*--------------------------------------------------------
must allocate space in cpp file
----------------------------------------------------------*/
unsigned long long longnumber::num_allocated = 0;
unsigned long long longnumber::num_released = 0;
//helper functions

inline std::string intToString(int n) {
	std::ostringstream ss;
	ss << n;
	return ss.str();
}
inline void reverseString(std::string &str) {
    std::reverse(str.begin(), str.end());
}

std::string addStringNumbers(const std::string &num1, const std::string &num2) {
    std::string result;
    int carry = 0;
    int sum = 0;
    size_t n1 = num1.size(), n2 = num2.size();
    reverseString(result);
    
    for (size_t i = 0; i < n1 || i < n2 || carry; ++i) {
        sum = carry;
        if (i < n1) sum += num1[i] - '0';
        if (i < n2) sum += num2[i] - '0';
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    reverseString(result);
    return result;
}

std::string multiplyStringWithDigit(const std::string &num, int digit) {
    if (digit == 0) return "0";

    std::string result;
    int carry = 0;
    for (int i = num.size() - 1; i >= 0; --i) {
        int product = (num[i] - '0') * digit + carry;
        result.push_back(product % 10 + '0');
        carry = product / 10;
    }

    while (carry) {
        result.push_back(carry % 10 + '0');
        carry /= 10;
    }

    reverseString(result);
    return result;
}





longnumber::longnumber(int n) : s_(new std::string(intToString(std::abs(n)))), isNegative(n < 0) {
    ++num_allocated;
}

longnumber::longnumber(const char* n) : s_(new std::string(n)), isNegative(n[0] == '-') {
    if (isNegative) {
        s_->erase(0, 1);
    }
    ++num_allocated;
}


longnumber::longnumber(const longnumber& other) : s_(new std::string(*other.s_)), isNegative(other.isNegative) {
    ++num_allocated;
}

longnumber::~longnumber() {
    delete s_;
    s_ = nullptr;
    ++num_released;
}

longnumber& longnumber::operator=(const longnumber& other) {
    if (this != &other) {
        delete s_;
        s_ = new std::string(*other.s_);
		isNegative = other.isNegative;
    }
    return *this;
}

bool longnumber::operator==(const longnumber& other) const {
    return *s_ == *other.s_;
}

bool longnumber::operator!=(const longnumber& other) const {
    return !(*this == other);
}

longnumber longnumber::operator+(const longnumber& other) const {
    std::string sum = addStringNumbers(*this->s_, *other.s_);
    return longnumber(sum.c_str());
}

longnumber longnumber::operator*(int value) const {
    std::string product = multiplyStringWithDigit(*this->s_, value);
    return longnumber(product.c_str());
}

bool longnumber::is_positive() const {
	return isNegative;
}

bool longnumber::is_negative() const {
	return isNegative;
}

int longnumber::num_digits() const {
    return s_->length();
}

std::ostream& operator<<(std::ostream& os, const longnumber& num) {
	if (num.is_negative()) {
        os << '-';
    }
    for (size_t i = 0; i < num.s_->length(); ++i) {
        if (i > 0 && i % 40 == 0) {
            os << "\n";
        }
        os << (*num.s_)[i];
    }
    return os;
}

/*--------------------------------------------------------
Factorial of n.
Must use my code below
----------------------------------------------------------*/
longnumber longnumber::fact(int n) {
	longnumber a(1);
	for (int i = 2; i <= n; ++i) {
			a = a * i;
	}
	return a;
}
//EOF