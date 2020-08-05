#include <iostream>
#include <complex>
#include "vector.cpp"
#include "axpy.cpp"

// extern void axpy(float alpha, const Vector<float>& x, Vector<float>& y);
// extern void axpy(double alpha, Vector<double>& x, Vector<double>& y);

using namespace std;

int main(int argc, char const *argv[])
{

	Vector<int> ai(2);
	Vector<int> bi(2);
	Vector<double> a(2);
	Vector<double> b(2);
	Vector<complex<double> > ac(2);
	Vector<complex<double> > bc(2);

	// Init: a,b = [1 2]
	ai[0] = 1; ai[1] = 2; bi = ai;
	a[0] = 1.0; a[1] = 2.0; b = a;

	ac[0] = complex<double> (1.0,2.0); 
	ac[1] = complex<double> (2.0,3.0);
	bc = ac;

	// _AXPY: b = 10a + b
	axpy(10, ai,bi);  
	axpy(10.0, a,b); 
	axpy(complex<double> (10,0), ac, bc); 
	
	cout << bi[0] << endl;
	cout << b[0] << endl;
	cout << bc[0] << endl;

 	return 0;
}
