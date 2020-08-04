// Example from pg 101.
#pragma once
#include "Point.h"

class Line
{
private:
	// ax + by + c = 0
	Number a;
	Number b;
	Number c;	
public:
	Line(Point p1, Point p2);				// Line through two points
	Line(Point p, Number xDir, Number yDir);// Line through p with tangent 
	Point intersect(Line line);				// Intersection with line
	Number distance(Point point);			// Distance to a point

private:
	static Number parallelism_tolerance;	// Smallest nonparallel angle
public:
	static Number get_parallelism();
	static void set_parallelism(Number tol);
};
