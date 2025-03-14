#include "vector.h"
template<class T> 
Vector<T>::Vector(int n)
{
	num_elts = n;
	ptr_to_data = new T[n];
}


template<class T> 
Vector<T>::Vector()
{
	num_elts = 0;
	ptr_to_data = 0;
}


template<class T> 
Vector<T>::Vector(const Vector<T>& a)
{
	num_elts = a.num_elts;
	ptr_to_data = new T[num_elts];
	copy(a); 
}


template<class T> 
void Vector<T>::copy(const Vector<T>& a)
{
	T* p = ptr_to_data + num_elts;
	T* q = a.ptr_to_data + num_elts;
	while (p > ptr_to_data) *--p = *--q;
}


template<class T> 
Vector<T>::~Vector()
{
	delete[] ptr_to_data;
}
	

template<class T> 
T& Vector<T>::operator[](int i)
{
	return ptr_to_data[i];
}


template<class T> 
int Vector<T>::numElts() 
{
	return num_elts;
}


template<class T> 
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
{
	if (ptr_to_data != rhs.ptr_to_data)
	{
		setSize(rhs.num_elts);
		copy(rhs);
	}
	return *this;
}


template<class T> 
Vector<T>& Vector<T>::operator=(T rhs)
{
	T* p = ptr_to_data + num_elts;
	while(p > ptr_to_data)
	{
		*--p = rhs;
	} 
	return *this;
}


template<class T> 
void Vector<T>::setSize(int n)
{
	if (n!=num_elts)
	{
		delete[] ptr_to_data;		// Delete old elements
		num_elts = n;				// set new count
		ptr_to_data = new T[n];		// and allocate new elements
	}
}

// #include <iostream>
// int main(int argc, char const *argv[])
// {
// 	Vector<double> a(4);
// 	a[1] = 1;
// 	std::cout << a[1] << std::endl;
//  	return 0;
// }

