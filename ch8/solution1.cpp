// Example from pg. 212
#include "../ch4/SimpleArray.h"
#include "../ch6/Point.h"
#include "../ch6/Line.h"

#include <iostream>
#include <fstream>

typedef SimpleArray<int> Element;
extern Number maxAngle(const Element& e, const SimpleArray<Point>& nodeTable);

using namespace std;

int main(int argc, char const *argv[])
{
	// Read sizes and create tables
	int numNodes;
	int numElements;
	ifstream read_file("mesh.in");
	read_file >> numNodes >> numElements;

	SimpleArray<Point> nodeTable(numNodes);
	SimpleArray<Element> elementTable(numElements);

	// Read node data
	cout << "Node count: " << numNodes << endl;
	for (int nodeNum = 0; nodeNum < numNodes; nodeNum++){
		read_file >> nodeTable[nodeNum];
		cout << nodeNum << ": " << nodeTable[nodeNum] << ", ";
	}
	cout << endl << endl;

	

	// Read element data
	cout << "Element count: " << numElements << endl;
	for (int eltNum = 0; eltNum < numElements; ++eltNum){
		Element& e = elementTable[eltNum]; // e is an alias for element# eltNum
		int elementSize;
		read_file >> elementSize;
		e.setSize(elementSize);
		cout << "Element " << eltNum << ": ";
		for (int i = 0; i < elementSize; ++i){
		 	read_file >> e[i];
		 	cout << e[i] << " ";
		} 
		cout << endl;
	}



	return 0;
}


Number 
maxAngle(Element& e, SimpleArray<Point>& nodeTable){
	Number maxang = 0.0;
	int numNodes = e.numElts();
	for (int i = 0; i < numNodes; ++i)
	 {
	 	int ccwNodeNum = (i+1) % numNodes;
	 	int cwNodeNum = (i + numNodes - 1) % numNodes;
	 	Number angle = nodeTable[e[i]].angle(nodeTable[e[cwNodeNum]], 
	 									     nodeTable[e[ccwNodeNum]]);
	 	if (angle > maxang){
	 		maxang = angle;
	 	}
	 } 
	 return maxang;
}