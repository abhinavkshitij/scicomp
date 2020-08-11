// Example from pg 155.
// g++-9 -o testCircle Point.cpp Line.cpp LineSegment.cpp Circle.cpp testCircle.cpp
// ./testCircle
#include <iostream>
#include "Point.h"
#include "LineSegment.h"
#include "Circle.h"

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
	Circle 		ca(l1,p3);		// Circle with chord l1 through p3
	Circle 		cb(l1);			// Circle with diameter
	Circle  	cc(p1,p2,p3);	

	// Circle center, radius
	cout << "Center: "; ShowPoint(cb.center());
	cout << "Radius = " << cb.radius() << endl;

	// Example of copy construction by initialization from pg. 158
	cout << "Creating a copy of cb " << endl;
	Circle 		c2(cb);

	// Circle center, radius
	cout << "Center: "; ShowPoint(c2.center());
	cout << "Radius = " << c2.radius() << endl;

	// Example of copy construction by assignment from pg. 158
	cout << "Creating a copy by initialization " << endl;
	Circle 		c3 = 10.0; 
	/* Create Circle(10.0) then initialize c3 from it
	 * NOTE: The (=) sign doesn't stand for assignment;
	 * but a new Circle object of r=10 is created and 
	 * copied into c3.
	 */

	// Circle center, radius
	cout << "Center: "; ShowPoint(c2.center());
	cout << "Radius = " << c2.radius() << endl;


	return 0;
}