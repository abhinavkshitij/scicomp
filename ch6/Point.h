/* Example from pg. 153; adapted from ch4/geometry/Point.h
 * ---
 * By adding const after the list formal arguments, 
 * the function is prevented to make any change to
 * member data, whether private or public.
 */ 
#pragma once
#include <iostream>
#include <cmath>
using namespace std;
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
	Number angle(Point p1, Point p2); 	// Angle between two points 
										// (p1.angle(p2,p3), vertex at 2)
	Number& x();						// Reference to x-coordinate
	Number x() const;					// Get x-coordinate
	Number& y();						// Reference to y-coordinate
	Number y() const; 					// Get y-coordinate


	friend istream& operator>>(istream& input, Point& pt){
		input >> pt.the_x >> pt.the_y;
		return input;
	}	

	friend ostream& operator<<(ostream& output, Point& pt){
		cout << '(' << pt.x() << ',' << pt.y() << ')';
		return output;
	}	
};

