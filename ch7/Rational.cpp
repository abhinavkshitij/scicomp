// Example from pg 194
#include "Rational.h"

Rational::Rational()
	:the_num(0), the_den(0){}

Rational::Rational(int num, int den)
	:the_num(num), the_den(den){}

std::ostream& operator<<(std::ostream& output, const Rational& r)
{
	std::cout << r.the_num << "/" << r.the_den << std::endl;
	return output;
}	


const Rational Rational::zero(0,1);
const Rational Rational::quarter(1,4);
const Rational Rational::half(1,2);	


