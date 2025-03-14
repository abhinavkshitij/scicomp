// Example from pg 162.
class ComplexDouble; // forward declaration

class ComplexFloat
{
public:
	ComplexFloat();
	operator ComplexDouble() const;
};

class ComplexDouble
{
public:
	ComplexDouble(const ComplexFloat&);	
};

int main(int argc, char const *argv[])
{
	ComplexFloat cf;
	ComplexDouble cd = cf; // WRONG: ambiguous conversion
	return 0;
}