// Example from pg. 169
#include "List.h"
// #include "List.cpp"
// #include <iostream>
#include <cfloat>
using namespace std;

int main(int argc, char const *argv[])
{
	// Read list of values and find minimum
	List<float> list;
	float val;
	float minval = FLT_MAX;

	while(cin >> val){
		if (val < minval){
			minval = val;
		}
		list.add(val);
	}

	for (ListIterator<float> i(list); i.more(); i.advance())
	{
		cout << i.current() - minval << endl;
	}
	return 0;
}