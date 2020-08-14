// Example from pg. 190
// static objects with local scope.
#include <iostream>

float f(float x){return x;} // Expensive computation

float remembers(float x){
	static int first_time = 1;
	static float previous_x;
	static float previous_result;

	if (first_time || x != previous_x){
		first_time = 0;
		previous_x = x;
		previous_result = f(x);
		std::cout << "value changed, calling f(x) " << f(x) << std::endl;
	}
	return previous_result;
};


int main(int argc, char const *argv[])
{
	std::cout<< remembers(1) << std::endl;
	std::cout<< remembers(1) << std::endl;
	std::cout<< remembers(2) << std::endl;
	std::cout<< remembers(1) << std::endl;
	return 0;
}