// Example from pg 45.

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	float x[10]= {4,5,6,7,2,3,4,5,1,8};
	float* left = &x[0];
	float* right = &x[9];
	cout << "Array: " << endl;
	for (int i = 0; i < 10; ++i){
		cout << x[i] << " ";
	}
	cout << endl;
	cout << "Reversing array with pointers:" << endl;

	// Reverse array
	while(left < right){
		float temp = *left;
		*left++ = *right;
		*right-- = temp;
	}
	for (int i = 0; i < 10; ++i){
		cout << *(x+i) << " "; // same as x[i]
	}
	cout << endl;
	return 0;
}