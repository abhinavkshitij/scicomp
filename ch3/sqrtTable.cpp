// Example from pg 85
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	float x;
	ifstream read_num("num.in");
	cout << "Reading num from num.in" << endl;
	ofstream write_sqrt("sqrtTable.out");
	while(read_num >> x){
		write_sqrt << setw(15) << x << setw(15) << sqrt(x) << endl;
	}
	cout << "Created table in sqrtTable.out" << endl;
	return 0;
}