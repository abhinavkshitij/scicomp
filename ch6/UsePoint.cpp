// Example from pg 153.

#include <iostream>
#include "Point.h"
#include "Line.h"

using namespace std;

int main(int argc, char const *argv[])
{
	// Create non-const Point object
	Point p1(2,3);
	cout << p1.x() << endl;	// Uses non-const x()
	p1.x() = 1;				// Uses non-const x()
	p1.y() = 2;				// Uses non-const y()

	// Create a const Point object
	const Point p2 = p1;
	cout << p2.x() << endl;	// Uses const x()
	// Cannot re-≥assign const objects 
	p2.x() = 3;				// WRONG:lvalue required as left operand of assignment
	p2.y() = 4;				// WRONG:lvalue required as left operand of assignment

	return 0;
}