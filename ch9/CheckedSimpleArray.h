class SubscriptRangeError
{
private:
	int subscript;
public:
	SubscriptRangeError(int i);
	int badSubscript();
};

class ArraySizeError
{
private:
	int size;
public:
	ArraySizeError(int n);
	int badSize();
};

template<class T> 
class CheckedSimpleArray
{
private:
	int num_elts; 						// Number of elements
	T* ptr_to_data; 					// Pointer to built-in array of elements
	void copy(const CheckedSimpleArray<T>& a); // Copy in elements of a
public:
	CheckedSimpleArray(int n);			// Create array of n elements	
	CheckedSimpleArray();  				// Create array of 0 elements
	CheckedSimpleArray(const CheckedSimpleArray<T>&);	// Copy array
	~CheckedSimpleArray();				// Destroy array
	T& operator[](int i);				// Subscripting 
	int numElts();						// Number of elements
	CheckedSimpleArray<T>& operator=(const CheckedSimpleArray<T>&); // Array assignment
	CheckedSimpleArray<T>& operator=(T);// Scalar assignment
	void setSize(int n); 				// Change size	
};

