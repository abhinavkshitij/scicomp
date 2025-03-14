// Example from pg. 62
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char hello1[] = {'H','I'};
	char hello2[] = "Hi";
	char name[15] = "Isaac Newton";

	name[12] = '\'';
	name[13] = 's';
	name[14] = '\0';

	cout << name << endl;
 	return 0;
}