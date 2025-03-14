// Example from pg 275.
class SimpleFloatArray
{
public:
	int num_elts; 					// Number of elements
	float* ptr_to_data; 			// Pointer to built-in array of elements
	void copy(const SimpleFloatArray& a); // Copy in elements of an array
public:
	SimpleFloatArray(int n);		// Create array of n elements	
	SimpleFloatArray();  			// Create array of 0 elements
	SimpleFloatArray(const SimpleFloatArray&);	// Copy array
	~SimpleFloatArray();			// Destroy array
	float& operator[](int i);		// Subscripting 
	int numElts();					// Number of elements
	SimpleFloatArray& operator=(const SimpleFloatArray&); // Array assignment
	SimpleFloatArray& operator=(float);	// Scalar assignment
	void setSize(int n); 			// Change size	
};

class CheckedFloatArray : public SimpleFloatArray {
public:
	CheckedFloatArray(int n);
	CheckedFloatArray();
	float& operator[](int i);
	CheckedFloatArray& operator=(float);

	class SubscriptRangeError{};
};

