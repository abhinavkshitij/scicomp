// Example from pg. 212
#include "Mesh.h"

// int Mesh::numNodes() const {return node_table.numElts();}
// int Mesh::numElements() const {return element_table.numElts();}


// Number Mesh::maxAngle(const Element& e) const {
// 	Number maxang = 0.0;
// 	int numNodes = e.numNodes();
// 	for (int i = 0; i < e.numNodes(); ++i){
// 	 	int ccwNodeNum = (i+1) % numNodes;
// 	 	int cwNodeNum = (i + numNodes - 1) % numNodes;
// 	 	Number angle = node_table[e[i]].angle(node_table[e[cwNodeNum]], 
// 	 									     node_table[e[ccwNodeNum]]);
// 	 	if (angle > maxang){
// 	 		maxang = angle;
// 	 	}
// 	 } 
// 	 return maxang;
// }



Number Element::maxAngle() const{
	Number maxang = 0.0;
	for (NodesOfElement nodes(*this); nodes.more(); nodes.advance()){
		Number angle = nodes.current().angle(nodes.cwNeighbor(), nodes.ccwNeighbor);
		if (angle > maxang){
			maxang = angle;
		}
	}
	return maxang;
}




Boolean Mesh::checkElementsAngles(Number angle_threshold) const{
	Boolean anglesOK = Boolean::True;
	for (ElementsOfMesh elts(*this); elts.more(); elts.advance()){
			if (elts.current().maxAngle() > angle_threshold){
				cout << "Element " << elts.current() << "has a large angle." << endl; 
			}
			anglesOK = Boolean::False;
		}
	}
	return anglesOK;
}


istream& operator>>(istream& instream, Mesh& m){
	// Set sizes of node and element tables
	int nNodes;
	int nElements;
	instream >> nNodes >> nElements;
	m.node_table.setSize(nNodes);
	m.element_table.setSize(nElements);

	// Read nodes
	cout << "Node count: " << nNodes << endl;
	for (int nodeNum = 0; nodeNum < nNodes; ++nodeNum){
		instream >> m.node_table[nodeNum]; // overloaded Point::operator >>
		cout << nodeNum << ": " << m.node_table[nodeNum] << ", ";
	}
	cout << endl << endl;

	// Read Elements
	cout << "Element count: " << nElements << endl;
	NodeReader reader(m,instream);
	for (int elementNum = 0; elementNum < nElements; ++elementNum){
		reader >> m.element_table[elementNum]; // overloaded Element::operator >>
	}
	return instream;
}


NodeReader::NodeReader(Mesh& m, istream& instream):
	mesh(m), in(instream){}

int NodeReader::getSize(){
	int size;
	in >> size;
	return size;
}

Node* NodeReader::getNode(){
	int nodeNum;
	in >> nodeNum;
	return &mesh.node_table[nodeNum];
}
