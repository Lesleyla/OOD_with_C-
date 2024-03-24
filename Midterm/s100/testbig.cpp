/*----------------------------------------------------------------
Copyright (c) 2024 Author: Jagadeesh Vasudevamurthy
file: testbig.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
																				NOTHING CAN BE CHANGED IN THIS FILE
																				DO NOT POST THIS FILE IN CANVAS
																				WE WILL USE DIFFERENT TEST FOR GRAING
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
ONLY INCLUDE HERE. YOU CANNOT ADD ANYTHING HEREe
-----------------------------------------------------------------*/
#include "longnumber.h"

static int marks = 5;

/*--------------------------------------------------------
long number class
----------------------------------------------------------*/
class testbig {
public:
		testbig() {
				small_test_();
				//real_exam_();
		}

private:
		void small_test_();
	
		void basic_();
		void test_add_();
		void test_add_(const int a, const int b, const int ans, bool display = true);
		void test_add_(const char* a, const char* b, const char* ans, bool display = true);
		void test_multiply_();
		void test_multiply_(const int  a, const int  b, const int ans, bool display = true);
		void test_multiply_(const char* a, const int  b, const char* ans, bool display = true);
		void test_factorial_();
		void test_factorial_(int n, const char* s);
};

/*----------------------------------------------------------------
small test
-----------------------------------------------------------------*/
void testbig::small_test_() {
		cout << "------------------  small tests starts ----------------\n";
#if 1
		{
				longnumber l;
				cout << "l = " << l << endl;
				cout << "Your marks so for " << marks << endl;
		}
#endif
#if 1
		{
				int k = -1986;
				const char* n = "1986";
				longnumber l(k);
				cout << "l(unsigned int) = " << l << endl;
				int start = 0;
				int d = l.num_digits();
				for (int i = 0; i < d; ++i) {
						int c = l[i] - '0';
						int rc = n[i + start] - '0';
						assert(c == rc);
				}
				marks += 5;
				cout << "Your marks so for " << marks << endl;
		}
#endif
#if 1
		{
				const char* n = "-123567890123567890123567890123567890123567890123567890123567890";
				longnumber l(n);
				cout << "l(const char* n) = " << l << endl;
				assert(l.is_negative());
				int start = 1;
				int d = l.num_digits();
				for (int i = 0; i < d; ++i) {
						int c = l[i] - '0';
						int rc = n[i + start] - '0';
						assert(c == rc);
				}
				marks += 5;
				cout << "Your marks so for " << marks << endl;
		}
#endif

#if 1
		{
				test_add_(1986, 19, (1986 + 19));
				marks += 5;
				cout << "Your marks so for " << marks << endl;
		}
#endif

#if 1
		{
				test_add_("99", "1", "100");
				marks += 5;
				cout << "Your marks so for " << marks << endl;
		}
#endif
#if 1
		{
				test_multiply_(1986, 19, (1986 * 19));
				marks += 5;
				cout << "Your marks so for " << marks << endl;
		}
#endif
#if 1
		{
				test_multiply_("89977", 46, "4138942");
				marks += 5;
				cout << "Your marks so for " << marks << endl;
		}
#endif
#if 1
		{
				const char* a = "3628800";
				test_factorial_(10, a);
				marks += 15;
				cout << "Your marks so for " << marks << endl;
		}
#endif
		cout << "I will make you suffer in real exam" << endl;
		cout << "You should take easy 85 tests\n";
}

/*----------------------------------------------------------------
test add
-----------------------------------------------------------------*/
void testbig::test_add_(const int  a, const int  b, const int ans, bool display) {
		longnumber c = a + b;
		if (c != ans || display) {
				cout << "-----------------------------------------------------\n";
				cout << "a = " << a << endl;
				cout << "b = " << b << endl;
				cout << "c = " << c << endl;
				if (c != ans) {
						cout << "Expected ans was " << ans << endl;
						assert(false);
				}
		}
}

/*----------------------------------------------------------------
test add
-----------------------------------------------------------------*/
void testbig::test_add_(const char* a, const char* b, const char* ans, bool display) {
		longnumber c = longnumber(a) + longnumber(b);
		longnumber lans = longnumber(ans);
		if (c != lans || display) {
				cout << "-----------------------------------------------------\n";
				cout << "a = " << a << endl;
				cout << "b = " << b << endl;
				cout << "c = " << c << endl;
				if (c != lans) {
						cout << "Expected ans was " << ans << endl;
						assert(false);
				}
		}
}

/*----------------------------------------------------------------
test mult
-----------------------------------------------------------------*/
void testbig::test_multiply_(const int  a, const int  b, const int ans, bool display) {
		longnumber c = longnumber(a) * b;
		longnumber lans = longnumber(ans);
		if (c != lans || display) {
				cout << "-----------------------------------------------------\n";
				cout << "a = " << a << endl;
				cout << "b = " << b << endl;
				cout << "c = " << c << endl;
				if (c != lans) {
						cout << "Expected ans was " << ans << endl;
						assert(false);
				}
		}
}

/*----------------------------------------------------------------
test mult
-----------------------------------------------------------------*/
void testbig::test_multiply_(const char* a, const int  b, const char* ans, bool display) {
		longnumber c = longnumber(a) * b;
		longnumber lans = longnumber(ans);
		if (c != lans || display) {
				cout << "-----------------------------------------------------\n";
				cout << "a = " << a << endl;
				cout << "b = " << b << endl;
				cout << "c = " << c << endl;
				if (c != lans) {
						cout << "Expected ans was " << ans << endl;
						assert(false);
				}
		}
}


/*----------------------------------------------------------------
test factorial
-----------------------------------------------------------------*/
void testbig::test_factorial_(int n, const char* s) {
		longnumber ans(s);
		std::clock_t c_start = std::clock();
		longnumber a = longnumber::fact(n);
		std::clock_t c_end = std::clock();
		double time_elapsed_ms = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
		cout << "Factorial of " << n << " = " << endl;
		cout << a << endl;
		if (a != ans) {
				cout << "Expected ans was " << ans << endl;
		}
		cout << "CPU time used: " << time_elapsed_ms / 1000 << " seconds\n";
		assert(a == ans);
}

/*----------------------------------------------------------------
The main
-----------------------------------------------------------------*/
int main() {
#ifdef _WIN32
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
		cout << "------- Start----------\n";
		testbig l;
		cout << "num_allocated = " << longnumber::num_allocated << endl;
		cout << "num_released = " << longnumber::num_released << endl;
		if (longnumber::num_allocated == 0 && longnumber::num_released == 0) {
				cout << "You have NO CLUE about this class\n";
				assert(0);
		}
		if (longnumber::num_allocated != longnumber::num_released) {
				cout << "You are not releasing memory. Will loose 10 marks\n";
				assert(0);
		}
		cout << "------- END----------\n";
		return 0;
}
