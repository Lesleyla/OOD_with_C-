/*----------------------------------------------------------------
Copyright (c) 2022 Author: Jagadeesh Vasudevamurthy
file: sarray.h
-----------------------------------------------------------------*/
#pragma once
#include "../util/util.h"

#define T int

//MUST Attach two outputs with and without move
#define MOVE


class Sarray {
public:
	Sarray(unsigned size = 0);
    Sarray(const Sarray& other);
    Sarray& operator=(const Sarray& other); // Copy assignment operator
    ~Sarray();

#ifdef MOVE
	Sarray(Sarray&& other); // Move constructor
    Sarray& operator=(Sarray&& other); // Move assignment operator
#endif

	friend void Swap(Sarray& a, Sarray& b); // Add this line

	static bool show;
	static unsigned long long num_allocated;
	static unsigned long long num_freed;


private:
	unsigned size_;
	T* ptr_;

	//private funcions
	void allocate(unsigned size);
    void deallocate();
    void copy(const Sarray& other);
		
};



