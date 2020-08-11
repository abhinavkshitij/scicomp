// Example from pg 163
class ComplexFloat{};  // forward declaration
class ComplexDouble{}; // forward declaration

class ComplexInt
{
public:
	ComplexInt(){};
};

class ComplexFloat
{
public:
	ComplexFloat(ComplexInt){}; 	// conversion with constructor
};

class ComplexDouble
{
public:
	ComplexDouble(ComplexInt){}; 	// conversion with constructor	
	ComplexDouble(ComplexFloat){}; 	// conversion with constructor
};

// arg function
extern float 	arg(ComplexFloat z){return 0;};
extern double 	arg(ComplexDouble z){return 0;};
// Fixed by introducing a function that disabmiguates the call
inline float 	arg(ComplexInt z) {return arg(ComplexFloat(z));}

int main(int argc, char const *argv[])
{
	ComplexInt ci; // C++ supplies default constructor

	// WRONG: call matches arg(ComplexFloat) and arg(ComplexDouble)
	double a = arg(ci); // Comment out LINE 28 to see the effect

	// Fixed by explicitly disambugating function call
	double b = arg(ComplexDouble(ci));   
	return 0;
}