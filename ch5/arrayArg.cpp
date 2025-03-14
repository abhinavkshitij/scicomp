// Example from pg 139.
// Built-in arrays are passed by reference.
double runningSum(float* y){
	double sum = *y;
	for (int i = 1; i < 5; ++i){
		sum += *(y+i);
		*(y+i) = sum;
 	}
 	return sum;
}

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	float x[5] = {1., 2., 3., 4., 5.};
	float sum = runningSum(x);
	cout << sum << endl;
	
	return 0;
}