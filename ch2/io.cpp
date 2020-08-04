// Example from pg 30.
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	// Create file in write mode
	ofstream out("pi.out");
	out << 3.14159 << endl;

	return 0;
}

