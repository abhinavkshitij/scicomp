#include <iostream>

class Rational
{
private:
	int the_num;
	int the_den;
public:
	Rational();
	Rational(int num, int den);
	
	static const Rational zero;
	static const Rational quarter;
	static const Rational half;	

	friend std::ostream& operator<<(std::ostream& output, const Rational& r);

	int Num() const {return the_num;}
	int Den() const {return the_den;}
};

