// Example from pg 81.
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	// Can use printf in C++
	printf("Bytes used in C char type = %lu\n", sizeof('x'));
	cout << "Bytes used in C++ char type = " << sizeof('x') << endl; 
	return EXIT_SUCCESS;
}