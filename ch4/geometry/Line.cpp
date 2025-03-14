// Example from pg 101.
#include "Point.h"
#include "Line.h"
#include <cmath>
#include "float.h"

// Line through p1, p2
Line::Line(Point p1, Point p2){
	if (p1.x() == p2.x()){ 	// Vertical line
		a = 1;
		b = 0;
		c = -p1.x();
	}
	else{
		a = p2.y() - p1.y();
		b = p1.x() - p2.x();
		c = p1.y()*p2.x() - p2.y()*p1.x();
	}
}

// Line: Point-direction
Line::Line(Point p, Number xDir, Number yDir){
	a = yDir;
	b = -xDir;
	c = xDir*p.y() - yDir*p.x();
}

// Point-Line intersection
Point Line::intersect(Line line){
	/* Intersect with line. If the angle between the two lines is less than the
	 * parallism_tolerance, return the point at infinity. The parallelism test
	 * computes the square of the sin of the angle. We assume that the tolerance
	 * is small enough for sin(theta) to be approx equal to theta.
	 */
	Number det = a*line.b - line.a*b;
	Number sinsq = (det*det)/(a*a+b*b)*(line.a*line.a + line.b*line.b);
	if (sinsq < parallelism_tolerance*parallelism_tolerance){
		return Point(FLT_MAX,FLT_MAX); // Point at infinity (FLT_MAX.h)
	}
	else{
		return Point( (b*line.c - line.b*c)/det, (c*line.a - line.c*a)/det);
	}
}	

// Point-line distance			
Number Line::distance(Point point){
	return abs(a*point.x() + b*point.y() + c) / sqrt(a*a+b*b);
}			

// Static members
Number Line::parallelism_tolerance = 0.01745;	// Initialize tolerance

Number Line::get_parallelism(){
	return parallelism_tolerance;
}

void Line::set_parallelism(Number tol){
	parallelism_tolerance = tol;
}