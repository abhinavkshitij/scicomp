// Example from pg. 160
class Boolean
{
private:
	char v;	
public:
	// Constants
	enum constants {False = 0, True = 1};

	Boolean() {}					// Construct uninitialized
	Boolean(int i): v(i != 0) {}	// Construct, initialized to (i!=0)
	Boolean(float f): v(f != 0) {}	// Construct, initialized to (f!=0)
	Boolean(double d): v(d != 0) {}	// Construct, initialized to (d!=0)
	Boolean(void* p): v(p != 0) {}	// Construct, initialized to (p!=0)

	/* Conversion function (§6.4.2) - Boolean to int
	 * Serves as an alternative to convert through a constructor
	 * Use conversion function or a constructor but not both
	 */
	operator int() const {return v;} // To allow "if(boolean-value)"
	// is same as int(const Boolean&) constructor

	// Negation
	Boolean operator!() const {return !v;}	
};