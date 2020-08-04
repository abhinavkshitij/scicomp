/* Example from pg. 69
 * Array reference is passed by copying the
 * address of the first element to the pointer
 * in the formal argument list. 
 */
void f(int i, float x, float* a){
	i = 100;
	x = 101.0;
	a[0] = 0.0;
}

// Using reference formal arguments
void swap(int& i1, int& i2){
	// Pass references to change actual arguments
	int temp = i1;
	i1 = i2;
	i2 = temp;
}

// Driver
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int j = 1;
	int k = 2;
	float y[] = {3.0, 4.0, 5.0};

	// Set y[0] to zero
 	f(j,k,y);
	cout << y[0] << endl;

	// Swap c and d
	int c = 3;
	int d = 4;
	swap(c,d);
	cout << c << " " << d << endl;

	return 0;
}