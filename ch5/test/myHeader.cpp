#include "myHeader.h"

template<class T>
abc<T>::abc(T i) : val(i){}

template<class T>
T abc<T>::show() {return val;}

template class abc<int>;
