// Example from pg. 137
#include <iostream>
using namespace std;

int order(int& i1, int& i2, int& i3){
	// Rearrange arguments in ascending order. Return max value
	if (i1 > i2) {int temp = i1; i1 = i2; i2 = temp;}
	if (i2 > i3) {int temp = i2; i2 = i3; i3 = temp;}
	if (i1 > i2) {int temp = i1; i1 = i2; i2 = temp;}
	return i3;
}

int main(int argc, char const *argv[])
{
	int a = 1;
	int b = 2;
	int c = -8;
	cout << order(a,b,c) << endl;
	return 0;
}
