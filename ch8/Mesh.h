// Example from pg. 212
#pragma once
// #include "../ch4/SimpleArray.h"
#include "../ch4/SimpleArray.cpp"
#include "../ch6/Point.h"
#include "../ch6/Line.h"
#include "../ch6/SciEng/Boolean.h"
// #include "Element.h"

typedef Point Node;

// typedef Point Node;

extern class NodeReader;

class Element
{
private:
	SimpleArray<Node*> node_ptrs;	
		// SimpleArray<int> node_numbers;
public:
	friend class NodesOfElement; 		// Iterator over nodes of an element

	friend void operator>>(NodeReader& reader, Element& e);
	friend ostream& operator<<(ostream& os, const Element& e);

	Number maxAngle() const;
	// int operator[](int i) const;
	// int numNodes() const;
	// friend istream& operator>>(istream&, Element&); 	
};


class ElementsOfMesh
{
private:
	const SimpleArray<Element> &element_table;
	int cur;	
public:
	ElementsOfMesh(const Mesh& m):
		element_table(m.element_table), cur(m.element_table.numElts()-1){}
	Boolean more() const 			{return cur >= 0;			}
	void advance()					{--cur;						}
	const Element& current() const 	{return element_table[cur];	}
};

class NodesOfElement
{
private:
	const SimpleArray<Node*> &node_ptrs;
	int cur; 	
public:
	NodesOfElement(const Element& e):
		node_ptrs(e.node_ptrs), cur(e.node_ptrs.numElts()-1){}

	// Iteration
	Boolean more() const 			{return cur >= 0;			}
	void advance()					{--cur;						}
	const Node& current() const 	{return *node_ptrs[cur];	}

	// Neighbors of current iterate
	Node& ccwNeighbor() const {return *node_ptrs[(cur+1)%node_ptrs.numElts()];}
	Node& cwNeighbor() const {
		int numNodes = node_ptrs.numElts();
		return *node_ptrs[(cur + numNodes - 1)%numNodes];
	}	
};



void operator>>(NodeReader& reader, Element& e){
	int nNodesInElement = reader.getSize();
	e.node_ptrs.setSize(nNodesInElement);
	for (int i = 0; i < nNodesInElement; ++i){
		e.node_ptrs[i] = reader.getNode();
	}
// }


class Mesh
{
private:
	SimpleArray<Node> 		node_table;
	SimpleArray<Element> 	element_table;
public:
	friend class ElementsOfMesh;		// Iterator over elements of a mesh
	friend class NodesOfMesh;			// Iterator over nodes of a mesh
	friend istream& operator>>(istream&, Mesh&);
	friend class NodeReader;
	// int numNodes() const;
	// int numElements() const;
	// Number maxAngle(const Element& e) const;
	Boolean checkElementsAngles(Number angle_threshold) const;
};

class NodeReader
{
private:
	Mesh& mesh;
	istream& in;	
public:
	NodeReader(Mesh& m, istream& instream);
	int getSize();
	Node* getNode();
};
