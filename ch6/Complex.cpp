#ifndef COMPLEXNUMBERHEADERDEF
#define COMPLEXNUMBERHEADERDEF 

#include <iostream>
#include <cmath>

class Complex
{
private:
	double mRealPart; 
	double mImaginaryPart;	

public:
	// constructor
	Complex();
	Complex(double x);
	Complex(double x, double y);

	// class methods
	double CalculateModulus() const;
	double CalculateArgument() const;
	Complex CalculatePower(double n) const;

	// overloaded operator 
	Complex& operator=(const Complex& z);
	Complex operator-() const;
	// Complex operator+(const Complex& z) const;
	// Complex operator-(const Complex& z) const;
	Complex& operator+=(const Complex& rhs);
	Complex& operator*=(const Complex& rhs);
	friend std::ostream& operator<<(std::ostream& output, const Complex& z);
};


// Override default constructor
Complex::Complex() 
	: mRealPart(0.0), mImaginaryPart(0.0) {}

Complex::Complex(double x) 
	: mRealPart(x), mImaginaryPart(0.0) {}

Complex::Complex(double x, double y) 
	: mRealPart(x), mImaginaryPart(y) {}


// Method for computing the modulus of a complex number
double Complex::CalculateModulus() const
{
	return sqrt(mRealPart*mRealPart + mImaginaryPart*mImaginaryPart);
}


// Method for computing the argument of a complex number
double Complex::CalculateArgument() const
{
	return atan2(mImaginaryPart, mRealPart);
}

// Method for raising complex number to a power
// by first converting into polar form, followed
// by applying the de Moivre's theorm

Complex Complex::CalculatePower(double n) const
{
	double modulus = CalculateModulus();
	double argument = CalculateArgument();
	double mod_of_result = pow(modulus, n);
	double arg_of_result = argument * n;
	double real_part = mod_of_result*cos(arg_of_result);
	double imag_part = mod_of_result*sin(arg_of_result);
	Complex z(real_part, imag_part);
	return z;
} 

// Overloading the =(assignment)  operator
// By default, all method arguments are called by copy.
Complex& Complex::operator=(const Complex& z)
{
	mRealPart = z.mRealPart;
	mImaginaryPart = z.mImaginaryPart;
	return *this;
}

// Overloading the unary - operator
Complex Complex::operator-() const
{
	Complex w;
	w.mRealPart = -mRealPart;
	w.mImaginaryPart = -mImaginaryPart;
	return w;
}

// Add and assign
Complex& Complex::operator+=(const Complex& rhs)
{
	mRealPart += rhs.mRealPart;
	mImaginaryPart += rhs.mImaginaryPart;
	return *this;
}


// Multiply and assign
Complex& Complex::operator*=(const Complex& rhs)
{
	float original_real_part = mRealPart;
	mRealPart = mRealPart*rhs.mRealPart - mImaginaryPart*rhs.mImaginaryPart;
	mImaginaryPart = mImaginaryPart*rhs.mRealPart + original_real_part*rhs.mImaginaryPart;
	return *this;
}


// Global function (for commutative addition)
Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs);
	return result+= rhs;
}


// Global function (for commutative difference)
Complex operator-(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs);
	return result+= -rhs;
}

// Global function (for commutative multiplication)
Complex operator*(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs);
	return result*= rhs;
}

// Overloading the insertion << operator
std::ostream& operator<<(std::ostream& output, const Complex& z)
{
	// Format as '(a + bi)' or '(a - bi)'
	output << "(" << z.mRealPart << " ";
	if (z.mImaginaryPart >= 0.0)	
	 {
	 	output << "+ " << z.mImaginaryPart << "i)";
	 } 
	 else
	 {
	 	// z.mImaginaryPart < 0.0
	 	// Replace + with minus sign
	 	output << "- " << -z.mImaginaryPart << "i)";
	 }
	 return output;
}


#endif

