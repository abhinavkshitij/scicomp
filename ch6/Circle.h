// Example from pg. 155
#include "Point.h"
#include "LineSegment.h"

class Circle
{
private:
	Point the_center;
	double the_radius;	
public:
	Circle(double radius);
	Circle(Point center, double radius);
	Circle(Point p1, Point p2, Point p3);
	Circle(LineSegment chord, Point p);
	Circle(LineSegment diameter);
	Point centerOfCircleThrough(Point p1, Point p2, Point p3);
	Point center();
	Number radius();
};