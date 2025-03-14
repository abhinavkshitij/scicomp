// Example from pg 29.
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	double a = 3.14159;
	double b = 1/a;
	double c = 10 * a;

	// Use FORTRAN compatibility output
	std::cout << setiosflags(ios::showpoint | ios::uppercase);

	// Write data in G15.8 format.
	std::cout << setw(15) << setprecision(8) << a;
	std::cout << setw(15) << setprecision(8) << b;

	// Write F10.3 format
	std::cout << setiosflags(ios::fixed);
	std::cout << setw(10) << setprecision(3) << c << endl;

	return 0;
}