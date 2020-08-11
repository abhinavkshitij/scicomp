// Exmaple from pg 164
class Array
{
public:
	Array(int n){};						// Single-argument constructor
	Array(const Array&){};				// Copy array
	Array& operator=(const Array&){return *this;};	// Assign array	
	Array& operator=(const int){return *this;};
	operator int() const {return 0;};
};

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	Array a(5);
	a = 5; // ERROR: int 5 creates an Array object and assigns to Array a.
	cout << a << endl;
	return 0;
}