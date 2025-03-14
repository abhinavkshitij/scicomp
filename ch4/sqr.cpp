#include <iostream>
#include <complex>
#include "utils.h"

int main(int argc, char const *argv[])
{
int i = 1;
float f = 3.1;
double d = 4.4;
std::complex<double> c(3,4);

// 
std::cout << sqr(i) << std::endl;
std::cout << sqr(f) << std::endl;
std::cout << sqr(d) << std::endl;
std::cout << sqr(c) << std::endl;

return 0;
}