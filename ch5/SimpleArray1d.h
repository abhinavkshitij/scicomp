template<class T> 
class SimpleArray1d
{
private:
	int num_elts; 						// Number of elements
	T* ptr_to_data; 					// Pointer to built-in array of elements
	void copy(const SimpleArray1d<T>& a); // Copy in elements of a
public:
	SimpleArray1d(int n);					// Create array of n elements	
	SimpleArray1d();  					// Create array of 0 elements
	SimpleArray1d(const SimpleArray1d<T>&);	// Copy array
	~SimpleArray1d();						// Destroy array
	T& operator[](int i);				// Subscripting 
	int numElts();						// Number of elements
	SimpleArray1d<T>& operator=(const SimpleArray1d<T>&); // Array assignment
	SimpleArray1d<T>& operator=(T);		// Scalar assignment
	void setSize(int n); 				// Change size	
};

