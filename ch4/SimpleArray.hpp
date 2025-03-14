#include "../ch8/Mesh.h"
#include "SimpleArray.cpp"

template class SimpleArray<int>;
template class SimpleArray<Point>;
template class SimpleArray<SimpleArray<int> >;
template class SimpleArray<Node*>;
// template class SimpleArray<Element>;
