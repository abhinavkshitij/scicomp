// Example from pg 194
#include "TraceLifetime.h"
#include <iostream>
using namespace std;


int main(int argc, char const *argv[]){
	cout << "-- main starts -- " << endl;
	TraceLifetime a1("a1"); 

	for (int i = 1; i <= 2; ++i){
		cout << "-- loop i=" << i << " -- " << endl;
		TraceLifetime a2("a2"); // Object created each loop iteration
		if (i == 2)	{
			TraceLifetime a3("a3");	// Only created if i = 2.
		}
	}
	cout << "-- loop is done -- " << endl;	
	TraceLifetime a4("a4");
	cout << "-- main ends -- " << endl;	
	return 0;
}


