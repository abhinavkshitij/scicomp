// Example from pg 190
#include "TraceLifetime.h"
#include <iostream>
using namespace std;

static TraceLifetime s1("s1"); 	// File scope, internal linkage static object

void fnc(int j){
	cout << "--- starting fnc(" << j << ") -- " << endl;
	static TraceLifetime s2("s2"); // Local scope: created on first call
	
	if (j == 2)	{
		static TraceLifetime s4("s4");	// Only created when j = 2.
	}

	for (int i = 1; i <= 2; ++i){
		cout << "-- loop i=" << i << " -- " << endl;
		static TraceLifetime s3("s3"); // Local scope: created once, when i=1
	}

	cout << "-- returning from fnc(" << j << ") -- " << endl;
}

int main(int argc, char const *argv[]){
	cout << "-- main starts -- " << endl;
	fnc(1);
	fnc(2);
	cout << "-- main ends -- " << endl;	
	return 0;
}

static TraceLifetime s5("s5"); 	// File scope, internal linkage static object
