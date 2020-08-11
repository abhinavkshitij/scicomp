// Example from pg. 166
// Issues with explicit initialization of template class
#pragma once
#include "../ch4/SimpleArray.h"
#include "SciEng/Boolean.h"

class Interval
{
private:
	double the_lo;
	double the_hi;	
public:
	Interval();
	Interval(double lo, double hi);
	double lo() const;
	double hi() const;	
};


template<class T>
class Fallible
{
private:
	Boolean is_valid;
	T instance;
public:
	Fallible(const T& t): is_valid(Boolean::True), instance(t)	{} // Valid
	Fallible()			: is_valid(Boolean::False)				{} // Invalid
	Boolean failed() const 	{return !is_valid;}		// True if invalid
	Boolean valid()  const 	{return is_valid;}		// True if valid 
	void invalidate()		{is_valid = Boolean::False;} // Make invalid
	operator T() 	 const;
	T elseDefaultTo(const T& default_value) const; // Value if valid, else default_value

	class UsedInInvalidStateErr
		{
		public:
			// UsedInInvalidStateErr();
		};	
};

class SetOfIntervals
{
private:
	int num_intervals;
	SimpleArray<Interval> intervals;
public:
	SetOfIntervals(int max_number_of_intervals);
	void add(Interval);
	Fallible<Interval> intervalContaining(double val);
};



