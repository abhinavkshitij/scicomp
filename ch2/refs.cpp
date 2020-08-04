// Example from pg. 62
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	// A reference variable creates an alias for an object
	int i = 3;
	int& ir = i;

	cout << ir << endl;
	ir = 4;
	cout << "Change object with reference variable ir" << endl;
	cout << ir << endl;

	// Put two stickers on the same address
	const float pi = 3.14159;
	const float& unit_circle_area = pi;
	cout << "area of a unit circle = " << unit_circle_area << endl;

	// Const reference to a non-const object
	float x;
	const float& x_ref = x;
	x = 5.0; // permitted
	x_ref = 4.0; // not permitted; x_ref is const
 	return 0;
}