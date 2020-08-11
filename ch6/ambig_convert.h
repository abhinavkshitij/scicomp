// Example from pg 162.

class ComplexDouble

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
	ComplexDouble cd = cf;
	return 0;
}