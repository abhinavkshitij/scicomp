// Example from pg. 179
// Split this file into .h and .cpp and include both into
// demoList.cpp
#include "SciEng/Boolean.h"

template<class T> class ListIterator; // Forward declaration

template<class T>
class List
{
private:
	class Node
	{
	private:
		// link, datum declared as public members
	public:
		Node(T x): link(0), datum(x){}
		Node* link;
		T datum;
	};	

	Node* first;
	Node* last;

public:
	List():first(0), last(0){}

	void add(T x){
		if (first == 0) first = last = new Node(x);
		else last = last->link = new Node(x);
	}

	void remove(T x);

	friend class ListIterator<T>;
	
};


template<class T>
class ListIterator
{
private:
	List<T>::Node* cur;
public:
	ListIterator(const List<T>& list) 
		: cur(list.first) {}

	Boolean more() const{
		return cur != 0;
	}

	T current() const{
		return cur->datum;
	}	

	void advance(){
		cur = cur->link;
	}	
};

// friend class List::ListIterator<T>;