/*----------------------------------------------------------------
Copyright (c) 2022 Author: Jagadeesh Vasudevamurthy
file: sarray.cpp
-----------------------------------------------------------------*/

#include "sarray.h"

bool Sarray::show = false;
unsigned long long Sarray::num_allocated = 0;
unsigned long long Sarray::num_freed = 0;

Sarray::Sarray(unsigned size) : size_(size), ptr_(nullptr) {
    allocate(size_);
}

Sarray::Sarray(const Sarray& other) : size_(0), ptr_(nullptr) {
    if (show) {
        std::cout << "calling copy constructor of size " << other.size_ << std::endl;
    }
    copy(other);
}

Sarray& Sarray::operator=(const Sarray& other) {
    if (this != &other) {
        if (show) {
            std::cout << "calling equal operator size " << other.size_ << std::endl;
        }
        deallocate();
        copy(other);
    }
    return *this;
}

Sarray::~Sarray() {
    deallocate();
}

#ifdef MOVE
Sarray::Sarray(Sarray&& other) : size_(other.size_), ptr_(other.ptr_) {
    other.size_ = 0;
    other.ptr_ = nullptr;
    if (show) {
        std::cout << "calling move constructor of size " << size_ << std::endl;
    }
}

Sarray& Sarray::operator=(Sarray&& other) {
    if (this != &other) {
        if (show) {
            std::cout << "calling move equal operator size " << other.size_ << std::endl;
        }
        //leaves other in a valid but unspecified state
        deallocate();
        size_ = other.size_;
        other.size_ = 0;
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }
    return *this;
}
#endif

void Sarray::allocate(unsigned size) {
    if (show) {
        std::cout << "Allocating array of size " << size << std::endl;
    }
    if (size > 0) {
        ptr_ = new T[size];
        num_allocated += size;
    }
}

void Sarray::deallocate() {
    if (ptr_) {
        if (show && size_ > 0) {
            std::cout << "Freeing array of size " << size_ << std::endl;
        }
        delete[] ptr_;
        num_freed += size_;
        ptr_ = nullptr;
        size_ = 0;
    } else {
        std::cout << "Nothing freed. Array was taken by move/equal operator" << std::endl;
    }
}

void Sarray::copy(const Sarray& other) {
    if (other.size_ > 0) {
        size_ = other.size_;
        allocate(size_);
        for (unsigned i = 0; i < size_; ++i) {
            ptr_[i] = other.ptr_[i];
        }
    }
}


void Swap(Sarray& a, Sarray& b) {
    Sarray temp(std::move(a)); // Move construct temp from a
    a = std::move(b);          // Move assign a from b
    b = std::move(temp);       // Move assign b from temp
}