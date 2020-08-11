// Example from pg. 176

class A;

class B
{
public:
	double g() const;
	double g();
	double g(int);
	void h();	
};

class C
{
private:
	friend void B::h(); 		// Member of B::void h()	
public:
	friend int f(double);		// global function: int f(double)
	friend double B::g() const;	// Member of B: double g() const
								// NOTE: only one of B's g members is a friend
	friend class D;				// All members of D
	friend A;					// All members of A; A already declared	
};

// int main(int argc, char const *argv[])
// {
// 	/* code */
// 	return 0;
// }