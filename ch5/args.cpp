// Example from pg. 138
#include <iostream>
#include "SimpleArray1d.hpp" // class template instantiation

using namespace std;

extern int index_of_min(SimpleArray1d<float>& a);
extern float& min_elt(SimpleArray1d<float>& a);

int index_of_min(SimpleArray1d<float>& a){
	float min_val = a[0];
	int min_idx = 0;
	for (int i = 0; i < a.numElts(); ++i){
		if (a[i] < min_val){
			min_idx = i;
			min_val = a[i];
		}
	}
	return min_idx;
}


float& min_elt(SimpleArray1d<float>& a){
	return a[index_of_min(a)];
}

int main(int argc, char const *argv[])
{
	SimpleArray1d<float> a(3);
	a[0] = 1; a[1] = 7; a[2] = 4;

	int min;
	float min_val;
	min_elt(a) = 0;

	min = index_of_min(a);
	cout << "min value =  " <<  a[index_of_min(a)]
		 << " at element = " << index_of_min(a) << endl;

	return 0;
}