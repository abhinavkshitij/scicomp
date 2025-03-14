// Example from pg 195
#include "TraceLifetime.h"
#include <iostream>
using namespace std;

void f2(){
	cout << " -- f2 starts -- " << endl;
	TraceLifetime c("c");
	throw "Exception";
	cout << " -- f2 ends -- " << endl;
}

void f1(){
	cout << " -- f1 starts -- " << endl;
	TraceLifetime a("a");
	f2();
	TraceLifetime b("b");
	cout << " -- f1 ends -- " << endl;
}

int main(int argc, char const *argv[])
{
	cout << " -- main starts -- " << endl;
	try{
		f1();
	}
	catch(const char*){
		cout << " Exception caught." << endl;
	}

	cout << " -- main ends -- " << endl;
	return 0;
}

