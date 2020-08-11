// Example from pg 154
#pragma once
#include "Point.h"

class LineSegment
{
private:
	Point the_start;
	Point the_end;
public:
	LineSegment(Point p1, Point p2);	// Line through two points
	Number length();					// Length
	Point midPoint();					// Midpoint 
	Point start();
	Point end();
};
