// Example from pg 102
#include <iostream>
#include "Point.h"
#include "Line.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Line l1(Point(0,0), Point(0,1)); // x = 1
	Line l2(Point(1,1), 0, 1); // Line through (1,2) at 45 deg

	cout << l2.get_parallelism() << endl;
	Line::set_parallelism(0.0124); // Change parallelism tolerance (static member)
	cout << l1.get_parallelism() << endl;

	// Point of intersection
	Point intersection;
	intersection = l1.intersect(l2);
	cout << "(" << intersection.x() << "," << intersection.y() << ")" << endl;

	return 0;
}