// Example from pg 154
#include "Point.h"
#include "LineSegment.h"
#include <cmath>

LineSegment::LineSegment(Point p1, Point p2):
	the_start(p1),
	the_end(p2){
}	

Number LineSegment::length(){
	return sqrt(pow((the_start.x()-the_end.x()),2) + pow((the_start.y()-the_end.y()),2));
}


Point LineSegment::midPoint(){
	return Point(0.5*(the_start.x() + the_end.x()), 0.5*(the_start.y() + the_end.y()));
}

Point LineSegment::start(){
	return Point(the_start);
}

Point LineSegment::end(){
	return Point(the_end);
}