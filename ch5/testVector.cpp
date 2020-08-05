#include <iostream>
#include "vector.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
	Vector<double> a(4);
	a[1] = 1;
	std::cout << a[1] << std::endl;
 	return 0;
}