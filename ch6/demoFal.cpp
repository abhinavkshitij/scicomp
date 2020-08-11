// Example from pg. 166
// g++-9 -o demoFal demoFal.cpp ../ch4/SimpleArray.cpp  ; ./demoFal
#include "../ch4/SimpleArray.h"
#include "../ch4/SimpleArray.cpp" // for template initialization
#include "demoFal.h"

Interval::Interval(){}

Interval::Interval(double lo, double hi)
	:the_lo(lo), the_hi(hi){
	}

double Interval::lo() const 
	{
		return the_lo;
	}

double Interval::hi() const 
	{
		return the_hi;
	}	


SetOfIntervals::SetOfIntervals(int max_number_of_intervals)
{
	num_intervals = max_number_of_intervals;
	SimpleArray<Interval> intervals(num_intervals);
}


void SetOfIntervals::add(Interval i)
{
	// intervals = i;
}


Fallible<Interval> SetOfIntervals::intervalContaining(double val)
{
	for (int i = 0; i < num_intervals; ++i)
	{
		Interval& t = intervals[i];
		if (t.lo() <= val && val <= t.hi())		
		{
			return t;
		}
	}
	return Fallible<Interval> ();	// Invalid state
}

template<class T>
inline
Fallible<T>::operator T() const
{
	if (failed())
	{
		throw UsedInInvalidStateErr();
	}
	return instance;
}


// Main
#include <iostream>
using namespace std;

// From pg. 181.
// global function to print Interval object
ostream& operator<<(ostream& os, const Interval& i)
{
	return os << "[" << i.lo() << "," << i.hi() << "]";
}

// global function to input [lo,hi] format
istream& operator>>(istream& is, Interval&i)
{
	char lbracket = 0;
	char rbracket = 0;
	char comma = 0;
	double lo;
	double hi;
	
	is >> lbracket >> lo >> comma >> hi >> rbracket;
	if(lbracket!='[' || comma!=',' || rbracket != '[') is.clear(ios::badbit);
	else if (is) i = Interval(lo,hi); // read if it is in good state.

	return is;
}

int main(int argc, char const *argv[])
{
	SetOfIntervals s(5);
	s.add(Interval(-100,-50));
	s.add(Interval(-1,1));
	s.add(Interval(2,4));

	// Test line for cout for interval
	Interval small(-0.01, 0.02);
	cout << small << endl;

	// Segmentation fault upon running this part:
	// Interval interval_about_0 = s.intervalContaining(0);
	// Interval interval_about_5 = s.intervalContaining(5);

	// Not tried yet
	// if (s.intervalContaining(11.2).valid())
	// {
	// 	/* code */
	// }


	return 0;
}

