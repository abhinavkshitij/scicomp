/* Example from pg. 153; adapted from ch4/geometry/Point.h
 * ---
 * By adding const after the list formal arguments, 
 * the function is prevented to make any change to
 * member data, whether private or public.
 */ 
#pragma once
typedef float Number;
class Line; // Forward declaration to Line.h

class Point
{
private:
	Number the_x;
	Number the_y;	
public:
	Point();							// Default: origin
	Point(Number x, Number y);			// Create from (x,y)
	Number distance(Point point) const;	// Distance to another point
	Number distance(Line line) const;	// Distance to a line
	Number& x();						// Reference to x-coordinate
	Number x() const;					// Get x-coordinate
	Number& y();						// Reference to y-coordinate
	Number y() const; 					// Get y-coordinate
};

