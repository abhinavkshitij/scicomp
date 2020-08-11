// Example from pg 155
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	// Built-in variables can be defined in a constructor-like manner 
 	int i = 3;
	int j(3); 	// defined 
	cout << i << j << endl;

	/* The parenthesis must be omitted if there are no constructor arguments
	 * (or for built-in types, initializer); other a function prototype is created
	 */ 

	int f1(); 	// f1 is a function returning int, taking no args
	int f2; 	// f2 is an int
	Point p4(); // p4 is a function returning Point, taking no args
	Point p5;	// p5 is a Point
	
	return 0;
}