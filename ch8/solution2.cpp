// Example from pg. 212
#include "Mesh.h"

#include <iostream>
#include <fstream>
#include <cstddef>
using namespace std;


int main(int argc, char const *argv[]){
	
	// Read mesh
	Mesh m;
	ifstream read_file("mesh.in");
	read_file >> m;

	Number angle_threshold;
	read_file >> angle_threshold;
	Boolean anglesOK = m.checkElementsAngles(angle_threshold);

	return anglesOK ? EXIT_SUCCESS : EXIT_FAILURE;
		
}


