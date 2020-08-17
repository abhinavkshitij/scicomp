#pragma once
#include "../ch6/Point.h"
template<class T> 
class SimpleArray
{
private:
	int num_elts; 						// Number of elements
	T* ptr_to_data; 					// Pointer to built-in array of elements
	void copy(const SimpleArray<T>& a); // Copy in elements of a
public:
	SimpleArray(int n);					// Create array of n elements	
	SimpleArray();  					// Create array of 0 elements
	SimpleArray(const SimpleArray<T>&);	// Copy array
	~SimpleArray();						// Destroy array
	T& operator[](int i);				// Subscripting 
	int numElts();						// Number of elements
	SimpleArray<T>& operator=(const SimpleArray<T>&); // Array assignment
	SimpleArray<T>& operator=(T);		// Scalar assignment
	void setSize(int n); 				// Change size	

};
