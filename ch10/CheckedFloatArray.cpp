// Example from pg 107.
#include <iostream>
#include "CheckedFloatArray.h"

SimpleFloatArray::SimpleFloatArray(int n){
	num_elts = n;
	ptr_to_data = new float[n];
}

SimpleFloatArray::SimpleFloatArray(){
	num_elts = 0;
	ptr_to_data = 0;
}

SimpleFloatArray::SimpleFloatArray(const SimpleFloatArray& a){
	num_elts = a.num_elts;
	ptr_to_data = new float[num_elts];
	copy(a); 
}

void SimpleFloatArray::copy(const SimpleFloatArray& a){
	float* p = ptr_to_data + num_elts;
	float* q = a.ptr_to_data + num_elts;
	while (p > ptr_to_data) *--p = *--q;
}

SimpleFloatArray::~SimpleFloatArray(){
	delete[] ptr_to_data;
}
	
int SimpleFloatArray::numElts(){
	return num_elts;
}

float& SimpleFloatArray::operator[](int i){
	std::cout << "using base class operator[]()" << std::endl;
	return ptr_to_data[i];
}

SimpleFloatArray& SimpleFloatArray::operator=(const SimpleFloatArray& rhs){
	if (ptr_to_data != rhs.ptr_to_data){
		setSize(rhs.num_elts);
		copy(rhs);
	}
	return *this;
}
 
SimpleFloatArray& SimpleFloatArray::operator=(float rhs){
	float* p = ptr_to_data + num_elts;
	while(p > ptr_to_data){
		*--p = rhs;
	} 
	return *this;
}

void SimpleFloatArray::setSize(int n){
	if (n!=num_elts){
		delete[] ptr_to_data;		// Delete old elements
		num_elts = n;				// set new count
		ptr_to_data = new float[n];		// and allocate new elements
	}
}


CheckedFloatArray::CheckedFloatArray(int n):SimpleFloatArray(n){}

CheckedFloatArray::CheckedFloatArray(){}

float& CheckedFloatArray::operator[](int i){
	std::cout << "using derived class operator[]()" << std::endl;
	if (i < 0 && i >= numElts()) 
		throw SubscriptRangeError();
	return SimpleFloatArray::operator[](i);
}

CheckedFloatArray& CheckedFloatArray::operator=(float rhs){
	float* p = ptr_to_data + num_elts;
	while(p > ptr_to_data){
		*--p = rhs;
	} 
	return *this;
}

// Base class cliient function
float average(SimpleFloatArray& a){
	double sum = 0.f;
	for (int i = 0; i < a.numElts(); i++)
		sum += a[i];
	return sum/a.numElts();
}

// Test Driver
int main(int argc, char const *argv[])
{
	CheckedFloatArray a(3), b(3);
	a = 4;
	a[2] = 11;
	b = a;
	
	std::cout << "Test for subscript error: " << a[-1] << std::endl;
	std::cout << "Average of b: " << average(b) << std::endl;
	return 0;
}


