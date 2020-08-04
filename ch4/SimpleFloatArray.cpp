// Example from pg 107.
#include <iostream>
#include "SimpleFloatArray.h"

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


// // Test Driver 
// int main(int argc, char const *argv[])
// {
// 	SimpleFloatArray a(3);
// 	a = 4;
// 	std::cout << a[1] << std::endl; 
// 	return 0;
// }


