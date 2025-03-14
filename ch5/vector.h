#pragma once
template<class T> 
class Vector
{
private:
	int num_elts; 						// Number of elements
	T* ptr_to_data; 					// Pointer to built-in array of elements
	void copy(const Vector<T>& a); // Copy in elements of a
public:
	Vector(int n);					// Create array of n elements	
	Vector();  					// Create array of 0 elements
	Vector(const Vector<T>&);	// Copy array
	~Vector();						// Destroy array
	T& operator[](int i);				// Subscripting 
	int numElts();						// Number of elements
	Vector<T>& operator=(const Vector<T>&); // Array assignment
	Vector<T>& operator=(T);		// Scalar assignment
	void setSize(int n); 				// Change size	
};

