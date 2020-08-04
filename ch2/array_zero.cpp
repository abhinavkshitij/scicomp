// Example from pg 45.

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	float x[10];
	cout << "Uninitialized Array: " << endl;
	for (int i = 0; i < 10; ++i){
		cout << x[i] << " ";
	}
	cout << endl;

	// Set array elements to zero
	cout << "Array set to zero using pointers: " << endl;
	float* p = &x[10];
	while(p!=x){ 
		*--p = 0.0;
		cout << *p << " ";
	}
	return 0;
}