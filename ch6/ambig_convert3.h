// Example from pg 165
class ComplexFloat;  // forward declaration
class ComplexDouble; // forward declaration

class ComplexInt
{
public:
	ComplexDouble toComplexDouble() const;
};

class ComplexFloat
{
public:
	ComplexFloat(ComplexInt); 	// conversion with constructor
};

class ComplexDouble
{
public:
	ComplexDouble(ComplexFloat); // conversion with constructor
};

// arg function
extern float 	arg(ComplexFloat z){return 0;};
extern double 	arg(ComplexDouble z){return 0;};

