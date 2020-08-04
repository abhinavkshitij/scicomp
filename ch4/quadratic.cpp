// Example from pg 122.
#include "quadratic.h"
#include <cmath>

QuadraticPolynomial::QuadraticPolynomial(double c1, double c2, double c3)
{
	a = c1;
	b = c2;
	c = c3;
}

QuadraticPolynomial::RealRoots::RealRoots(double x1, double x2)
{
	if (x1 < x2){
		min_root = x1;
		max_root = x2;
	}
	else{
		min_root = x2;
		max_root = x1;
	}
}

double QuadraticPolynomial::RealRoots::minRoot(){return min_root;}
double QuadraticPolynomial::RealRoots::maxRoot(){return max_root;}
QuadraticPolynomial::RealRoots::~RealRoots(){}


QuadraticPolynomial::ComplexRoots::ComplexRoots(ComplexNumber z1, ComplexNumber z2)
{
	root_1 = z1;
	root_2 = z2;	
}

ComplexNumber QuadraticPolynomial::ComplexRoots::Root1(){return root_1;}
ComplexNumber QuadraticPolynomial::ComplexRoots::Root2(){return root_2;}
QuadraticPolynomial::ComplexRoots::~ComplexRoots(){}


QuadraticPolynomial::RealRoots QuadraticPolynomial::realRoots(){
	// Solve for real roots.
	double sgn_b = (b >= 0.0 ? 1.0 : -1.0);
	double disc = b*b - 4*a*c;
	if (disc < 0.0){
		throw NoRealRoots();
	}
	double q = -0.5*(b + sgn_b * sqrt(disc));
	return RealRoots(q/a,c/q);
}

QuadraticPolynomial::ComplexRoots QuadraticPolynomial::complexRoots()
{
	// Solve for complex roots.
	ComplexNumber sgn_b(b >= 0.0 ? 1.0 : -1.0, 0.0);
	ComplexNumber disc (b*b - 4*a*c, 0.0);
	ComplexNumber halfB(-0.5*b,0); 
	ComplexNumber q;
	q = halfB + sgn_b * disc.CalculatePower(-0.5);
	return ComplexRoots(q,q+disc); // Dummy expression for testing
	// return ComplexRoots(q/a,c/q);
}

double 	QuadraticPolynomial::evaluateAt(double x){
	// Evaluate ax^2 + bx + c at x
	return a*x*x + b*x + c;
}
QuadraticPolynomial::~QuadraticPolynomial(){}

// Exception
QuadraticPolynomial::NoRealRoots::NoRealRoots(){}

// Test driver
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	// x^2 - 5x + 6; real roots
	// x^2 -  x + 1; complex roots
	float a = 1.0;
	float b = -1.0;
	float c = 1.0;

	try{
		QuadraticPolynomial eqn(a,b,c);
		QuadraticPolynomial::RealRoots roots = eqn.realRoots();
		cout << "Real roots are: " << roots.minRoot() 
			 << ", " << roots.maxRoot() << endl;
	}
	catch (QuadraticPolynomial::NoRealRoots){
		cout << "No real roots." << endl;
		QuadraticPolynomial eqn(a,b,c);
		QuadraticPolynomial::ComplexRoots roots = eqn.complexRoots();
		cout << "Complex roots are: " << roots.Root1() 
			 << ", " << roots.Root2() << endl;
	}

	return 0;
}