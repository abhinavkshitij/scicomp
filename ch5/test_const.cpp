// Tests the effectiveness of the const keyword in 
// preventing input-modification of specific array elements

#include <iostream>
using namespace std;

template<class T> 
class SimpleArray1d
{
private:
	int num_elts; 				// Number of elements
	T* ptr_to_data; 			// Pointer to built-in array of elements
public:
	SimpleArray1d(int n);		// Create array of n elements	
	SimpleArray1d();  			// Create array of 0 elements
	~SimpleArray1d();			// Destroy array
	T& operator[](int i) const;	// Subscripting 
	int numElts() const;		// Number of elements
	SimpleArray1d<T>& operator=(T);	// Scalar assignment
};

template class SimpleArray1d<float> ;

template<class T> 
SimpleArray1d<T>::SimpleArray1d(int n){
	num_elts = n;
	ptr_to_data = new T[n];
}

template<class T> 
SimpleArray1d<T>::SimpleArray1d(){
	num_elts = 0;
	ptr_to_data = 0;
}

template<class T> 
SimpleArray1d<T>::~SimpleArray1d(){
	delete[] ptr_to_data;
}
	
template<class T> 
T& SimpleArray1d<T>::operator[](int i) const{
	return ptr_to_data[i];
}

template<class T> 
int SimpleArray1d<T>::numElts() const{
	return num_elts;
}

template<class T> 
SimpleArray1d<T>& SimpleArray1d<T>::operator=(T rhs)
{
	T* p = ptr_to_data + num_elts;
	while(p > ptr_to_data)
	{
		*--p = rhs;
	} 
	return *this;
}


// Client code
// This does not work
// The const keyword does NOT prevent assigning a[0] = 1
void f(const SimpleArray1d<float>& a){
	a[0] = 1;
	cout << a.numElts() << "  " << a[0] << endl;
}

// This works
// Add 'const' before float* a to prevent input-modification
void g(float a){
	a[0] = 7; a[1] = 3; a[2] = 1;
}


// Test driver
int main(int argc, char const *argv[])
{
	SimpleArray1d<float> a(3);
	float b[3] = {7, 3, 2};

	f(a);
	cout << "a[0] = " << a[0] << endl;

	g(a[0]);
	cout << "a[0] = " << a[0] << endl;

	return 0;
}


