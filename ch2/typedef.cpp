// Example from pg 51.
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	// 1. Typedef performs no type conversion check
	typedef int distance;
	typedef float force; // call float force, no type checking

	distance d = 10;
	force f;
	f = d/7; // divide int by prime -> float
	cout << "There is no type-conversion with typedef" << endl;
	cout << "Divide d(int) by 7 to get f(float) = " << f << endl; 
	// prints int, not float
	cout << endl;

	/* 2. The most important use of typdef is plan for change.
	 * A program running on a personal computer with limited 
	 * memory might require to run on single precision, while
	 * the same code when run on a large machine can use double
	 * precision.  
	 */

	// Small machine (short int, float)
	// Large machine (long int, double)
	typedef long int intNumber;
	typedef double floatNumber;

	intNumber step = 8;
	floatNumber length = 5.0;

	// Print datatype using "typeid(<var>).name()"
	cout << "int type = " << typeid(step).name() << endl; 
	cout << "float type = " << typeid(length).name() << endl; 
	return 0;
}