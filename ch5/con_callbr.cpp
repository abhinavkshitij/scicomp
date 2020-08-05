// Example from pg. 138
extern void f(int& num); // Non-const call by reference

void f(int& num){}

int main(int argc, char const *argv[])
{
/* error: cannot bind non-const lvalue reference 
 *		  of type 'int' to an rvalue of type 'int'	
 */	
	f(3); 

/* error: cannot bind non-const lvalue reference 
 *		   of type 'int' to an rvalue of type 'int'
 */	
	float num = 3.0;
	// Note: float was converted to int to initialize formal arg	
	f(num);

	return 0;
}

