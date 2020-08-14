// Example from pg. 200

#include <iostream>
using namespace std;

class Dangle
{
private:
	int* p;	
public:
	Dangle()	{p = new int(0);}
	~Dangle() 	{delete p;}
	int* pointer() {return p;}
};

class NoDangle
{
private:
	int* p;	
public:
	NoDangle()	{p = new int(0);}
	~NoDangle() {delete p;}
	NoDangle(const NoDangle& x) : p(new int(*x.p)){}
	NoDangle& operator=(const NoDangle& rhs){
		if (rhs.p!=p){
			delete p;
			p = new int(*rhs.p);
		}
		return *this;
	}
	int* pointer() {return p;}
};

void f(){
	Dangle a;
	Dangle b = a;
}

// From pg 202
void dangle(int j){ // WARNING: Incorrect code
	int* p;
	if (j < 100){
		// Dangling reference created when this block terminates
		int iarray[100];
		p = iarray;		// p points at iarray that won't exist past this block 
	}
	else p = new int[j];

	for (int i = 0; i < j; ++i){
		p[i] = i;
	}
	cout << *p << endl; 
}

// From pg 202: deletes function arg
void f(int* x){
	delete[] x;
}

void dynamic_dangle(int size){
	int* iarray = new int[size];
	f(iarray);
	for (int i = 0; i < size; ++i){
		cout << iarray[i] << endl;
	}
}
	
int main(int argc, char const *argv[])
{
	// f();
	// Change to NoDangle to fix the problem.
	NoDangle a;
	NoDangle b = a; // copy constructor will copy p to b, won't call new int(0)
	cout << "Copy a to b " << endl;
	cout << "a at " << a.pointer() << endl;
	cout << "b at " <<b.pointer() << endl;

	dangle(2);
	dynamic_dangle(2);

	return 0;
}