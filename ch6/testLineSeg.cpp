// Example from pg 155.
// g++-9 -o testLineSeg Point.cpp Line.cpp LineSegment.cpp testLineSeg.cpp
// ./testLineSeg
#include <iostream>
#include "Point.h"
#include "LineSegment.h"

using namespace std;

// Print point co-ordinates
static void ShowPoint(Point p){
	cout << "(" << p.x() << "," << p.y() << ")" << endl;
	return;
}

int main(int argc, char const *argv[])
{
	Point 		p1;
	Point 		p2(2,0);
	Point 		p3(0,1);
	LineSegment l1(p1,p2);		// Line with endpoints p1, p2

	// Endpoints
	cout << "Start:"; ShowPoint(l1.start());
	cout << "End:"; ShowPoint(l1.end());

	// Length
	cout << "Length = " << l1.length() << endl;

	// Midpoint
	cout << "Midpoint: "; ShowPoint(l1.midPoint());

	return 0;
}