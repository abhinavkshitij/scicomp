// Example from pg 58.
// Read the ptr syntax backwards to make sense out of it.
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	/* 1. pointer to a const float 
	 * ptr can change, object cannot
	 */
	const float PI = 3.14159;
	const float* p; 
	p = &PI; 
	cout << "PI = " << *p << endl;

	/* 2. const pointer to a float
	 * object can change, ptr cannot
	 */
	float a;
	float* const p1 = &a; 
	*p1 = 9;

	/* 3. const pointer to a const float
	 * object, ptr cannot change
	 */
	const float e = 2.718281828;
	const float* const p2 = &e;

	return 0;
}