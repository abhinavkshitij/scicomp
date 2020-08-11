#include "ambig_convert3.h"

ComplexDouble ComplexInt::toComplexDouble() const {};

ComplexFloat::ComplexFloat(ComplexInt){}; 	

ComplexDouble::ComplexDouble(ComplexFloat){}; 

int main(int argc, char const *argv[])
{
	ComplexInt ci; // C++ supplies default constructor

	float a = arg(ci); 
	double b = arg(ci.toComplexDouble());   
	return 0;
}
