// Example from pg 98.
#include "Point.h"
#include "Line.h"
#include <cmath>

Point::Point(){
	the_x = 0.0;
	the_y = 0.0;
}						

Point::Point(Number x, Number y){		
	the_x = x;
	the_y = y;
}

Number Point::distance(Point point){
	Number x_diff = the_x - point.the_x;
	Number y_diff = the_y - point.the_y;
	return sqrt (x_diff*x_diff + y_diff*y_diff);
}	

// Distance to a line - pass Point ptr into Line.distance()  
Number Point::distance(Line line){
	return line.distance(*this);
};		

Number Point::x(){
	return the_x;
}

Number Point::y(){
	return the_y;
}


