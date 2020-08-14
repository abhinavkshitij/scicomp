// Example from pg 198
#include "Rational.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int* p = new int; // new operator calls class constructor
	int* q = new int(3); // new operator calls constructor for int, init to 3
	Rational* r = new Rational(8,9);	
	int* qa = new int[2]; // int array of 2 elements
	Rational* ra = new Rational[5]; // Rational array of 5 elements  

	cout << *p << " " << *q << " " << *r << endl;
	cout << "Rational array elements init to " << *ra << endl;

	delete p;
	delete q;
	delete r;
	delete[] qa;
	delete[] ra;
	

	return 0;
}
