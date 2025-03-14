// Example from pg. 212
#include "Element.h"

// int Element::operator[] (int i) const {return node_numbers[i];}
// int Element::numNodes() 		const {return node_numbers.numElts();}

// istream& operator>>(istream& instream, Element& e){
// 	int n;
// 	instream >> n;
// 	e.node_numbers.setSize(n);
// 	for (int i = 0; i < n; ++i){
// 		instream >> e.node_numbers[i];
// 	}
// 	return instream;
// }



// Number Element::maxAngle() const{
// 	Number maxang = 0.0;
// 	for (NodesOfElement nodes(*this); nodes.more(); nodes.advance()){
// 		Number angle = nodes.current().angle(nodes.cwNeighbor(), nodes.ccwNeighbor);
// 		if (angle > maxang){
// 			maxang = angle;
// 		}
// 	}
// 	return maxang;
// }


