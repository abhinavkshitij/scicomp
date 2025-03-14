// Example from pg 99
#include <iostream>
#include "Point.h"
#include "Line.h"

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "Origin created, enter x,y for P" << endl;
	Point origin;

	Number x;
	Number y;
	cout << "Enter x = "; cin >> x;
	cout << "Enter y = "; cin >> y;
	Point p(x,y);
	cout << "Distance OP = " << origin.distance(p) << endl;

	// Access member function with class pointer
	cout << "Point P1(1,2) created" << endl;
	Point p1(1,2);
	Point* p_ptr;
	p_ptr = &origin;
	cout << "Distance OP1 = " << p_ptr->distance(p1) << endl;

	Line l1(Point(1,2), 1,1); // Line through (1,2) at 45 deg
	cout << "Distance between p and l1 = " << p.distance(l1) << endl; 
	return 0;
}