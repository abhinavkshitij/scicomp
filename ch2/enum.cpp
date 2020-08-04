// Example from pg. 26
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	// 1. Relic from C
	enum Color {red, orange, green};
	Color light = green;
	cout << "Signal = " << light << endl;

	// 2. using typedef enum [C++ equivalent]
	typedef enum Spectrum {
		Red = 1,
		Orange = 2,
		Yellow = 3,
		Green = 4,
		Blue = 5,
		Indigo = 6,
		Violet = 7
	} Spectrum;

	Spectrum frequency = Indigo;
	cout << "Frequency = " << frequency << endl;
	return 0;
}