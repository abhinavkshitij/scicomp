// Driver for Coulomb's law
#include <iostream>
#include "coulombsLaw.h"
using namespace std;

int main(int argc, char const *argv[])
{
	const float q_e = 1.6e-19; 
	const float& q_p = q_e; // electron and proton have equal charge
	const float r_H = 5.5e-11;
	cout << "Force in H atom = " << coulombLaw(q_e,q_p,r_H) 
		 << " N" << endl;
	return 0;
}
