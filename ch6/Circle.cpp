// Example from pg. 155
#include "Point.h"
#include "LineSegment.h"
#include "Circle.h"


Circle::Circle(double radius):
	the_center(0,0),
	the_radius(radius){}

Circle::Circle(Point center, double radius):
	the_center(center),
	the_radius(radius){}

Circle::Circle(Point p1, Point p2, Point p3):
	the_center(centerOfCircleThrough(p1,p2,p3)),
	the_radius(the_center.distance(p1)){}

Circle::Circle(LineSegment chord, Point p):
	the_center(centerOfCircleThrough(chord.start(),chord.end(),p)),
	the_radius(the_center.distance(p)){}

Circle::Circle(LineSegment diameter):
	the_center(diameter.midPoint()),
	the_radius(0.5*diameter.length()){}

Point Circle::centerOfCircleThrough(Point p1, Point p2, Point p3){
	return Point (0,0); // dummy value
}	

Point Circle::center(){
	return Point(the_center); 
}

Number Circle::radius(){
	return the_radius;
}

