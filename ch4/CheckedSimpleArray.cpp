#include <iostream>
#include "CheckedSimpleArray.h"

SubscriptRangeError::SubscriptRangeError(int n)
{
	subscript = n;
}

int SubscriptRangeError::badSubscript()
{
	return subscript;
}


ArraySizeError::ArraySizeError(int n)
{
	size = n;
}

int ArraySizeError::badSize()
{
	return size;
}

template<class T> 
CheckedSimpleArray<T>::CheckedSimpleArray(int n)
{
	if (n < 0) throw ArraySizeError(n);
	num_elts = n;
	ptr_to_data = new T[n];
}


template<class T> 
CheckedSimpleArray<T>::CheckedSimpleArray()
{
	num_elts = 0;
	ptr_to_data = 0;
}


template<class T> 
CheckedSimpleArray<T>::CheckedSimpleArray(const CheckedSimpleArray<T>& a)
{
	num_elts = a.num_elts;
	ptr_to_data = new T[num_elts];
	copy(a); 
}


template<class T> 
void CheckedSimpleArray<T>::copy(const CheckedSimpleArray<T>& a)
{
	T* p = ptr_to_data + num_elts;
	T* q = a.ptr_to_data + num_elts;
	while (p > ptr_to_data) *--p = *--q;
}


template<class T> 
CheckedSimpleArray<T>::~CheckedSimpleArray()
{
	delete[] ptr_to_data;
}
	

template<class T> 
T& CheckedSimpleArray<T>::operator[](int i)
{
	if (i < 0 || i >= num_elts) throw SubscriptRangeError(i);
	return ptr_to_data[i];
}


template<class T> 
int CheckedSimpleArray<T>::numElts()
{
	return num_elts;
}


template<class T> 
CheckedSimpleArray<T>& CheckedSimpleArray<T>::operator=(const CheckedSimpleArray<T>& rhs)
{
	if (ptr_to_data != rhs.ptr_to_data)
	{
		setSize(rhs.num_elts);
		copy(rhs);
	}
	return *this;
}


template<class T> 
CheckedSimpleArray<T>& CheckedSimpleArray<T>::operator=(T rhs)
{
	T* p = ptr_to_data + num_elts;
	while(p > ptr_to_data)
	{
		*--p = rhs;
	} 
	return *this;
}


template<class T> 
void CheckedSimpleArray<T>::setSize(int n)
{
	if (n!=num_elts)
	{
		if (n < 0) throw ArraySizeError(n);
		delete[] ptr_to_data;		// Delete old elements
		num_elts = n;				// set new count
		ptr_to_data = new T[n];		// and allocate new elements
	}
}


// Test driver
int main(int argc, char const *argv[])
{
	try{
		CheckedSimpleArray<float> a1(-3);
		CheckedSimpleArray<int> b1(4);
		std::cout << b1[-1] << std::endl;;
	}
	catch (SubscriptRangeError e){
		std::cerr << "SubscriptRangeError: bad subscript = " << e.badSubscript() << std::endl;
	}
	catch (ArraySizeError e){
		std::cerr << "ArraySizeError: bad size = " << e.badSize() << std::endl;
	}
	return 0;
}

