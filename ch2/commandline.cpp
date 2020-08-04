// Example from pg 72
#include <iostream>
#include <cstdlib>
 
using namespace std;

int main(int argc, char const *argv[])
{
	cout << "Flags found:";
	int flag;
	while ((flag = getopt(argc, argv, "abcdefg")) != EOF){
		char flagc = flag;
		cout << flagc  << " ";
	}
	cout << endl;
	return EXIT_SUCCESS;
}