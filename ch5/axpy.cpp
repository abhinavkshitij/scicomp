// Example from pg 146
#include "vector.h"
#include "axpy.h"

template<class EltType>
extern void axpy(EltType alpha, Vector<EltType>& x, Vector<EltType>& y)
{
	if (alpha != 0.0){
		int n = x.numElts();
		for (int i = 0; i < n; ++i){
			y[i] += alpha * x[i];
		}
	}
}

