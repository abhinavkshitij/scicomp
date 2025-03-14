// Example from pg 98.
#pragma once
typedef float Number;
class Line; // Forward declaration to Line.h

class Point
{
private:
	Number the_x;
	Number the_y;	
public:
	Point();						// Create uninitialized
	Point(Number x, Number y);		// Create from (x,y)
	Number distance(Point point);	// Distance to another point
	Number distance(Line line);		// Distance to a line
	Number x();						// Get x-coordinate
	Number y(); 					// Get y-coordinate
};

