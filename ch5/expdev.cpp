// Example from pg. 133.
#include <iostream>
#include <cmath>
#include "exprandom.h"

// Uncomment to make this static/inline function available here. 
// inline double exp_random(double mu){return -mu*log(random());}

void simulation1(){
	double x1 = exp_random(2.1);
}

double simulation2(){
	return exp_random(3.5);
}

int main(int argc, char const *argv[])
{
	simulation1();
	std::cout << simulation2() << std::endl;
	return 0;
}