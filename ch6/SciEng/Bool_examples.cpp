// Example from pg 160
#include "Boolean.h"
#include <iostream>

using namespace std;

Boolean has_real_soln(double a, double b, double c){
	// Does ax^2 + bx + c = 0 have a real solution
	return (b*b) >= 4*a*c;
}

int main(int argc, char const *argv[])
{
	Boolean b1(Boolean::True);		// calls Boolean(int)
	Boolean b2(3);					// calls Boolean(int)
	int* p_i = new int(0);			// ptr to int object
	Boolean b3(p_i);				// calls Boolean(void*)
	Boolean b4(3.5);				// calls Boolean(float)

	cout << "b1 = " << b1 << endl;
	cout << "b2 = " << b2 << endl;
	cout << "*p_i = " << *p_i << endl;
	cout << "b3 = " << b3 << endl;
	cout << "b4 = " << b4 << endl;	

	// Using negation operator 
	if 	(!has_real_soln(2,0.5,5)){
		cout << "No real soln" << endl; 
	}

	return 0;
}
