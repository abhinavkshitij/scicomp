// Example from pg 106
#include <iostream>
#include <fstream>
#include "SimpleFloatArray.h"

using namespace std;

void linefit(){
	// Create arrays with the desired numer of elements
	int n;
	ifstream read_file("../ch2/linefit.in");
	read_file >> n; // number of points

	SimpleFloatArray x(n); // float* const x = new float[n];
	SimpleFloatArray y(n); // float* const y = new float[n];

	// Read data points
	for (int i = 0; i < n; ++i){
		read_file >> x[i] >> y[i];
	}

	// Accumulate sums Sx and Sy in double precision
	double sx = 0.0;
	double sy = 0.0;
	for (int i = 0; i < n; ++i){
		sx += x[i];
		sy += y[i];
	}

	// Compute coeff
	double sx_over_n = sx / n;
	double stt = 0.0;
	double b = 0.0;

	for (int i = 0; i < n; ++i){
		double ti = x[i] - sx_over_n;
		stt += ti * ti;
		b += ti * y[i];
	}
	b /= stt;
	double a = (sy - sx * b)/n;

	// delete &x;
	// delete &y;

	ofstream out_file("../ch2/linefit.out");
	out_file << "a = " << a << ", b = " << b << endl;
 }

// Test driver:
int main(int argc, char const *argv[])
{
	linefit();
	return 0;
}