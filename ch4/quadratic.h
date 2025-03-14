// Example from pg 122.
// Still working on integrating the ComplexNumber class -- line 48 in *.cpp file 
#include "../../ScientificComputing/ComplexNo_operatorOverloading.hpp"
// Add complex division and scalar multiplcation in the header file abpve.

class QuadraticPolynomial
{
private:
	// Polynomial coefficients
	double a;
	double b;
	double c;	
public:
	QuadraticPolynomial(double a, double b, double c);

	class RealRoots
	{
	private:
		double min_root;
		double max_root;	
	public:
		RealRoots(double x1, double x2);
		double minRoot();
		double maxRoot();
		~RealRoots();
	};

	class ComplexRoots
	{
	private:
		ComplexNumber root_1;
		ComplexNumber root_2;	
	public:
		ComplexRoots(ComplexNumber z1, ComplexNumber z2);
		ComplexNumber Root1();
		ComplexNumber Root2();
		~ComplexRoots();
	};

	RealRoots  		realRoots(); 			// Solve for real roots
	ComplexRoots 	complexRoots();			// Solve for complex roots
	double 			evaluateAt(double x);	// Evaluate at x
	~QuadraticPolynomial();

	// Exception: Real roots requested but both roots are complex
	class NoRealRoots
	{
	public:
		NoRealRoots();
	};	
};