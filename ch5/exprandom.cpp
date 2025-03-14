#include "exprandom.h"
/* static will make exp_random work only 
 * one translation unit, i.e. this file
 * change static to extern (or remove static) here 
 * and in header file to make this function 
 * avaiable in expdev.cpp
 */
static double exp_random(double mu){
	return -mu*log(random());
}
