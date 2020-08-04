#include <iostream>
extern int var; 
int main(void) { 
	// int var = 10; 
	int var = 10;
	if (var == 10){
		int var = 20; // This var exists only in the IF-block
	}
	std::cout << var << std::endl;
	return 0; 
} 

