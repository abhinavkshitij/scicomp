// Example from pg 81.
/* Compile with gcc - char is 4 bytes long
 * Compile with g++ - char is 1 byte long
 */
#include "stdio.h"
int main(int argc, char const *argv[])
{
	printf("Bytes used in C char type = %lu\n", sizeof('x'));
	return 0;
}