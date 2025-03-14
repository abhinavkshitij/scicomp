/* Example from pg 65.
 * Coulomb's law definition
 */
#include "coulombsLaw.h"

double coulombLaw(double q1, double q2, double r){
	const double k = 8.9875e9;
	return k * q1 * q2 / (sqr(r));
}
