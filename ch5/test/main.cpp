#include <iostream>
#include "myHeader.h"

int main(int argc, char const *argv[])
{
	abc<int> a(4);
	std::cout <<  a.show() << std::endl;
	return 0;
}