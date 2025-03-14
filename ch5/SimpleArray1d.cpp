#include "SimpleArray1d.h"

template<class T> 
SimpleArray1d<T>::SimpleArray1d(int n)
{
	num_elts = n;
	ptr_to_data = new T[n];
}


template<class T> 
SimpleArray1d<T>::SimpleArray1d()
{
	num_elts = 0;
	ptr_to_data = 0;
}


template<class T> 
SimpleArray1d<T>::SimpleArray1d(const SimpleArray1d<T>& a)
{
	num_elts = a.num_elts;
	ptr_to_data = new T[num_elts];
	copy(a); 
}


template<class T> 
void SimpleArray1d<T>::copy(const SimpleArray1d<T>& a)
{
	T* p = ptr_to_data + num_elts;
	T* q = a.ptr_to_data + num_elts;
	while (p > ptr_to_data) *--p = *--q;
}


template<class T> 
SimpleArray1d<T>::~SimpleArray1d()
{
	delete[] ptr_to_data;
}
	

template<class T> 
T& SimpleArray1d<T>::operator[](int i) const
{
	return ptr_to_data[i];
}


template<class T> 
int SimpleArray1d<T>::numElts() const
{
	return num_elts;
}



template<class T> 
SimpleArray1d<T>& SimpleArray1d<T>::operator=(const SimpleArray1d<T>& rhs)
{
	if (ptr_to_data != rhs.ptr_to_data)
	{
		setSize(rhs.num_elts);
		copy(rhs);
	}
	return *this;
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


template<class T> 
void SimpleArray1d<T>::setSize(int n)
{
	if (n!=num_elts)
	{
		delete[] ptr_to_data;		// Delete old elements
		num_elts = n;				// set new count
		ptr_to_data = new T[n];		// and allocate new elements
	}
}



// Test driver
// #include <iostream>
// int main(int argc, char const *argv[])
// {
// 	SimpleArray1d<double> a(4);
// 	a[1] = 1;
// 	std::cout << a[1] << std::endl;
//  	return 0;
// }



