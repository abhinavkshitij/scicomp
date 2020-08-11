// Example from pg. 169
#include "Complex.cpp"

int main(int argc, char const *argv[])
{
	Complex a(1,1);
	Complex b(2,3);

	std::cout << a + b << std::endl;	
	std::cout << b - a << std::endl;
	std::cout << 3.0 + a << std::endl;	

	a *= b; 
	std::cout << a << std::endl;

	a.operator*=(b); // same as a *= b
	std::cout << a  << std::endl;

	Complex c = a + 2.0;

	a = b = c;  // multi-assign

	return 0;
}