// Example from pg 194
#include "Rational.h"
#include "RationalComplex.h"

const RationalComplex RationalComplex::realHalf(Rational::half, Rational::zero); 
const RationalComplex RationalComplex::imagHalf(Rational::zero, Rational::half);


int main(int argc, char const *argv[])
{
	return 0;
}